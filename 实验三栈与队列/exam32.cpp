#include <cstdlib>
#include <string>
#include <iostream>
#include <tchar.h>
#include <iostream>
#include <iomanip>
#define MAXQSIZE 10
#define ERROR 0
#define OK 1
using namespace std;
typedef char ElemType;
typedef struct
{
	ElemType *base;
	int front;
	int rear;
}SqQueue;
int InitQueue(SqQueue &Q)
{
	/*构造一个空队列Q*/
	Q.base=new ElemType[MAXQSIZE];
	if(!Q.base)exit(ERROR);
	Q.front=Q.rear=0;
	return OK;
}

int QueueLength(SqQueue Q)
{
	/*返回队列的长度*/
	return(Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}

int EnQueue(SqQueue &Q,ElemType e)
{
	/*向队列插入数据(入队）*/
	if((Q.rear+1)%MAXQSIZE==Q.front)
	{
		//尾指针在循环意义上加1后等于头指针，表明队满 
		cout<<"插入数据"<<e<<"错误"<<"因为队满"<<endl; 
		return ERROR;
	}else{
	cout<<"插入数据"<<e<<"成功"<<endl;
	
	Q.base[Q.rear]=e;				//新元素插入队尾 
	Q.rear=(Q.rear+1)%MAXQSIZE;		//队尾指针加1 
	return OK;
	}
}

int DeQueue(SqQueue &Q,ElemType &e)
{
	/*从队列中取出数据（出队）*/
	if(Q.front==Q.rear)return ERROR;    //队空 
	e=Q.base[Q.front];                  //保存队头元素 
	Q.front=(Q.front+1)%MAXQSIZE;		//队头指针加1 
	return OK;
}

int ShowQueue(SqQueue Q)
{
	SqQueue M;
	if(Q.front==Q.rear)return ERROR;    //队空 
	M=Q;
	while(M.front!=Q.rear)
	{
		cout<<M.base[M.front]<<setw(3);
		M.front=(M.front+1)%MAXQSIZE;
	}
	
}
int main()
{
	int i=0;
	char a;
	SqQueue Q;
	InitQueue(Q);
	//1,2,3,4,5，d, e, b 入队
	cout<<"1,2,3,4,5，d, e, b 入队"<<endl;
	char e[50]={'1','2','3','4','5','d','e','b'};
	while(e[i]!='\0')
	{
		//cout<<i;
		EnQueue(Q,e[i]);
		i++;
	}
	ShowQueue(Q);
	//1,2,3出队
	cout<<endl<<endl<<"1,2,3出队:"<<endl;
	i=0;
	for(int i=0;i<3;i++)
	{
		DeQueue(Q,a);
	}
	ShowQueue(Q);
	//f, g, h, i, i,k ,h 入队
	cout<<endl<<endl<<"f, g, h, i, i,k ,h 入队:"<<endl;
	i=0;
	char c[50]={'f','g','h','i','i','k','h'};
	while(c[i]!='\0')
	{
		EnQueue(Q,c[i]);
		i++;
	}
	ShowQueue(Q);
	//4,5,d,e 出队
	cout<<endl<<endl<<"4,5,d,e 出队:"<<endl;
	i=0;
	for(int i=0;i<4;i++)
	{
		DeQueue(Q,a);
	}
	ShowQueue(Q);
	//n, o, p入队
	cout<<endl<<endl<<"n, o, p入队:"<<endl;
	i=0;
	char f[50]={'n','o','p'};
	while(f[i]!='\0')
	{
		EnQueue(Q,f[i]);
		i++;
	}
	ShowQueue(Q);
	return 0;
}
