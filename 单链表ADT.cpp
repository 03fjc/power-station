#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
 
typedef struct Node
{
 int data;
 struct Node* next;
}Node,*LinkList;
 
 
//用尾插法建立单链表
LinkList CreateFormTail(LinkList L)
{
 L=(Node*)malloc(sizeof(Node));
 L->next=NULL;
 
 Node *r,*s;
 int x;
 scanf("%d",&x);
 r=L;
 while(x!=9999)
 {
   s=(Node*)malloc(sizeof(Node));
   s->data=x;
   r->next=s;
   r=s;
   scanf("%d",&x);
 }
 r->next=NULL;
 return L;
 }
 
 
//在单链表中查找值为e的元素 
int Locate(LinkList L,int e) 
{
 Node *p;
 p=L->next;
 int i=1;
 while(p!=NULL&&p->data!=e)
 {
  p=p->next;
  i++;
 }
 if(p==NULL)
     return 0;
 else
     return i;
}
 
//在链表中第i个位置插入值为e的元素
bool InsList(LinkList L,int i,int e)
{
 Node *pre,*s;
 int k=0;
 if(i<=0) return false;
 pre=L;
 while(pre!=NULL&&k<i-1)
 {
  pre=pre->next;
  k=k+1;
 }
 if(pre==NULL)
     return false;
 s=(Node*)malloc(sizeof(Node));
 s->data=e;
 s->next=pre->next;
 pre->next=s;
 return true;
 }
 
//删除第i个元素
bool DelList(LinkList L,int i,int e)
{
 Node *pre,*r;
 int k=0;
 pre=L;
 while(pre->next!=NULL&&k<i-1)
 {
  pre=pre->next;
  k=k+1;
 }
 if(pre->next==NULL)
     return false;
 r=pre->next;
 pre->next=r->next;
 e=r->data;
 free(r);
 return true;
}
 
//修改链表中第i个元素的数值
int ChangeList(LinkList L,int i,int e)
{
 Node *pr;
 pr=L;
 while(pr!=NULL)
 if(pr->data==i)
 {
  pr->data=e;
  break;
 }
 else
 {
  pr=pr->next;
 }
 if(pr==NULL) return false;
 return true;
 } 
 
//求单链表的长度
int ListLength(LinkList L)
{
 Node *p;
 p=L->next;
 int j=0;
 while(p!=NULL)
 {
  p=p->next;
  j++;
  }
  return j;
 } 
 
//打印输出单链表
void PrintList(LinkList L)
{
 L=L->next;
 while(L)
 {
  printf("%3d",L->data);
  L=L->next;
  }
  printf("\n");
 } 
 
int main()
{
 LinkList list;
 int i,j,k,e;
 printf("请输入链表中的数值："); 
 list=CreateFormTail(list);
 printf("当前链表中的数据为：");
 PrintList(list);
 printf("表长为：%d\n",ListLength(list));
 
 printf("请输入需要查找元素e的值：") ;
 scanf("%d",&e);
 printf("%d所在的位置是：%d\n",e,Locate(list,e));
 
 printf("请输入需要插入元素的位置i和元素的值e:");
 scanf("%d%d",&i,&e);
 InsList(list,i,e);
 printf("插入元素后链表中的数据为：");
 PrintList(list);
 printf("表长为：%d\n",ListLength(list));
 
 printf("请输入需要删除元素的位置i的值：");
 scanf("%d",&i);
 DelList(list,i,e);
 printf("删除元素后链表中的数据为：");
 PrintList(list);
 printf("表长为：%d\n",ListLength(list));
 
 printf("请输入需要修改位置i的值和更改后的值e:");
 scanf("%d%d",&i,&e);
 ChangeList(list,i,e);
 printf("修改元素后链表中的数据为：");
 PrintList(list);
 printf("表长为：%d\n",ListLength(list));
 
 } 
