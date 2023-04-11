#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

//定义二叉树结构体
typedef struct binary_tree
{
	int data;
	struct binary_tree* left;
	struct binary_tree* right;
}Binary_Tree;

//创建新节点
Binary_Tree* create_node(int data)
{
	Binary_Tree* node=(Binary_Tree*)malloc(sizeof(Binary_Tree));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}

//插入节点
Binary_Tree* insert_node(Binary_Tree* root, int data)
{
	if(root==NULL)
	{
		root=create_node(data);//空则创建新节点
	}
	else if(data<root->data)//小的数据放在左支
	{
		root->left=insert_node(root->left, data);
	}
	else//大的数据放在右支
	{
		root->right=insert_node(root->right, data);
	}
	return root;
}

//删除节点
Binary_Tree* delete_node(Binary_Tree* root, int data)
{
	Binary_Tree* temp;//定义一个新节点
	if(root==NULL)
	{
		printf("该节点不存在。\n");
	}
	else if(data<root->data)
	{
		root->left=delete_node(root->right, data);
	}
	else if(data>root->data)
	{
		root->right=delete_node(root->right, data);
	}
	else
	{
		if(root->left==NULL)
		{
			temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			temp=root->left;
			free(root);
			return temp;
		}
		temp=root->right;
		while(temp && temp->left != NULL)
		{
			temp=temp->left;
		}
		root->data=temp->data;
		root->right=delete_node(root->right, temp->data);
	}
	return root;
}

//查找节点
Binary_Tree* search_node(Binary_Tree* root, int data)
{
	if(root==NULL)//数据不存在
	{
		printf("查找的元素不存在！！！\n");
		return 0;
	}
	else if(root->data==data)
	{
		return root;//返回根节点
	}
	else if(data<root->data)
	{
		return search_node(root->left, data);//递归在左子树中查找
	}
	else
	{
		return search_node(root->right, data);//递归在右子树中查找
	}
}

//前序遍历（递归）
void pre_order_traversal(Binary_Tree* root)
{
	if(root != NULL)
	{
		printf("%d ", root->data);
		pre_order_traversal(root->left);
		pre_order_traversal(root->right);
	}
}

//前序遍历（非递归）
void pre_order_non_recursive(Binary_Tree* root)
{
	Binary_Tree* stack[100];//定义栈
	int top=-1;//初始化栈顶
	Binary_Tree* node=root;
	while(node || top != -1)
	{
		while(node)
		{
			printf("%d ", node->data);//访问根节点
			stack[++top]=node;
			node=node->left;
		}
		node=stack[top--];
		node=node->right;
	}
}

// 中序遍历（递归）
void in_order_traversal(Binary_Tree* root) 
{
    if (root != NULL) 
	{
        in_order_traversal(root->left);
        printf("%d ", root->data);
        in_order_traversal(root->right);
    }
}
// 中序遍历（非递归）
void in_order_non_recursive(Binary_Tree* root) 
{
    Binary_Tree* stack[100];
    int top=-1;
    Binary_Tree* node=root;
    while(node || top != -1)
	{
        while(node) 
		{
            stack[++top]=node;
            node=node->left;
        }
        node=stack[top--];
        printf("%d ", node->data); // 访问根节点
        node=node->right;
    }
}
// 后序遍历（递归）
void post_order_traversal(Binary_Tree* root) 
{
    if(root != NULL) 
	{
        post_order_traversal(root->left);
        post_order_traversal(root->right);
        printf("%d ", root->data);
    }
}
// 后序遍历（非递归）
void post_order_non_recursive(Binary_Tree* root) 
{
    Binary_Tree* stack[100];
    int top=-1;
    Binary_Tree* node=root;
    Binary_Tree* last_visited=NULL;
    while (node || top != -1) 
	{
        while (node) 
		{
            stack[++top]=node;
            node=node->left;
        }
        node=stack[top];
        if (node->right==NULL || node->right==last_visited) 
		{
            printf("%d ", node->data); // 访问根节点
            top--;
            last_visited=node;
            node=NULL;
        } 
		else 
		{
            node=node->right;
        }
    }
}
// 层序遍历
void level_order_traversal(Binary_Tree* root) 
{
    Binary_Tree* queue[100]; // 定义队列
    int front=-1, rear=-1;
    Binary_Tree* node=root;
    if(node != NULL) 
	{
        queue[++rear]=node;
    }
    while(front != rear) 
	{
        node=queue[++front];
        printf("%d ", node->data); // 访问根节点
        if(node->left != NULL) 
		{
            queue[++rear]=node->left;
        }
        if (node->right != NULL) 
		{
            queue[++rear]=node->right;
        }
    }
}
int main() 
{
	Binary_Tree* root=NULL;
	while(1)
	{
		printf("\t|--------双叉树操作如下------|\n");
		printf("\n");
		printf("\t|--------插入节点请按1---------|\n");
		printf("\n");
		printf("\t|--------删除节点请按2---------|\n");
		printf("\n");
		printf("\t|--------查找节点请按3---------|\n");
		printf("\n");
		printf("\t|--------前序遍历（递归）请按4---------|\n");
		printf("\n");
		printf("\t|--------前序遍历（非递归）请按5---------|\n");
		printf("\n");
		printf("\t|--------中序遍历（递归）请按6-----|\n");
		printf("\n");
		printf("\t|--------中序遍历（非递归）请按7|\n");
		printf("\n");
		printf("\t|--------后序遍历（递归）请按8|\n");
		printf("\n");
		printf("\t|--------后序遍历（非递归）请按9|\n");
		printf("\n");
		printf("\t|--------层序遍历请按0|\n");
		printf("\n");
		printf("\t|**************************|\n");
	
		//功能选择
		char ch = getch();
	
		switch (ch)
		{
			case '1'://插入节点
				int n, data;
				printf("请输入要插入的节点个数:");
				scanf("%d", &n);
				printf("请输入要插入的节点:\n");
				for(int i=0;i<n;i++)
				{
					scanf("%d", &data);
					root=insert_node(root, data);
				}
				printf("插入成功！！！\n");
				break;
			case '2'://删除节点
				int m, Ddata;
				printf("请输入要删除的节点个数:");
				scanf("%d", &m);
				printf("请输入要删除的节点:\n");
				for(int i=0;i<m;i++)
				{
					scanf("%d", &Ddata);
					root=delete_node(root, Ddata);
				}
				printf("删除成功！！！\n");
				break;
			case '3'://查找节点
				int Sdata;
				printf("请输入要查找的元素:");
				scanf("%d", &Sdata);
				root=search_node(root,Sdata);
			
			case '4'://前序遍历（递归）
				printf("前序遍历（递归）的结果：\n");
				pre_order_traversal(root);
				printf("\n");
				break;
			case '5'://前序遍历（非递归）
				printf("前序遍历（非递归）的结果：\n");
				pre_order_non_recursive(root);
				printf("\n");
				break;
			case '6'://中序遍历（递归）
				printf("中序遍历（递归）的结果：\n");
				in_order_traversal(root);
				printf("\n");
				break;
			case '7'://中序遍历（非递归）
				printf("中序遍历（非递归）的结果：\n");
				in_order_non_recursive(root);
				printf("\n");
				break;
			case '8'://后序遍历（递归）
				printf("后序遍历（递归）的结果：\n");
				post_order_traversal(root);
				printf("\n");
				break;
			case '9'://后序遍历（非递归）
				printf("后序遍历（非递归）的结果：\n");
				post_order_non_recursive(root);
				printf("\n");
				break;
			case '0'://层序遍历
				printf("层序遍历的结果：\n");
				level_order_traversal(root);
				printf("\n");
				break;
		}
	}
    return 0;
}