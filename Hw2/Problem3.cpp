#include <iostream>
#include <cmath>
using namespace std;

int Sum(int *nums, int len){
  int sum,tempsum;
  int i,j,k;
  for(i=0;i<len;i++){
    //assign the temporary sum value
    tempsum = nums[i];
    if(tempsum==330){
      return 330;
    }
    //if temp>330 no need to add any more
    else if(tempsum>330){
      if((tempsum-330)<abs(sum-330)){
	sum = tempsum;
	tempsum = 0;
      }
    }
    else{   //when 1st num <330, add 2nd isnt useless
      if(abs(tempsum-330)<abs(sum-330)){
	sum = tempsum;
      }
      //go into the next loop to increment
      for(j=i+1;j<len;j++){
	//assign the temporary sum value
	tempsum = nums[i]+nums[j];
	if(tempsum==330){
	  return 330;
	}
	else if(tempsum>330){
	  if((tempsum-330)<abs(sum-330)){
	    sum = tempsum;
	    tempsum = 0;
	  }
	}
	else{
	  if(abs(tempsum-330)<abs(sum-330)){
	    sum = tempsum;
	  }
	    //go into the next loop to increment
	    for(k=j+1;k<len;k++){	//assign the temporary sum value
	      tempsum = nums[i]+nums[j]+nums[k];
	      if(tempsum==330){
		return 330;
	      }
	      else if(tempsum>330){
		if((tempsum-330)<abs(sum-330)){
		  sum = tempsum;
		  tempsum = 0;
		}
	      }
	      else{
		if(abs(tempsum-330)<abs(sum-330)){
		  sum = tempsum;
		}
	      }
	    }//end of k loop
	}//1st+2nd <330 enter k loop
      }//end j loop
    }//when 1st <330,enter j loop
  }//start of i loop
  return sum;
}


int main(){
  int we[10]={1,2,200,4,5,6,7,100,10,30};
  int er = Sum(we,10);
  cout << "sum is : "<<er<<'\n';
}
