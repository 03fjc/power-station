#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

typedef int Elemtype;
typedef struct Node
{
	Elemtype data;
	struct Node *next;
}Node;

typedef struct LinkStack
{
	Node *top;
	int count;
}LinkStack;

LinkStack *S;
Node *P,*top;






void InitStack()//初始化链栈
{
	S=(LinkStack*)malloc(sizeof(LinkStack));
	P=(Node*)malloc(sizeof(Node));
	if(S==NULL)
	{
		return;
	}
	S->top=NULL;
	P->data=0;
	P->next=NULL;
	printf("链栈初始化成功\n");
}

void IsEmpty()//判断链栈是否为空
{
	
	if(S==NULL)
	{
		printf("链栈为空\n");
	}
	else
	{
		printf("链栈不为空\n");
	}
}

void Push()//入栈操作
{	
	
	Elemtype s,Count;
	S=(LinkStack*)malloc(sizeof(LinkStack));
	S->top=(Node*)malloc(sizeof(Node));
	printf("请输入链栈的长度:");
	scanf("%d", &Count);
	printf("请输入入栈的数字:");
	for(int i=0;i<Count;i++)
	{
		P=(Node*)malloc(sizeof(Node));
		P->next=NULL;
		scanf("%d", &s);
		
		P->data=s;
		P->next=S->top->next;
		S->top->next=P;
		
	}
	printf("入栈成功\n");
}

void Pop()//出栈操作
{
	
	Elemtype s,Count;
	S=(LinkStack*)malloc(sizeof(LinkStack));
	printf("请输入出栈的元素个数:");
	scanf("%d", &Count);
	if(S==NULL)
	{
		printf("链栈中没有元素");
	}
	for(int i=0;i<Count;i++)
	{
		S->top=(Node*)malloc(sizeof(Node));
		s=S->top->data;
		P=S->top;
		S->top=P->next;
		free(P);
	}
	printf("出栈成功\n");
	
}

void GetTopElem()//取栈顶元素
{
	S=(LinkStack*)malloc(sizeof(LinkStack));
	S->top=(Node*)malloc(sizeof(Node));
	if(S->top==NULL)
	{
		printf("没有栈顶元素");
	}
	else
	{
		printf("此时栈顶元素为:");
		int e=S->top->data;
		printf("%d\n", e);
	}
	
}

void DestroyStack()//销毁链栈
{
	LinkStack *q;
	S=(LinkStack*)malloc(sizeof(LinkStack));
	S->top=(Node*)malloc(sizeof(Node));
	S=q;
	while(q)
	{
		S->top=S->top->next;
		free(q);
		S=q;
	}
	printf("链栈已销毁\n");
}

void GetCount()//获得链栈元素个数
{
	int Count=0;
	Node *q;
	S=(LinkStack*)malloc(sizeof(LinkStack));
	S->top=(Node*)malloc(sizeof(Node));
	S->top=q;
	while(q)
	{
		q=(Node*)malloc(sizeof(Node));
		q=q->next;
		Count++;
	}
	printf("链栈元素个数为%d", Count);
}

void Show()//遍历输出链栈元素
{
	LinkStack *q;
	S=(LinkStack*)malloc(sizeof(LinkStack));
	q=(LinkStack*)malloc(sizeof(LinkStack));
	S->top=(Node*)malloc(sizeof(Node));
	
	if(S->top==NULL)
	{
		printf("链栈中没有元素");
	}
	S=q;
	while(q->top)
	{
		q->top=(Node*)malloc(sizeof(Node));
		printf("%d", q->top->data);
		q->top=q->top->next;
	}
}
int main()
{
	while(1)
	{
		printf("\t|--------链栈操作如下------|\n");
		printf("\n");
		printf("\t|--------初始化链栈请按1---------|\n");
		printf("\n");
		printf("\t|--------判断链栈是否为空请按2---------|\n");
		printf("\n");
		printf("\t|--------入栈操作请按3---------|\n");
		printf("\n");
		printf("\t|--------出栈操作请按4---------|\n");
		printf("\n");
		printf("\t|--------获得栈顶元素请按5---------|\n");
		printf("\n");
		printf("\t|--------销毁链栈请按6-----|\n");
		printf("\n");
		printf("\t|--------获得链栈结点个数请按7|\n");
		printf("\n");
		printf("\t|--------遍历输出链栈元素请按8|\n");
		printf("\n");
		printf("\t|**************************|\n");
		
		
		char ch=getch();
		switch(ch)
		{
			case '1':
				InitStack();//初始化链栈
				break;
			case '2':
				IsEmpty();//判断链栈是否为空
				break;
			case '3':
				Push();//入栈操作
				break;
			case '4':
				Pop();//出栈操作
				break;
			case '5':
				GetTopElem();//获得栈顶元素
				break;
			case '6':
				DestroyStack();//销毁链栈
				break;
			case '7':
				GetCount();//获得链栈结点个数
				break;
			case '8':
				Show();//遍历输出链栈元素
				break;
		}
	}
	
	
	
	return 0;
}