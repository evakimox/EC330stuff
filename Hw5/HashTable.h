#ifndef HASHTABLE
#define HASHTABLE

#include <iostream>
#include <string>
#include <set>
#include <fstream>

class HashTable{
 public:
  HashTable(char* filename);
  SpellCheck(string inputword);
  set<string> dictionary;
};

HashTable::HashTable(char* filename){
  ifstream dict(filename);
  int num = 1;
  set<string> dictionary;
  if(dict.is_open()){
    while(getline(dict,word)){
      dictionary.insert(word);
    }
    dict.close();
  }
  else{
    cout<<"unable to open file"<<endl;
  }
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
#endif
