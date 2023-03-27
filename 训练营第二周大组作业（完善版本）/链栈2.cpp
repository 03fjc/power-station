#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 定义节点结构体
struct Node 
{
    int data;           // 数据域
    struct Node *next;  // 指向下一个节点的指针
};
// 定义栈结构体
struct Stack 
{
    struct Node *top;   // 栈顶指针
};
// 初始化栈
void initStack(struct Stack *stack) 
{
    stack->top = NULL;  // 栈为空，栈顶指针为空
}
// 判断栈是否为空
int isStackEmpty(struct Stack *stack) 
{
    return stack->top == NULL;
}
// 入栈操作
void push(struct Stack *stack, int data) 
{
    // 创建新节点
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;       // 赋值
    newNode->next = stack->top; // 新节点的next指针指向当前栈顶
    stack->top = newNode;       // 栈顶指针指向新节点
}
// 出栈操作
int pop(struct Stack *stack) 
{
    // 如果栈为空，返回-1
    if (isStackEmpty(stack)) 
	{
        printf("栈为空。\n");
        return -1;
    } 
	else 
	{
        // 否则将栈顶节点出栈，修改栈顶指针
        struct Node *temp = stack->top;
        int data = temp->data;
        stack->top = stack->top->next;
        free(temp);     // 释放空间
        return data;    // 返回被出栈的元素的值
    }
}
// 清空栈
void clearStack(struct Stack *stack) 
{
    while (!isStackEmpty(stack)) 
	{
        pop(stack);
    }
}
// 打印栈中所有元素
void printStack(struct Stack *stack) 
{
    if (isStackEmpty(stack)) 
	{
        printf("栈为空。\n");
    } 
	else 
	{
        struct Node *current = stack->top;
        printf("栈顶 -> ");
        while (current != NULL) 
		{
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("栈底\n");
    }
}
// 输出栈顶元素
void getTop(struct Stack *stack) 
{
    if (isStackEmpty(stack)) 
	{
        printf("栈为空。\n");
    } else {
        printf("栈顶元素为：%d\n", stack->top->data);
    }
}
// 主函数
int main() 
{
    struct Stack stack;     // 定义栈
    initStack(&stack);      // 初始化栈
    int choice, value;
    while (1) 
	{
        // 打印菜单
        printf("\t|--------链栈操作如下------|\n");
		printf("\n");
		printf("\t|--------入栈操作请按1---------|\n");
		printf("\n");
		printf("\t|--------出栈操作请按2---------|\n");
		printf("\n");
		printf("\t|--------清空栈请按3---------|\n");
		printf("\n");
		printf("\t|--------遍历输出栈中元素请按4---------|\n");
		printf("\n");
		printf("\t|--------获得链栈首个元素请按5---------|\n");
		printf("\n");
		printf("\t|--------退出程序请按6-----|\n");
		printf("\n");
		printf("\t|**************************|\n");
		printf("请做出你的选择：");
        scanf("%d", &choice);
        // 根据用户的选择执行相应的操作
        switch (choice) 
		{
            case 1:
                printf("请输入要入栈的值：");
                scanf("%d", &value);
                push(&stack, value);     // 入栈
                break;
            case 2:
                printf("出栈的值为：%d\n", pop(&stack));    // 出栈
                break;
            case 3:
                clearStack(&stack);     // 清空栈
                break;
            case 4:
                printStack(&stack);     // 打印栈
                break;
            case 5:
                getTop(&stack);         // 获取栈顶元素
                break;
            case 6:
                exit(0);    // 退出程序
            default:
                printf("无效的选择。\n");  // 如果输入的选择无效，打印提示信息
        }
    }
    return 0;
}