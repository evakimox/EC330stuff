#ifndef OMNILIST
#define OMNILIST

#include "Problem3a.h"
#include <vector>

using namespace std;

template <class Type>
class omniList{
 private:
  vector<omniCell<Type> > mylist;
 public:
  omniList();
  void write(omniCell<Type> addelement);
  void print();
  Type sum();
  Type prod();
  string prod(string n);
};
//constructor
template <class Type>
omniList<Type>::omniList(){
  mylist = vector<omniCell<Type> >();
}

//write
template <class Type>
void omniList<Type>::write(omniCell<Type> addelement){
  mylist.push_back(addelement);
}

template <class Type>
void omniList<Type>::print(){
  for(int i=0;i<mylist.size();i++){
    omniCell<Type> needCell = mylist[i];
    cout<<needCell.read()<<'\n';
  }
}

template<class Type>
Type omniList<Type>::sum(){
  Type result;
  result = Type();
  for(int i=0;i<mylist.size();i++){
    result = result+mylist[i].read();
  }
  return result;
}


//Problem3c
template<>
int omniList<int>::prod(){
  int result=1;
  for(int i=0;i<mylist.size();i++){
    result = result*mylist[i].read();
  }
  return result;
}

template<>
string omniList<string>::prod(string n){
  string result = " ";
  for(int i=0;i<mylist.size()-1;i++){
    //weaving
    int j=0;  //j point to the letter to be add on
    while((j<mylist[i].read().length())&&j<mylist[i+1].read().length()){
      result += mylist[i].read()[j];
      result += mylist[i+1].read()[j];
      j++;
    }
    while((j<=mylist[i].read().length())||j<=mylist[i+1].read().length()){
      if(j==mylist[i].read().length()){ //i th one is shorter  
	if(j==mylist[i+1].read().length()+1){//two string are same length
	  //do nothing then, it is done
	  break;
	}
	else{//deal with [i+1]th string
	  result += mylist[i+1].read().substr(j,mylist[i+1].read().length());
	  break;
	}
      }// end i th one shorter
      else{// i+1th one is shorter
	if(j==mylist[i+1].read().length()+1){//two string are same length
	  //do nothing then, it is done
	  break;
	}
	else{//deal with [i]th string
	  result += mylist[i+1].read().substr(j,mylist[i+1].read().length());
	  break;
	}
      }// end i+1 th one shorter
    }//end second while
  }//end for loop
  return result;
}//end prod
	


#endif


