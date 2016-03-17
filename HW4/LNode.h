#ifndef LNode_hpp
#define LNode_hpp

#include <stdio.h>

class LNode {
public:
    int val;
    LNode* next;
    LNode(int x);
};


LNode::LNode(int x){
        val = x;
        next = NULL; //nullptr;
}

#endif /* LNode_hpp */
