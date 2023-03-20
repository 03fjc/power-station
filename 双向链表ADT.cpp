#include<stdio.h>
#include<stdlib.h>
 
#define TRUE 1
#define FALSE 0
 
typedef struct NODE
{
 int data;
 struct NODE* pre;//指向前驱结点
 struct NODE* next;//指向后继结点
}Node;
 
Node* Inint_List()//初始化链表
{
 Node* list = (Node*)malloc(sizeof(Node));//申请链表的空间
 list->next = NULL;
 list->pre = NULL;
 list->data = 0;
}
 
void PushByPos(Node* list, int pos,int data)
{
 if (pos<0 || pos>list->data)
 {
  pos = list->data;
 }
 
 Node* newnode = (Node*)malloc(sizeof(Node));
 newnode->data = data;
 Node* node = list;
 for (int i = 0; i < pos; i++)
 {
  node = node->next;
 }
   
 if (pos != list->data)
 {
  newnode->next = node->next;
  newnode->pre = node;
  node->next->pre = newnode;
  node->next = newnode;
 }
 
 else
 {
  newnode->next = node->next;
  newnode->pre = node;
  node->next = newnode;
 }
 list->data++;
}
 
void Push_Pop(Node* list, int data)
{
 
 Node* node = (Node*)malloc(sizeof(Node));
 node->data = data;
 
 if (list->data == 0)//链表为空
 {
  node->next = list->next;//=NULL不对
  list->next = node;
  node->pre = list;
 }
 
 else
 {
  node->pre = list;
  node->next = list->next;
 
  list->next->pre = node;//头插必须有
  list->next = node;
 }
 list->data++;
}
 
void Push_Back(Node* list, int data)
{
 Node* node = list;
 
 Node* newnode = (Node*)malloc(sizeof(Node));
 newnode->data = data;
 
 while (node->next)
 {
  node = node->next;
 }
 
  newnode->next = node->next;//找到的node为最后一个结点，需要在它后面插
  node->next = newnode;
  newnode->pre = node;
 
  list->data++;
}
 
int DeleteList(Node* list, int data)
{
 Node* node = list->next;
 int index = 1;
 while (node)
 {
  if (node->data == data && index != list->data)//删除操作
  {
   
   node->pre->next = node->next;
   node->next->pre = node->pre;
 
   free(node);
   list->data--;
   return TRUE;
  }
 
  else if (node->data == data && index == list->data)
  {
   node->pre->next = NULL;
   free(node);
   list->data--;
   return TRUE;
  }
 
  index++;
  node = node->next;
 }
 return FALSE;
}
 
int DeleteByPos(Node* list, int pos)//清空链表
{
 if (pos < 0 || pos > list->data)
 {
  return FALSE;
 }
 
 Node* node = list->next;
 
 for(int i=0;i<pos;i++)
 { 
  node = node->next;
 }
    
 if (pos != list->data)
 {
  node->next->pre = node->pre;
  node->pre->next = node->next;
 }
 
 else
 {
  node->pre->next = NULL;
 }
 
 free(node);
 list->data--;
 return TRUE;
}
 
void PrintList(Node* list)//打印链表
{
 Node* node = list->next;
 while (node != NULL)
 {
  printf("%d->", node->data);
  node = node->next;
 }
 printf("NULL\n");
}
 
int main()
{
 Node* list = Inint_List();
 
 Push_Pop(list, 1);
 Push_Pop(list, 2);
 Push_Pop(list, 3);
 Push_Pop(list, 4);
 
 Push_Back(list, 5);
 Push_Back(list, 6);
 
 DeleteList(list, 4);
 DeleteList(list, 1);
 
 PushByPos(list, 2, 3);
 PushByPos(list, 100, 8);
 DeleteList(list, 8);
 DeleteByPos(list, 0);
 
 PrintList(list);
 system("pause");
 return 0;
}
