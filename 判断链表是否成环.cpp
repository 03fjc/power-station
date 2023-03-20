#include<stdio.h>
#include<stdlib.h>
//判断是否成环，如果成环，返回环入口结点
typedef struct Node
{
	struct Node *next;	
}Node;
Node * isCylization(Node * node){
    if(node == NULL) return NULL;
    Node * fast = node;
    Node * slow = node;
    while(1){
        fast = fast->next?fast->next:NULL;
        if(!fast)return NULL;
        fast = fast->next?fast->next:NULL;
        if(!fast)return NULL;
        slow = slow->next?slow->next:NULL;
        if(!slow)return NULL;
        if(slow == fast) break;
    }
    Node * x = node;
    Node * y = slow;
    for(x == y;x=x->next;y=y->next);
    return x;
}
int main(){

    return 0;
}
