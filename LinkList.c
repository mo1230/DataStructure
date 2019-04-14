#include <stdio.h>
#include <stdlib.h>

// 单链表的最大容量
// #define MAX_SIZE 100
typedef int Dtype;

typedef int Status;
// 状态码
#define OK 1
#define ERROR 0

/*****************单链表定义***************/
// 节点定义
typedef struct LinkNode
{
	// 数据域
	Dtype data;
	// 指针域
	struct LinkNode *next;
	// int length;
} LinkNode;

// 链表定义
typedef struct LinkList
{
	LinkNode *node;
} LinkList;


/****************初始化操作*****************/
// 创建空表
LinkList* Init(){
	// 创建头结点
	// 变量的声明并没有为其分配内存
	LinkList *L;
	L = (LinkList*)malloc(sizeof(LinkList));
	L->node = (LinkNode*) malloc(sizeof(LinkNode));
	// 让头结点的指针域指向NULL
	L->node->next = NULL;
	return L;
}

// 进行赋值  尾插法
Status CreateList(LinkList *L, int num){
	printf("请输入元素：\n");
	int e;
	int i =0;
	while(i<num){
		scanf("%d",&e);
		// 创建一个结点，并为其分配内存
		LinkNode *current_node;
		current_node = (LinkNode*)malloc(sizeof(LinkNode));
		// 给当前结点的数据域赋值
		current_node->data = e;
		// 头结点的next指向当前结点
		L->node->next = current_node;
		// 当前结点的next指向NULL
		current_node->next = NULL;
		// 移动头指针，以便以后的赋值工作
		L->node = current_node;
		i++;
	}
	printf("hello\n");
	return OK;
}

int main(int argc, char const *argv[])
{
	while(1){
		printf("请根据提示进行操作：\n");
		printf("1.创建空表\n2.对链表进行赋值\n3.====\n4.====\n5.====\n6.====\n7.退出\n");
		printf("=========================\n");

		LinkList *L;
		int flog;
		scanf("%d", &flog);
		// 根据flog进行判断用户操作
		if(flog==1){
			
			L = Init();
		}
		if(flog==2){
			int length;
			printf("请输入要创建的链表长度：\n");
			scanf("%d",&length);
			CreateList(L, length);
		}	
		/*if (flog==3)
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
		}*/
		if (flog==7) 
		{
			// 退出程序，该函数位于stdlib.h
			exit(0);
		}
	
	}
	// LinkList *L = Init();
	
	return 0;
}