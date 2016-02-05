#include <iostream>
#include <cmath>
using namespace std;

int Sum(int *nums, int len){
  int sum,tempsum;
  int i,j,k;
  for(i=0;i<len;i++){
    tempsum = nums[i];

    if(abs(tempsum-330)<abs(sum-330)){
      sum = tempsum;
    }
	
    for(j=i+1;j<len;j++){
      tempsum = tempsum+nums[j];

      if(abs(tempsum-330)<abs(sum-330)){
	sum = tempsum;
      }
	
      for(k=j+1;k<len;k++){
	tempsum = tempsum+nums[k];
	
	if(abs(tempsum-330)<abs(sum-330)){
	  sum = tempsum;
	}

	tempsum = 0;
      }
    }
  }
  return sum;
}


int main(){
  int we[10]={1,2,330,4,5,6,7,100,9,0};
  int er = Sum(we,10);
  cout << "sum is : "<<er<<'\n';
}
