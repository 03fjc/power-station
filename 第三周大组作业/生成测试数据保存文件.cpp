#include <stdio.h>
#include <stdlib.h>
#include  <time.h>

void GetTextData()
{
	int n, a[100000];//定义最大长度数组
	printf("请输入数组的长度：");
	scanf("%d", &n);
	printf("请输入数组元素的最大范围：");
	int x;
	scanf("%d", &x);
	
	srand(time(NULL));//随机数种子
	FILE* fp=fopen("C:\\Users\\Lenovo\\Desktop\\test.txt.txt", "w");
	fprintf(fp,"%d\n",n);//写入数组的长度
	for(int i=0;i<n;i++)
	{
		a[i]=rand()%x+1;//生成随机数
		fprintf(fp,"%d ",a[i]);//随机数写入文件
	} 
	fclose(fp);
	printf("数据保存成功！！！");
}

int main()
{
	GetTextData();
	return 0;
}