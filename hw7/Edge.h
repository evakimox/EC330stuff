#ifndef Edge_hpp
#define Edge_hpp

#include "Vertex.h"


using namespace std;

class Edge{
 public:
  Edge(Vertex* inVertex1, Vertex* inVertex2);
  Vertex* V1;
  Vertex* V2;
};

Edge::Edge(Vertex* inVertex1, Vertex* inVertex2){
  V1 = inVertex1;
  V2 = inVertex2;
  V1->addneighbour(V2);
  V2->addneighbour(V1);
  cout<<"edge containing "<<V1->name<<" and "<<V2->name<<" constructed"<<endl;
}

#endif
