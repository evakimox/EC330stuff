#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;

int main(){
  string word;
  char* dictname = "dictionary.txt";
  ifstream dict(dictname);
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

  set<string>::iterator it;
  string app = "juice";
  it = dictionary.find(app);
  cout<<*it<<endl;
  return 0;
}
