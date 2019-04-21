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
	// 创建一个移动指针,头指针是单链表的唯一标识，不可移动
	LinkNode *p = L->node;
	while(i<num){
		scanf("%d",&e);
		// 创建一个结点，并为其分配内存
		LinkNode *current_node;
		current_node = (LinkNode*)malloc(sizeof(LinkNode));
		// 给当前结点的数据域赋值
		current_node->data = e;
		// 头结点的next指向当前结点
		p->next = current_node;
		// 当前结点的next指向NULL
		current_node->next = NULL;
		// 移动头指针，以便以后的赋值工作
		p = current_node;
		i++;
	}
	// 将链表长度存放在头结点中
	L->node->data = num;
	printf("hello\n");
	return OK;
}

/***************插入操作*******************/
// 将元素e插入至第i个位置

Status InsertElem(LinkList *L, Dtype e, int i){
	// 先判断i值是否符合要求
	if (i<= 0 || i>L->node->data)
	{	
		printf("i值非法！\n");
		return ERROR;
	}
	// 移动指针
	LinkNode *p = L->node;
	int count = 0;

	while(count<i-1){
		p = (LinkNode*)p->next;
		count++;
	}
	// printf("here!1111\n");
	// 创建新结点
	LinkNode *current_node;
	current_node = (LinkNode*)malloc(sizeof(LinkNode));
	// printf("here!22222\n");
	current_node->data = e;
	// printf("here!3333\n");
	current_node->next = p->next;
	// printf("here!444444\n");
	p->next = current_node;
	// 将头结点中存放的链表长度+1
	L->node->data++;
	return OK;
}

/*************删除操作************/
// 删除第i个位置的元素
Status DelElem(LinkList *L,int i ){
	// 判断i值是否符合要求
	if (i<=0 || i>L->node->data)
	{
		printf("i值非法！\n");
		return ERROR;
	}
	// 定义一个移动指针
	LinkNode *p = L->node;
	// 将移动指针p移动到第i-1个元素
	int count = 0;
	while(count<i-1){
		p = (LinkNode*)p->next;
		count++;
	}
	
	LinkNode *DelNode = p->next;
	LinkNode *NextNode = DelNode->next;
	p->next = NextNode;
	free(DelNode);
	// 头结点中存放的链表长度-1
	L->node->data--;
	return OK;
}

/*********************查询操作*************************/
//查询单链表的长度
Status GetLength(LinkList *L){
	printf("单链表长度为:%d\n", L->node->data);
	return OK;
} 


// 获取指定位置的值
Status GetElem(LinkList *L, int i){
	// 先判断i值是否符合要求
	if (i<=0 || i>L->node->data)
	{
		printf("i值非法！\n");
		return ERROR;
	}
	// 定义一个移动指针p
	LinkNode *p = L->node;
	// 移动指针p到指定位置
	
	for (int j = 0; j < i; ++j)
	{
		p = p->next;
	}
	printf("第%d个位置的元素为：%d\n", i, p->data);
	return OK;

}

int main(int argc, char const *argv[])
{
	LinkList *L;
	while(1){
		printf("\n");
		printf("=========================\n");
		printf("请根据提示进行操作：\n");
		printf("1.创建空表\n2.对链表进行赋值\n3.插入操作\n4.删除操作\n5.查询单链表长度\n6.获取指定位置的值\n7.退出\n");
		printf("=========================\n");
		printf("\n");
		
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
		if (flog==3)
		{
		// 	printf("您要获取第几个元素的值：\n");
		// 	int i;
		// 	scanf("%d", &i);
		// 	GetElem(list1,i);
			printf("请输入您要插入的值：\n");
			int e;
			scanf("%d", &e);
			printf("您要插入到第几个位置:\n");
			int i;
			scanf("%d", &i);
			InsertElem(L,e,i);
		}
		if (flog==4)
		{
			printf("您要删除第几个元素：\n");
			int i;
			scanf("%d",&i);
			DelElem(L, i);
		}
		if (flog==5)
		{
			GetLength(L);
		}
		if (flog==6)
		{
			printf("请问您要获取第几个位置的元素：\n");
			int num;
			scanf("%d",&num);
			GetElem(L, num);
		}
		if (flog==7) 
		{
			// 退出程序，该函数位于stdlib.h
			exit(0);
		}
	
	}
	// LinkList *L = Init();
	
	return 0;
}