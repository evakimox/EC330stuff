#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

/* 
the Trie is found online and the website is: 
http://www.sourcetricks.com/2011/06/c-tries.html#.VvxtNhIrI00
Contributed by SourceTricks
Cited on: 2016.3.26
*/

class Node {
public:
    Node() { mContent = ' '; mMarker = false; }
    ~Node() {}
    char content() { return mContent; }
    void setContent(char c) { mContent = c; }
    bool wordMarker() { return mMarker; }
    void setWordMarker() { mMarker = true; }
    Node* findChild(char c);
    void appendChild(Node* child) { mChildren.push_back(child); }
    vector<Node*> children() { return mChildren; }

private:
    char mContent;
    bool mMarker;
    vector<Node*> mChildren;
};

class Trie {
public:
    Trie();
    ~Trie();
    void addWord(string s);
    bool searchWord(string s);
    void deleteWord(string s);
private:
    Node* root;
};

Node* Node::findChild(char c)
{
    for ( int i = 0; i < mChildren.size(); i++ )
    {
        Node* tmp = mChildren.at(i);
        if ( tmp->content() == c )
        {
            return tmp;
        }
    }

    return NULL;
}

Trie::Trie()
{
    root = new Node();
}

Trie::~Trie()
{
    // Free memory
}

void Trie::addWord(string s)
{
    Node* current = root;

    if ( s.length() == 0 )
    {
        current->setWordMarker(); // an empty word
        return;
    }

    for ( int i = 0; i < s.length(); i++ )
    {        
        Node* child = current->findChild(s[i]);
        if ( child != NULL )
        {
            current = child;
        }
        else
        {
            Node* tmp = new Node();
            tmp->setContent(s[i]);
            current->appendChild(tmp);
            current = tmp;
        }
        if ( i == s.length() - 1 )
            current->setWordMarker();
    }
}


bool Trie::searchWord(string s)
{
    Node* current = root;

    while ( current != NULL )
    {
        for ( int i = 0; i < s.length(); i++ )
        {
            Node* tmp = current->findChild(s[i]);
            if ( tmp == NULL )
                return false;
            current = tmp;
        }

        if ( current->wordMarker() )
            return true;
        else
            return false;
    }

    return false;
}
/* 
this trie implementation is found online:
http://www.sourcetricks.com/2011/06/c-tries.html#.VvxtNhIrI00
 */

bool LenGreater8(string word);
bool LenEq8(string word);
int countsubword(string word, Trie dictionary);
int substrpalin(string word);

void fourA(){
  ifstream bigData("smallData.txt");
  string word;
  char letter;
  int sum = 0;
  int count = 0;
  while(bigData>>letter){
    if(letter == 'U'){
      bigData>>word;
      if(word.length()>8){
	//length>8 check method
	sum+=LenGreater8(word);
      }
      else if(word.length()==8){
	//length = 8 check method
	sum+=LenEq8(word);
      }
      else{
	//not enough digits
      }
    }//end Start with letter U
  }//end searching the bigData
  cout<<"BUIDs: "<<sum<<endl;
  bigData.close();
}

void fourB(){
  int count = 0;
  ifstream bigData("smallData.txt");
  ifstream dict("smalldictionary.txt");
  string correctword;
  Trie dictionary;
  if(dict.is_open()){
    while(getline(dict,correctword)){
      dictionary.addWord(correctword);
    }
    dict.close();
  }
  string myword;
  //inside the string, insert char by char (only ascii between A and z)
  while(bigData>>myword){
    //go over every substring in the word
    count+=countsubword(myword, dictionary);
  }
  cout<<"Count word: "<<count<<endl;
}

void fourC(){
  ifstream bigData("BigData.txt");
  string word;
  int currentlen = 0;
  getline(bigData,word);
    //call functions
    currentlen = substrpalin(word);
  cout<<"Biggest Length palin: "<<currentlen<<endl;
}


int main(){
  fourA();
  //  fourB();
  fourC();
  return 0;
}


/* the support functions */
//fourA function
bool LenEq8(string word){
  bool isID;
  int sum = 0;
  for(int i=0;i<8;i++){//do things that check if all char inside is numerical
    char thisletter = word[i];
    int thisletternum = (int)thisletter-48;//turn it back from ascii
    if(thisletternum>9||thisletternum<0){
      //this is some character, not BUID
      return 0;
    }
    else{
      sum+=thisletternum;
      if(sum>28){
	isID = 1;
      }
    }	      
  }//end of for loop that check if inside this word
  return isID;
}

bool LenGreater8(string word){
  bool isID = 0;
  int sum = 0;
  if(word[8]=='0'||word[8]=='1'||word[8]=='2'||word[8]=='3'||
     word[8]=='4'||word[8]=='5'||word[8]=='6'||
     word[8]=='7'||word[8]=='8'||word[8]=='9'){ //this is definitly not BUID
    return 0;
  }//length >8 followed by number
  
  else{//length>8 followed by non-numerical character
    for(int i=0;i<8;i++){//do things that check if all char inside is numerical
      char thisletter = word[i];
      int thisletternum = (int)thisletter-48;
      if(thisletternum>9||thisletternum<0){
	//this is some character, not BUID
	return 0;
      }
      else{
	sum+=thisletternum;
	if(sum>28){
	  isID = 1;
	}
      }	      
    }//end of for loop that check if inside this word
  }//if length>8 followed by non-number
  return isID;
}//if length>8 all cases

//fourB function
int countsubword(string word, Trie dictionary){
  int count = 0;
  int length = word.length();
  string substring;
  for(int i=1;i<=length;i++){
    //i is the substring length
    for(int j=0;j<length-i+1;j++){
      //j+1 is the times that need to check substrings with length i
      //j is the starting index of the string
      substring = word.substr(j,i);
      if(substring[substring.length()-1]!='g'){//my last name zhang which end with g
	count+=dictionary.searchWord(substring);
      }
    }
  }
  return count;
}

//fourC function
int substrpalin(string word){
  int rightIndex = 0;
  int leftIndex = 0;
  string currentPalindrome;
  string longestPalindrome;
  for (int centerIndex = 1; centerIndex < word.length() - 1; centerIndex++){
    leftIndex = centerIndex - 1;
    rightIndex = centerIndex + 1;
    while (leftIndex >= 0 && rightIndex < word.length()) {
      if (word[leftIndex] != word[rightIndex]) {
	break;
      }
      else{
	currentPalindrome = word.substr(leftIndex, rightIndex-leftIndex + 1);
	longestPalindrome = currentPalindrome.length() > longestPalindrome.length() ? currentPalindrome : longestPalindrome;
	leftIndex--;
	rightIndex++;
      }
    }
  }
  return longestPalindrome.length();
}
