#include "Problem3a.h"

using namespace std;

int main(){
  //question 1:
  cout<<"Question 1: \n";
  omniCell<int> num1(46);
  omniCell<int> num2(2);
  omniCell<int> num3(15);
  omniCell<int> sumnum;
  sumnum = num1+num2+num3;
  cout <<"Num1 is "<<num1.read()<<"\nNum2 is "<<num2.read()<<"\nNum3 is "<<num3.read();
  cout <<"\nnum sum is "<<sumnum.read()<<'\n';

  //question 2:
  cout<<"\nQuestion 2: \n";
  omniCell<string> str1("abra");
  omniCell<string> str2("cadabra");
  omniCell<string> str3;
  str3 = str1+str2;
  cout<<"str1 is: "<< str1.read()<<"\nstr2 is: "<<str2.read()<<"\nstr sum is: "<<str3.read()<<'\n';

  //question3:
  cout<<"\nQuestion3\n";
  omniCell<string> str4("temp");
  omniCell<string> str5("lates");
  omniCell<string> str6("are");
  omniCell<string> str7("us");
  omniCell<string> str8("eful");
  omniCell<string> str9;
  str9 = str4+str5+str6+str7+str8;
  cout<<"str4: "<<str4.read()<<"\nstr5: "<<str5.read()<<"\nstr6: "<<str6.read()<<"\nstr7: "<<str7.read()<<"\nstr8: "<<str8.read()<<"\nsecond string sum: "<<str9.read()<<'\n';
  return 0;
}
