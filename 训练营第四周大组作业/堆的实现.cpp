#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int data[100];
    int size;
} heap_t;
void heap_init(heap_t *heap) 
{
    heap->size = 0;
}
void heap_insert(heap_t *heap, int value) 
{
    if(heap->size >= 100) 
	{
        printf("堆已满！！！\n");
        return;
    }
    heap->data[heap->size]=value;
    int i=heap->size;
    while(i>0 && heap->data[(i - 1) / 2]<heap->data[i]) 
	{
        int temp=heap->data[(i - 1) / 2];
        heap->data[(i - 1) / 2]=heap->data[i];
        heap->data[i]=temp;
        i=(i - 1) / 2;
    }
    heap->size++;
}
int heap_remove(heap_t *heap) 
{
    if (heap->size==0) 
	{
        printf("堆为空！！！\n");
        return -1;
    }
    int value=heap->data[0];
    heap->size--;
    heap->data[0]=heap->data[heap->size];
    int i=0;
    while(i*2+1 < heap->size) 
	{
        int child=i*2+1;
        if(child+1 < heap->size && heap->data[child + 1] > heap->data[child]) 
		{
            child++;
        }
        if (heap->data[i] < heap->data[child]) 
		{
            int temp=heap->data[i];
            heap->data[i]=heap->data[child];
            heap->data[child]=temp;
            i=child;
        } 
		else 
		{
            break;
        }
    }
    return value;
}
void heap_print(heap_t *heap) 
{
    printf("堆的大小为: %d\n", heap->size);
    printf("堆中元素为:");
    for(int i = 0; i < heap->size; i++) 
	{
        printf(" %d", heap->data[i]);
    }
    printf("\n");
}
int main() 
{
    heap_t heap;
    heap_init(&heap);
    int choice = 0, n;
    while(choice != 4) 
	{
        printf("1. 插入节点\n");
        printf("2. 清空堆\n");
        printf("3. 打印堆中元素\n");
        printf("4. 退出\n");
        printf("请输入你的选择: ");
        scanf("%d", &choice);
        switch(choice) 
		{
            case 1:
                printf("请输入插入的元素个数: ");
                int value;
                scanf("%d", &n);
                printf("请输入要插入的元素：\n");
                for(int i=0;i<n;i++)
                {
                	scanf("%d", &value);
                	heap_insert(&heap, value);
				}
                printf("节点插入成功！！！\n");
                break;
            case 2:
                value=heap_remove(&heap);
                if (value != -1) 
				{
                    printf("已删除的元素为: %d\n", value);
                }
                break;
            case 3:
                heap_print(&heap);
                break;
            case 4:
                printf("退出中...\n");
                break;
            default:
                printf("请输入正确的选择！！！\n");
                break;
        }
    }
    return 0;
}