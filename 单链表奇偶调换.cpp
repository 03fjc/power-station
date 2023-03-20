#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct student{
 char name[20];
 float score;
 int node;
 struct student *next;
}*head,*p1,*p2;
 
//输出链表
void PrintLink(struct student *head){
 struct student *p;
 int n=0;
 p=head->next;
 while(p!=NULL){
  printf("第%d个节点：节点：%d\t 姓名：%s\t 成绩：%.2f\t\n",++n,p->node,p->name,p->score);
  p=p->next;
 }
}
 
//交换奇偶节点，同时对奇偶节点进行重排列；
//循环结束后，将最后指向的偶节点的next置为NULL，
//再将最后指向的奇节点的next指向一开始存到p中的第二个节点，完成奇偶交换。
void Exchange(struct student *head){
 struct student *p1,*p2,*p;    //p1为第一个节点，p和p2为第二个节点
 p1=head->next;
 p=p2=p1->next;
 
 while(p1->next!=NULL&&p1->next->next!=NULL){
  p1->next=p1->next->next;
  p1=p1->next;
 
  if(p2->next!=NULL&&p2->next->next!=NULL){
   p2->next=p2->next->next;
   p2=p2->next;
  }
 }
 p2->next=NULL;
 p1->next=p;
 
}
int main(){
 int n=0;
 //建立一个带头节点的链表
 head=(struct student *)malloc(sizeof(struct student));
 do{
  p1=(struct student *)malloc(sizeof(struct student));
  if(++n==1){
   head->next=p1;
  }else
   p2->next=p1;
  printf("Please input the %dth student's name:",n);
  gets(p1->name);
  if(strcmp(p1->name,"0")==0){
   p2->next=NULL;
   free(p1);
   break;
  }
  printf("Please input the %dth student's score:",n);
  scanf("%f",&p1->score);getchar();
  p1->node=n;
  p1->next=NULL;
  p2=p1;
 }while(1);
 printf("=================================RESULT=================================\n");
 PrintLink(head);
 Exchange(head);
 
 printf("\n交换后\n");
 PrintLink(head);
 
}
