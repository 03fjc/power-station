#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>


typedef int Elemtype;
typedef struct Node
{
	Elemtype data;
	struct Node *next;
}Node;

typedef struct LinkQueue
{
	Node *head;
	Node *tail;
}LinkQueue;

LinkQueue *Q;

void InitQueue()//初始化链式队列
{
	
	Q=(LinkQueue*)malloc(sizeof(LinkQueue));
	Node *P=(Node*)malloc(sizeof(Node));//结点申请空间
	P->data=0;
	P->next=NULL;
	if(Q->head==NULL)//首个元素为空时，队首和队尾都指向P
	{
		Q->head=P;
		Q->tail=P;
		return;
	}
	Q->tail->next=P;
	Q->tail=P;
	printf("初始化成功\n");
}

void IsEmpty()//判断队列是否为空
{
	Q=(LinkQueue*)malloc(sizeof(LinkQueue));
	if(Q->head==Q->tail)//队首跟队尾重合，说明队列中没有元素
	{
		printf("队列为空\n");
	}
	else
		printf("队列不为空\n");
}

void Enter()//入队操作
{
	Q=(LinkQueue*)malloc(sizeof(LinkQueue));
	int Count,x;
	printf("请输入入队的元素个数:");
	scanf("%d", &Count);
	printf("请输入入队的元素:\n");
	for(int i=0;i<Count;i++)
	{
		Node *P=(Node*)malloc(sizeof(Node));
		Q->tail=(Node*)malloc(sizeof(Node));
		scanf("%d", &x);
		P->data=x;
		P->next=NULL;
		Q->tail->next=P;
		Q->tail=P;
	}
	printf("入队成功\n");
}

void Out()//出队操作
{
	Q=(LinkQueue*)malloc(sizeof(LinkQueue));
	Q->head=(Node*)malloc(sizeof(Node));
	Q->tail=(Node*)malloc(sizeof(Node));
	int Count;
	if(Q=NULL)
	{
		printf("队列为空");
	}
	printf("请输入出队的元素个数:");
	scanf("%d", &Count);
	for(int i=0;i<Count;i++)
	{
		Node *P=(Node *)malloc(sizeof(Node));
		P=Q->head->next;
		Q->head->next=P->next;
		if(NULL==Q->head->next)  
			Q->tail=Q->head;
		free(P);
	}
	printf("出队成功\n");
}

void GetHeadQueue()//获得队列首个元素
{
	Q=(LinkQueue*)malloc(sizeof(LinkQueue));
	Q->head=(Node*)malloc(sizeof(Node));
	if(Q->head==NULL)
	{
		printf("队列没有首个元素");
	}
	else
	{
		printf("队列的首个元素为:");
		int e=Q->head->data;
		printf("%d", e);
	}
}

void DestroyQueue()//销毁队列
{
	Q=(LinkQueue*)malloc(sizeof(LinkQueue));
	Q->head=(Node*)malloc(sizeof(Node));
	Q->head->next=NULL;
	Node *p, *q;
	Q->tail=Q->head;
	p=Q->head->next; 
	while(p!=NULL) 
	{
		q=p;
		p=p->next;
		free(q);
	}
	free(p);
	printf("销毁成功\n");
}

void GetCount()//获得队列长度
{
	int length;
	Q=(LinkQueue*)malloc(sizeof(LinkQueue));
	Node *P=(Node *)malloc(sizeof(Node));
	Q->head=(Node*)malloc(sizeof(Node));
	P=Q->head;
	for (length=0;P!=Q->tail;length++)//遍历队列结点个数
		P=P->next; 
	printf("队列长度为:%d", length);
}

void show()//遍历输出队列中的元素
{
	Q=(LinkQueue*)malloc(sizeof(LinkQueue));
	Q->head=(Node*)malloc(sizeof(Node));
	Q->head->next=NULL;
	if(Q->head==NULL)
	{
		printf("队列中没有元素");
	}
	Node* P; 
	P=Q->head->next; 
	int i=1;
	while(P!=NULL)
	{
		P=(Node*)malloc(sizeof(Node));
		printf("%d", P->data);
		P=P->next;
		free(P);
	}
	printf("\n");
}
int main()
{
	while(1)
	{
		printf("\t|--------链式队列操作如下------|\n");
		printf("\n");
		printf("\t|--------初始化队列请按1---------|\n");
		printf("\n");
		printf("\t|--------判断队列是否为空请按2---------|\n");
		printf("\n");
		printf("\t|--------入队操作请按3---------|\n");
		printf("\n");
		printf("\t|--------出队操作请按4---------|\n");
		printf("\n");
		printf("\t|--------获得队列首个元素请按5---------|\n");
		printf("\n");
		printf("\t|--------销毁队列请按6-----|\n");
		printf("\n");
		printf("\t|--------获得队列结点个数请按7|\n");
		printf("\n");
		printf("\t|--------遍历输出队列元素请按8|\n");
		printf("\n");
		printf("\t|**************************|\n");
	
	
		char ch=getch();
		switch(ch)
		{
			case '1':
				InitQueue();//初始化队列
				break;
			case '2':
				IsEmpty();//判断队列是否为空
				break;
			case '3':
				Enter();//入队操纵
				break;
			case '4':
				Out();//出队操作
				break;
			case '5':
				GetHeadQueue();//获得队列首个元素
				break;
			case '6':
				DestroyQueue();//销毁队列
				break;
			case '7':
				GetCount();//获得队列长度
				break;
			case '8':
				show();//遍历输出队列元素
				break;							
		}
	}
	return 0;
}