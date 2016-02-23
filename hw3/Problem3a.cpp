#include "Problem3a.h"
template <class Type>
omniCell<Type>::omniCell(){
  content = 0;
}

template<class Type>
omniCell<Type>::omniCell(Type inputvalue){
  content = inputvalue;
}

template<class Type>
Type omniCell<Type>::read(){
  return content;
}

