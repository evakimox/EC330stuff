
#include "Graph.h"
#include <fstream>
#include <ctype.h>

using namespace std;

int main(){
  ifstream flightinfo("flights.txt");
  string word;
  string previous_word;
  Graph g;
  while(flightinfo>>word){
    if(word.length()==3&&isalpha(word[0])&&isalpha(word[1])&&isalpha(word[2])){
      g.addelem(word);
    }
    else if(word=="\"\""){
      string name1;
      string name2;
      flightinfo>>name1;
      flightinfo>>name2;
      g.addedge(g.findelem(name1),g.findelem(name2));
    }
  }
  return 1;
}
