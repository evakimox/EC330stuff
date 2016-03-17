#ifndef LSorter_hpp
#define LSorter_hpp

#include <stdio.h>
#include <iostream>
#include "LNode.h"

using namespace std;

void merge(int arr[], int l, int m, int r){
  
  int lengthleft = m - l + 1;      //length of the left array
  int lengthright =  r - m;      //length of the right array
  
  //initiate the left and right array
  int L[lengthleft], R[lengthright];
  
  //copy values into the spiltted arrays
  for(int i = 0; i < lengthleft; i++)
    L[i] = arr[l + i];
  for(int j = 0; j < lengthright; j++)
    R[j] = arr[m + 1+ j];
  
  //Merge the temp array back into arr[]
  //Using While loop for more clear enter checking logic
  int i = 0;    //point to left array element
  int j = 0;    //point to right array element
  int k = l;    //point to the arr[] position
  while (i < lengthleft && j < lengthright){
    /* since this function is called recursively, the begining is merging only 2 int numbers the element order inside each merged subarray is promised to be sorted each time when I enter this while loop*/
    if (L[i] <= R[j]){    //find the smaller one to put to the arr[]
      arr[k] = L[i];
      i++;    //desert the value that has already been put back to the arr[]
    }
    else{
      arr[k] = R[j];
      j++;    //same reason 4 line above
    }
    k++;
  }
 
  /* if all the numbers inside L is smalengthlefter than those inside R (vice versa)
     and when there is more smalengthleft numbers in only one array
 do these while loops to colengthleftect the bigger numbers, actually only one of them get a chance to execute */
  while (i < lengthleft){
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < lengthright){
    arr[k] = R[j];
    j++;
    k++;
  }
}
 
//actually spilt the array and then merge them back
//merge order is controlled by the merge() method
void mergesort(int arr[], int l, int r){
  //while the # of elements > 1, I wilengthleft need to keep spiltting
  if (l < r){
    int m = l+(r-l)/2;        //spilt the array from the center
    mergesort(arr, l, m);        //spilt the left array
    mergesort(arr, m+1, r);        //spilt the right array
    //
    merge(arr, l, m, r);
  }
}


class LSorter {
public:
    LNode* sortList(LNode* head);
};


LNode* LSorter::sortList(LNode* head){
  int length=0;
  int finish=0;
  LNode* currnode = head;
  while(1){
    if(currnode == NULL){
      break;
    }
    length++;
    currnode = currnode->next;
  }
  
  int arr[length];
  currnode = head;
  for(int i=0;i<length;i++){
    arr[i] = currnode->val;
    currnode = currnode->next;
  }
  
  mergesort(arr,0,length-1);
  
  currnode = head;
  for(int i=0;i<length;i++){
    currnode->val = arr[i];
    currnode = currnode->next;
  }
  cout<<'\n';
  
  return head;
}

#endif /* LSorter_hpp */






