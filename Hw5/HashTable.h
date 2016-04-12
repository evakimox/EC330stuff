#ifndef HASHTABLE
#define HASHTABLE

#include <iostream>
#include <string>
#include <set>
#include <fstream>

using namespace std;
 
class HashTable{
 public:
  HashTable(const char* filename);
  void SpellCheck(string inputword);
  set<string> dictionary;
  bool findstring(string inputword);
  bool findbyreplace(string inputword);
  bool findbyswap(string inputword);
  bool findbyinsert(string inputword);
  bool findbydelete(string inputword);
};

HashTable::HashTable(const char* filename){
  ifstream dict(filename);
  string word;
  int num = 1;
  set<string> dictionary;
  set<string>::iterator it;
  std::pair<std::set<string>::iterator,bool> ret;
  if (ret.second==false) {it=ret.first;}

  if(dict.is_open()){
    while(getline(dict,word)){
      this->dictionary.insert(word);
    }
    dict.close();
  }
  else{
    cout<<"unable to open file"<<endl;
  }
}

bool HashTable::findstring(string inputword){
  set<string>::iterator it;
  it=dictionary.find(inputword);

  if(it!=dictionary.end()){
    return 1;
  }
  return 0;
}

bool HashTable::findbyreplace(string inputword){
  bool found = 0;
  // cout<<"Check mighty wrong letter. . .\n";
  for(int j=0;j<inputword.length();j++){
    string copy = inputword;
    char a = 'a';
    for(int k=0;k<26;k++){
      copy[j] = a+k;
      if(findstring(copy)){
	cout<<copy<<endl;
	found = 1;
      }
    }
  }
  return found;
}

bool HashTable::findbyswap(string inputword){
  // cout<<"Check swapping misspelling. . . \n";
  bool found = 0;
  for(int j=0;j<inputword.length()-1;j++){
    string copy = inputword;
    copy[j] = inputword[j+1];
    copy[j+1] = inputword[j];
    if(findstring(copy)){
      cout<<copy<<endl;
      found = 1;
    }
  }
  return found;
}

bool HashTable::findbyinsert(string inputword){
  //  cout<<"Check lost letter. . . \n";
  bool found = 0;
  for(int j=0;j<inputword.length()+1;j++){
    char a = 'a';
    for(int k=0;k<26;k++){
      string copy = inputword;
      copy.insert(copy.begin()+j,a+k);
      if(findstring(copy)){
	cout<<copy<<endl;
	found = 1;
      }
    }
  }
  return found;
}

bool HashTable::findbydelete(string inputword){
  // cout<<"Check redundant letter. . . \n";
  bool found = 0;
  for(int j=0;j<inputword.length();j++){
    string copy = inputword;
    copy.erase(copy.begin()+j);
    if(findstring(copy)){
      cout<<copy<<endl;
      found = 1;
    }
  }
  return found;
}



void HashTable::SpellCheck(string inputword){
  cout<<"Spell checking. . . "<<endl;
  bool flagfound = 0;
  if(findstring(inputword))
  {
    flagfound = 1;
    cout<<inputword<<'\n';
    return;
  }
  else
  {
    int count = 0;
    count += findbyreplace(inputword);
    count += findbyswap(inputword);
    count += findbyinsert(inputword);
    count += findbydelete(inputword);
    flagfound = (count!=0);

    if(!flagfound)
    {
      cout<<"no matches found!\n";
    }
  }
}

#endif
