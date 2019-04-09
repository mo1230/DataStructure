/*******************线性表的顺序存储结构***************/

#include<stdio.h>
#define MAX_LENGTH 100

// 定义线性表结构体，这里是线性表的顺序存储结构

typedef struct List
{
	int list[MAX_LENGTH];
	int length;	
} MyList;

/**************查询操作****************/
// 获取表长
void GetLength(MyList L){
	printf("%d\n", L.length);
}


// 获取指定位置的元素
void GetElem(MyList L, int i){
	// 判断i值是否符合要求
	if (i<0 || i>=L.length)
	{	
		printf("i值非法！，请重新输入：\n");
		scanf("%d", &i);
		printf("%d\n", L.list[i]);
	}
	printf("%d\n", L.list[i]);
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
int main(int argc, char const *argv[])
{
	MyList list1;
	list1.list[0] = 1;
	list1.list[1] = 2;
	list1.length = 2;
	printf("%d\n", list1.length);
	GetElem(list1, 1);
	return 0;
}
