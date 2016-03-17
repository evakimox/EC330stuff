#ifndef LSorter_hpp
#define LSorter_hpp

#include <stdio.h>
#include <iostream>
#include "LNode.h"

using namespace std;

/* index find the list element*/
int index(LNode* head,int ind){
  LNode* currnode = head;
  int result;
  for(int i=0;i<=ind;i++){
    result = currnode->val;
    currnode = currnode->next;
  }
  return result;
}


class LSorter {
public:
    LNode* sortList(LNode* head);
};

LNode* LSorter::sortList(LNode* mainlist){
  /* sublist size increment by *2 to practice merge sort*/
  int sublistsize = 1;
  /* count how many times I merged through the loop, because merge sorts starts from having a lot of sublists to merge, every time I merge I have one half less loops to go through the last time of the merge will do the loop only once so I will use this as the out-loop-checker*/
  int mergecount;
  /* Left and right size information */
  int leftsize;
  int rightsize;
  /* the last element of the sorted list */
  LNode* tail;
  /* these are not actual lists, they are just pointing to the original list where I want the left and right lists to start from */
  LNode* leftlist;
  LNode* rightlist;
  /* point to the next smallest node of the subarray*/
  LNode* next;
  
  /* merge sort */
  do{
    mergecount = 0;
    leftlist = mainlist;    /* always start from the first node */
    tail = mainlist = 0;    /* always start from the first node */

    while(leftlist!=NULL){
      mergecount++;
      rightlist = leftlist;
      leftsize = 0;
      rightsize = sublistsize;

      /* define which is leftlist and which is rightlist */
      while((rightlist!=NULL)&&(leftsize<sublistsize)){
	leftsize++;    /* increment the left size information until it is =subsize*/
	rightlist = rightlist->next;    /* push the rightlist pointer until it points to the correct starting point for the right pointer*/
      }
    
      /* this loop is putting the correct array in the next pointer and append it to the sorted list tail */
      while(leftsize>0 || (rightsize>0 && rightlist!=NULL)){
	if(leftsize==0){    /* if leftlist element run out */
	  next = rightlist;
	  rightlist = rightlist->next;
	  rightsize--;
	}
	else if(rightsize==0||rightlist==NULL){    /* if rightlist run out elements */
	  next = leftlist;
	  leftlist = leftlist->next;
	  leftsize--;
	}
	else if(index(leftlist,0)<index(rightlist,0)){    /* if leftlist first element < rightlist first element*/
	  next = leftlist;
	  leftlist = leftlist->next;
	  leftsize--;
	}
	else{    /* same just for rightlist */
	  next = rightlist;
	  rightlist = rightlist->next;
	  rightsize--;
	}
	if(tail!=NULL){    /* make sure that tail node is valid*/
	  tail->next = next;
	}

       	else{    /* if tail is not valid it means I am at the end of list*/
      	  mainlist = next;
	}
	
	/* the previous sublists are combined so I need to update the tail pointer */
	tail = next;
      }
      /* rightlist after the loop is pointing at the leftlist for next loop cycle*/
      leftlist = rightlist;
    }
    tail->next = NULL;
    sublistsize =sublistsize*2;
  }while(mergecount>1);
   
  return mainlist;
}

#endif /* LSorter_hpp */






