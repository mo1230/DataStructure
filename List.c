/*******************线性表的顺序存储结构***************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_LENGTH 100

// 定义线性表结构体，这里是线性表的顺序存储结构

typedef struct List
{
	int list[MAX_LENGTH];
	int length;	
} MyList;

// 随机生成一个线性表
MyList InitList(){
	int count;
	MyList L;
	L.length = 0;
	printf("请输入表长：\n");
	scanf("%d", &count);
	// 初始化随机数发生器
	srand((int)time(NULL));
	for (int i = 0; i < count; ++i)
	{
		
		L.list[i] = rand()%100;
		L.length++;
		printf("%d\t", L.list[i]);
	}
	printf("\n");
	return L;
}


/**************查询操作****************/
// 获取表长
void GetLength(MyList L){
	printf("表长：%d\n", L.length);
}


// 获取指定位置的元素
void GetElem(MyList L, int i){
	// 判断i值是否符合要求
	if (i<0 || i>=L.length)
	{	
		printf("i值非法！，请重新输入：\n");
		scanf("%d", &i);
		printf("该元素为：%d\n", L.list[i]);
	}
	printf("该元素为：%d\n", L.list[i]);
}


// 获取指定元素的索引值
void GetIndex(MyList L, int e){
	// 遍历线性表，进行比较
	for (int i = 0; i < L.length; ++i)
	{
		if (e==L.list[i])
		{
			printf("该值的索引值为：%d\n", i);
		}
	}
}


/***************插入操作******************/
// 在第i个位置前插入元素
void InsertElem(MyList *L){
	printf("您想要在第几个元素前插入新元素：\n");
	int i;
	scanf("%d", &i);
	// 判断i值是否符合要求
	if (i<=0 || i> L->length)
	{
		printf("i值非法！，请重新输入：\n");
		scanf("%d", &i);
	}
	printf("请输入您要插入的新元素：\n");
	int elm;
	scanf("%d",&elm);
	// 插入前需要将第i个元素及以后元素后移一位
	for (int j = L->length; j >= i; j--)
	{	
		L->list[j] = L->list[j-1];
	}
	L->list[i-1] = elm;
	// 表长需要增加
	L->length++;
	// 再将线性表输出，以供用户查看结果
	printf("修改后，线性表为：\n");
	for (int i = 0; i < L->length; ++i)
	{
		printf("%d\t", L->list[i]);
	}
	printf("\n");
}


/***************删除操作***************/
// 删除第i个位置的元素
void DelElem(MyList *L){
	printf("您想要删除第几个元素：\n");
	int i;
	scanf("%d", &i);
	// 先判断i值是否符合要求
	if (i<=0 || i>L->length)
	{
		printf("i值非法！，请重新输入：\n");
		scanf("%d", &i);
	}
	// 删除第i个元素
	for (int j = i; j < L->length; ++j)	
	{
		L->list[j-1] = L->list[j];
	}
	// 表长减一
	L->length--;
	// 将修改后的线性表输出，以供用户确认
	for (int i = 0; i < L->length; ++i)
	{
		printf("%d\t", L->list[i]);
	}
	printf("\n");
}


int main(int argc, char const *argv[])
{
	MyList list1;

	while(1){
		printf("请根据提示进行操作：\n");
		printf("1.创建线性表\n2.获取表长\n3.获取指定位置的元素\n4.获取指定元素的索引值\n5.插入操作\n6.删除操作\n7.退出\n");
		printf("=========================\n");

		int flog;
		scanf("%d", &flog);
		// 根据flog进行判断用户操作
		if(flog==1){
			list1 = InitList();
		}
		if(flog==2){
			GetLength(list1);
		}	
		if (flog==3)
		{
			printf("您要获取第几个元素的值：\n");
			int i;
			scanf("%d", &i);
			GetElem(list1,i);
		}
		if (flog==4)
		{
			printf("请输入值：\n");
			int e;
			scanf("%d",&e);
			GetIndex(list1, e);
		}
		if (flog==5)
		{
			InsertElem(&list1);
		}
		if (flog==6)
		{
			DelElem(&list1);
		}
		if (flog==7)
		{
			// 退出程序，该函数位于stdlib.h
			exit(0);
		}
	
	}
	return 0;
}
