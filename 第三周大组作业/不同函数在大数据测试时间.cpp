#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//插入排序
void InsertSort(int a[], int n)
{
	int i, j, t;
	for(i=1;i<n;i++)
	{
		t=a[i];
		j=i-1;
		while(j>=0 && a[j]>t)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=t;
	}
}

//归并排序
void merge(int a[], int l, int m, int r)
{
	int i, j, k;
	int n1=m-l+1;//左半部分数组的长度
	int n2=r-m;//右半部份数组的长度
	int L[n1], R[n2];
	//分别放入L数组和R数组
	for(i=0;i<n1;i++)
		L[i]=a[l+i];
	for(j=0;j<n2;j++)
		R[j]=a[m+1+j];
	
	i=0;
	j=0;
	k=l;
	//合并数组，将较小的值放入原数组
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			a[k]=L[i];
			i++;
		}
		else
		{
			a[k]=R[j];
			j++;
		}
		k++;
	}
	//将剩余部分放入原数组
	while(i<n1)
	{
		a[k]=L[i];
		k++;
		i++;
	}
	while(j<n2)
	{
		a[k]=R[j];
		k++;
		j++;
	}
}
void MergeSort(int a[], int l, int r)
{
	if(l<r)
	{
		int m=l+(r-l)/2;//取中间值
		MergeSort(a,l,m);//递归排序左半部分数组
		MergeSort(a,m+1,r);//递归排序右半部分数组
		merge(a,l,m,r);//合并排序后的两个数组
	}	
}

//计数排序
void CountSort(int a[], int n)
{
	int output[n];//定义输出数组
	int count[100000]={0};//定义计数数组
	for(int i=0;i<n;i++)
	{
		count[a[i]]++;//统计每个元素的出现次数
	}
	for(int i=1;i<=100000;i++)
	{
		count[i]+=count[i-1];//计算每个元素的最终位置
	}
	for(int i=n-1;i>=0;i--)
	{
		output[count[a[i]]-1]=a[i];//将a[i]放到合适的位置
		count[a[i]]--;//将计数数组中的a[i]的值减1
	}
	for(int i=0;i<n;i++)
	{
		a[i]=output[i];//将输出数组赋值给原数组
	}
}

//基数计数排序
int getMax(int a[], int n)
{
	int max=a[0];
	for(int i=1;i<n;i++)
	{
		if(a[i]>max)
			max=a[i];
	}
	return max;
}
void CountSort(int a[], int n, int exp)
{
	int output[n];//定义输出数组
	int count[10]={0};//定义计数数组 
	//统计每个元素的出现次数
	for(int i=0;i<n;i++)
	{
		count[(a[i]/exp)%10]++;
	}
	//计算每个元素的最终位置
	for(int i=1;i<10;i++)
	{
		count[i]+=count[i-1];
	}
	//将a[i]放到合适的位置 
	for(int i=n-1;i>=0;i--)
	{
		output[count[(a[i]/exp)%10]-1]=a[i];
		count[(a[i]/exp)%10]--;
	}
	//将输出数组赋值给原数组
	for(int i=0;i<n;i++)
	{
		a[i]=output[i];
	}
}
void RadixCountSort(int a[], int n)
{	
	int m=getMax(a, n);
	for(int exp=1;m/exp>0;exp*=10)//按照位数从低到高排序
	{
		CountSort(a,n,exp);
	}	
}

//快速排序
void swap(int* a, int* b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
int partition(int a[], int head, int tail)
{
	int pivot=a[tail];//取最后一个元素为基准值
	int i=(head-1);//定义左边元素的下标
	for(int j=head;j<=tail-1;j++)
	{
		if(a[j]<pivot)
		{
			i++;
			swap(&a[i],&a[j]);//交换当前元素和左边元素的位置
		}
	}
	swap(&a[i+1],&a[tail]);//交换左边元素和基准值的位置
	return (i+1);//返回基准值的下标
}
//递归版
void QuickSort1(int a[], int head, int tail)
{
	if(head<tail)
	{
		int p=partition(a,head,tail);//获取基准值的下标
		QuickSort1(a,head,p-1);//递归排序左半部分数组
		QuickSort1(a,p+1,tail);//递归排序右半部份数组
	}
}
//非递归版
void QuickSort2(int a[], int head, int tail)
{
	int stack[tail-head+1];//定义一个数组栈
	int top=-1;//初始化栈
	stack[++top]=head;
	stack[++top]=tail;//将head和tail入栈
	while(top>=0)
	{
		tail=stack[top--];//栈顶元素出栈，并赋值给tail
		head=stack[top--];//赋值给head
		int p=partition(a,head,tail);//获取基准值的下标
		if(p-1>head)//左半部分排序未充分
		{
			stack[++top]=head;//将head和p-1入栈
			stack[++top]=p-1;
		}
		if(p+1<tail)//右半部分排序未充分
		{
			stack[++top]=p+1;//将p+1和tail入栈
			stack[++top]=tail;
		}
	}
}

int main() 
{
    FILE* fp=fopen("insertionSortTime.txt", "w"); // 打开文件
    if(fp==NULL) 
	{ // 判断文件是否打开成功
        printf("Error opening file\n");
        return -1;
    }
    for (int n = 1000; n <= 100000; n += 1000) 
	{ // 不同数据量下的测试
        int a[100000];
        for (int i = 0; i < n; i++)
            a[i] = rand() % 100000 + 1; // 生成随机数
        clock_t t1 = clock(); // 记录开始时间
        InsertSort(a, n); // 插入排序
        MergeSort(a,0,n-1);//归并排序
        CountSort(a,n);//计数排序
        RadixCountSort(a,n);//基数计数排序
        QuickSort1(a,0,n-1);//快速排序（递归版）
        QuickSort2(a,0,n-1);//快速排序（非递归版）
        clock_t t2 = clock(); // 记录结束时间
        double time = (double)(t2 - t1) / CLOCKS_PER_SEC; // 计算时间（单位：秒）
        fprintf(fp, "%d %.6f\n", n, time); // 将数据写入文件
        printf("数据大小: %d, 用时: %.6f seconds\n", n, time); // 输出时间
    }
    fclose(fp); // 关闭文件
    printf("Data generated successfully and saved in file 'insertionSortTime.txt'\n");
    return 0;
}