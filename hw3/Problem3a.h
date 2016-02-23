#ifndef OMNICELL
#define OMNICELL

#include <stdio.h>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

template <class Type>
class omniCell{
 private:
  Type content;
 public:
  omniCell();
  omniCell(Type inputvalue);
  Type read();
  void write(Type writeinfo);
  omniCell& operator=(omniCell& otherCell);
  omniCell& operator+(omniCell& otherCell);
};

template <class Type>
omniCell<Type>::omniCell(){
  content = 0;
}

template <>
omniCell<string>::omniCell(){
    content = " ";
}

template<class Type>
omniCell<Type>::omniCell(Type inputvalue){
  content = inputvalue;
}

template<class Type>
Type omniCell<Type>::read(){
  return content;
}

template<class Type>
void omniCell<Type>::write(Type writeinfo){
  content = writeinfo;
}

template<class Type>
omniCell<Type>& omniCell<Type>::operator=(omniCell<Type>& otherCell){
  write(otherCell.read());
  return *this;
}
  
template<class Type>
omniCell<Type>& omniCell<Type>::operator+(omniCell& otherCell){
  omniCell *result =  new omniCell();
  result->write(this->read()+otherCell.read());
  return *result;
}  

#endif 

