#include "Problem3b.h"

using namespace std;

int main(){
  omniCell<string> str1("abcd");
  omniCell<string> str2("ef");
  omniCell<string> str3("ghijklm");
  omniList<string> productstr;
  string strprod;
  string argument = "nonsense";

  omniCell<int> Int1(4);
  omniCell<int> Int2(11);
  omniList<int> productint;
  int arguint = 3;
  int intprod;
  
  productint.write(Int1);
  productint.write(Int2);
  intprod = productint.prod();
  
  productstr.write(str1);
  productstr.write(str2);
  productstr.write(str3);
  strprod = productstr.prod(argument);
  cout<<"integet product is: "<<intprod<<'\n';
  cout<<"string product is: "<<strprod<<'\n';
  return 0;
}
