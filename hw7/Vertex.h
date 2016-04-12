#ifndef Vertex_hpp
#define Vertex_hpp

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Vertex{
 public:
  Vertex(string inputname);
  string name;
  vector<Vertex*> neighbourlist;
  void addneighbour(Vertex* neighbourVertex);
  int color;
  int distance;
};

Vertex::Vertex(string inputname){
  name = inputname;
  cout<<"Vetex "<<name<<" constructed"<<endl;
}

void Vertex::addneighbour(Vertex* neighbourVertex){
  vector<Vertex*>::iterator it;
  it = find(neighbourlist.begin(),neighbourlist.end(),neighbourVertex);
  if(it == neighbourlist.end()){
    neighbourlist.push_back(neighbourVertex);
  }
  else{
    cout<<"this connection already added"<<endl;
  }
}


#endif

    
