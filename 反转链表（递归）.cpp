#include <stdio.h>
#include <stdlib.h>
typedef struct nodef
{
 int data;
 struct nodef *next;
} *linklist;
linklist nailcreate(int n,linklist head)
{
 int i;
 linklist p,end,node;
 p=head;
 for(i=0;i<n;i++)
 {
  node=(linklist)malloc(sizeof(linklist));
  //node->next=NULL;
  p->next=node;
  scanf("%d",&node->data); 
  p=node;
 }
 node->next=NULL;
 return head;
}//尾插法创建链表 

linklist backward_2(linklist head)//递归法 
{
 if(head->next==NULL)
 {
   return head;//递归结束 
  } 
 linklist temp=backward_2(head->next);
 head->next->next=head;
 head->next=NULL; 
 return temp;
}
void output(linklist head)
{
 linklist p;
 p=head;
 while(p)
 {
 printf("%d ",p->data);
 p=p->next ;
 }
}//输出 
int main()
{
 linklist head;
 int n; 
 head=(linklist)malloc(sizeof(linklist));
 head->next=NULL;//链表初始化 
 printf("请输入链表长度：");
 scanf("%d",&n);//输入链表长度 
 printf("请输入链表："); 
 nailcreate(n,head);
 head=head->next;
 head=backward_2(head);//递归法 
 printf("反转后的链表为：");
 output(head);
 return 0;
}

