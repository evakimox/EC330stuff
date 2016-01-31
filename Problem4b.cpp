/*

Me: Jingning Zhang   U64723279

*/

#include <iostream>
#include <string>

using namespace std;

string Analyze(string str, int size){
  string result;
  if(size>=str.length()){
    return str;
  }
  else{
    //Need to iterate how many loops to finish counting this substring?
    int looptime=str.length()-size+1;
    //temporarily store the substring to be compared
    string me;
    //The current biggest counting number
    int biggest=0;
    //This substring count
    int thiscount;
    for(int i=0;i<looptime;i++){
      //Zero out self-count to make sure each loop does not affect eachother
      thiscount = 0;
      me=str.substr(i,size);
      //count appear rate
      for(int j=0;j<looptime;j++){
	if(me==str.substr(j,size)){
	  thiscount++;
	}
      }
      /*If my appear rate is more than the greatest 
      Then I am the most frequent substring
      my rate replace the biggest rate and I should be the result*/
      if(thiscount>biggest){
	biggest = thiscount;
	result = me;
      }
    }
  }
  return result; 
}

int main(int argc, char* argv[]){
  //string to store the output
  string printstring;
  //prepare the inputs to be used in the function
  string inputstring = argv[1];
  string substringlength = argv[2];
  int sublength = stoi(substringlength,nullptr,10);
  
  printstring = Analyze(inputstring,sublength);
  cout<<printstring<<'\n';
  return 0;
}
