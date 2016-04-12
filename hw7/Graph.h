#ifndef Graph_hpp
#define Graph_hpp

#include "Vertex.h"
#include "Edge.h"
#include <set>

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
  set<string> output;
  Vertex* root;
  if(findelem(name)==NULL){
    cout<<"This vertex does not exist in this graph"<<endl;
  }
  else{
    root = findelem(name);
    //Use DFS to collect all the vertex names that satisfy the requirements
    //color all white
    for(int i=0;i<elemVertex.size();i++){
      elemVertex[i]->color = 0;
    }

    root->color = 1;
    
    for(int i=0;i<root->neighbourlist.size();i++){
      Vertex* N1 = root->neighbourlist[i];
      output.insert(N1->name);
      // cout<<"Under root: "<<N1->name<<" inserted dist = 1"<<endl;
      for(int i2=0;i2<N1->neighbourlist.size();i2++){
	Vertex* N2 = N1->neighbourlist[i2];
      	if(!(N2->color)){
	  output.insert(N2->name);
	  //  cout<<"Under Dist1: "<<N2->name<<" INSERTED dist = 2"<<endl;
	  for(int i3 = 0;i3<N2->neighbourlist.size();i3++){
	    Vertex* N3 = N2->neighbourlist[i3];
	    if(!(N3->color)){
	      output.insert(N3->name);
	      // cout<<"Under Dist2: "<<N3->name<<" INSERTED dist = 3"<<endl;
	    }
	  }//end of dist = 3
       	}// end of if dist2 is unvisited
      }// dist = 2 Vertices end there
    }//end searching through vertices
    
  }//end statement where the vertex exist in graph
  set<string>::iterator it;
  for(it = output.begin();it!=output.end();it++){
    cout<<*it<<endl;
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

