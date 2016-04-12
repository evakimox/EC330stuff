#ifndef Graph_hpp
#define Graph_hpp

#include "Vertex.h"
#include "Edge.h"

using namespace std;

class Graph{
 public:
  Graph(void);
  vector<Vertex*> elemVertex;
  vector<Edge*> edgelist;
  void addelem(string name);
  Vertex* findelem(string name);
  void addedge(Vertex* V1, Vertex* V2);
  void distThreeNeighbour(string name);
};

Graph::Graph(){
  //do nothing
}

void Graph::distThreeNeighbour(string name){
  if(findelem(name)==NULL){
    cout<<"This vertex does not exist in this graph"<<endl;
  }
  else{
    //Use BFS to collect all the vertex names that satisfy the requirements
    //color all white
    //enqueue the refered vertex
    //
  }
}

void Graph::addedge(Vertex* V1,Vertex* V2){
  Edge* E;
  E = new Edge(V1,V2);
  edgelist.push_back(E);
}

void Graph::addelem(string name){
  if(this->findelem(name)!=NULL){
    cout<<"This vertex already exist in graph"<<endl;
  }
  else{
    Vertex* V;
    V = new Vertex(name);
    elemVertex.push_back(V);
  }
}  

Vertex* Graph::findelem(string name){
  //go through elemVertex vector to find one with name match
  for(int i=0;i<elemVertex.size();i++){
    if(name==elemVertex[i]->name){
      return elemVertex[i];
    }
  }
  return NULL;
}


#endif

