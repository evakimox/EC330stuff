#include "Problem3b.h"

using namespace std;
int main(){
  omniCell<int> num1(12);
  omniCell<int> num2(22);
  omniList<int> MyIntList;
  MyIntList.write(num1);
  MyIntList.write(num2);
  cout<<"Integer list is: \n";
  MyIntList.print();
  cout<<"Integer sum is: ";
  int intsum;
  
  intsum = MyIntList.sum();
  cout<<intsum<<'\n';
 
 
  omniCell<string> str1("al");
  omniCell<string> str2("go");
  omniCell<string> str3("rith");
  omniCell<string> str4("ms");
  omniList<string> MyStrList;
  MyStrList.write(str1);
  MyStrList.write(str2);
  MyStrList.write(str3);
  MyStrList.write(str4);
  string strsum;
  cout<<"String list is: \n";
  MyStrList.print();
  cout<<"String sum is: ";
  strsum = MyStrList.sum();
  cout<<strsum;

  
  cout<<'\n';
  return 0;
}  
