#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 定义节点结构体
struct Node 
{
    int data;           // 数据域
    struct Node *next;  // 指向下一个节点的指针
};
// 定义队列结构体
struct Queue 
{
    struct Node *front; // 队头指针
    struct Node *rear;  // 队尾指针
};
// 初始化队列
void initQueue(struct Queue *queue) 
{
    queue->front = queue->rear = NULL;  // 队列为空，队头和队尾指针都为空
}
// 判断队列是否为空
int isQueueEmpty(struct Queue *queue) 
{
    return queue->front == NULL;
}
// 入队操作
void enqueue(struct Queue *queue, int data) 
{
    // 创建新节点
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;       // 赋值
    newNode->next = NULL;       // 新节点的next指针指向NULL
    // 如果队列为空，则新节点即为队头，也是队尾
    if (queue->rear == NULL) 
	{
        queue->front = queue->rear = newNode;   // 队头和队尾指针都指向新节点
    }
	else 
	{
        // 否则将新节点接在队尾，修改队尾指针
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}
// 出队操作
int dequeue(struct Queue *queue) 
{
    // 如果队列为空，返回-1
    if (isQueueEmpty(queue)) 
	{
        printf("队列为空。\n");
        return -1;
    } 
	else 
	{
        // 否则将队头节点出队，修改队头指针
        struct Node *temp = queue->front;
        int data = temp->data;
        queue->front = queue->front->next;
        if (queue->front == NULL) 
		{
            queue->rear = NULL;
        }
        free(temp);     // 释放空间
        return data;    // 返回被出队的元素的值
    }
}
// 清空队列
void clearQueue(struct Queue *queue) 
{
    while (!isQueueEmpty(queue)) 
	{
        dequeue(queue);
    }
}
// 打印队列中所有元素
void printQueue(struct Queue *queue)
{
    if (isQueueEmpty(queue)) 
	{
        printf("队列为空。\n");
    } else {
        struct Node *current = queue->front;
        printf("队头 -> ");
        while (current != NULL)
		{
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("队尾\n");
    }
}
// 输出队首元素
void getFront(struct Queue *queue) 
{
    if (isQueueEmpty(queue)) 
	{
        printf("队列为空。\n");
    } else {
        printf("队首元素为：%d\n", queue->front->data);
    }
}
// 主函数
int main() 
{
    struct Queue queue;     // 定义队列
    initQueue(&queue);      // 初始化队列
    int choice,value;
    while (1) 
	{
        // 打印菜单
        printf("\t|--------链式队列操作如下------|\n");
		printf("\n");
		printf("\t|--------入队操作请按1---------|\n");
		printf("\n");
		printf("\t|--------出队操作请按2---------|\n");
		printf("\n");
		printf("\t|--------清空队列请按3---------|\n");
		printf("\n");
		printf("\t|--------遍历输出队列元素请按4---------|\n");
		printf("\n");
		printf("\t|--------获得队列首个元素请按5---------|\n");
		printf("\n");
		printf("\t|--------退出程序请按6-----|\n");
		printf("\n");
		printf("\t|**************************|\n");
        // 根据用户的选择执行相应的操作
        printf("请做出你的选择:\n");
        scanf("%d", &choice);
        switch (choice)
		 {
            case 1:
                printf("请输入要入队的值：");
                scanf("%d", &value);
                enqueue(&queue, value);     // 入队
                break;
            case 2:
                printf("出队的值为：%d\n", dequeue(&queue));    // 出队
                break;
            case 3:
                clearQueue(&queue);     // 清空队列
                break;
            case 4:
                printQueue(&queue);     // 打印队列
                break;
            case 5:
                getFront(&queue);       // 获取队首元素
                break;
            case 6:
                exit(0);    // 退出程序
            default:
                printf("无效的选择。\n");  // 如果输入的选择无效，打印提示信息
        }
    }
    return 0;
}