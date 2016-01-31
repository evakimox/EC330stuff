/*

Me: Jingning Zhang    U64723279

*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


long BinarySum(string fileName){
  //thing to return
  long sum=0;
  //temporaryly store the info read from file
  string line;
  fstream myfile (fileName);
  if (myfile.is_open()){
    //Since numbers are seperated by carriage returns, read numbers by line
    while (getline (myfile,line))
    {
      int i_bin = stoi (line,nullptr,2);
      //add the numbers one by one
      sum = sum+i_bin;
    }
    myfile.close();
  }
  return sum;
}


int main(int argc, char* argv[]){
  /* The argv is actually a list of arguments, the first one is program name, second one starts to be the input argument to be used by the function */
  string fname = argv[1];
  long bsum = BinarySum(fname);
  //Default is in decimal No need to change anything
  cout <<"sum is: "<< bsum << '\n';
  return 0;
}
