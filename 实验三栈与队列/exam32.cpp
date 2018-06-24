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
	/*����һ���ն���Q*/
	Q.base=new ElemType[MAXQSIZE];
	if(!Q.base)exit(ERROR);
	Q.front=Q.rear=0;
	return OK;
}

int QueueLength(SqQueue Q)
{
	/*���ض��еĳ���*/
	return(Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}

int EnQueue(SqQueue &Q,ElemType e)
{
	/*����в�������(��ӣ�*/
	if((Q.rear+1)%MAXQSIZE==Q.front)
	{
		//βָ����ѭ�������ϼ�1�����ͷָ�룬�������� 
		cout<<"��������"<<e<<"����"<<"��Ϊ����"<<endl; 
		return ERROR;
	}else{
	cout<<"��������"<<e<<"�ɹ�"<<endl;
	
	Q.base[Q.rear]=e;				//��Ԫ�ز����β 
	Q.rear=(Q.rear+1)%MAXQSIZE;		//��βָ���1 
	return OK;
	}
}

int DeQueue(SqQueue &Q,ElemType &e)
{
	/*�Ӷ�����ȡ�����ݣ����ӣ�*/
	if(Q.front==Q.rear)return ERROR;    //�ӿ� 
	e=Q.base[Q.front];                  //�����ͷԪ�� 
	Q.front=(Q.front+1)%MAXQSIZE;		//��ͷָ���1 
	return OK;
}

int ShowQueue(SqQueue Q)
{
	SqQueue M;
	if(Q.front==Q.rear)return ERROR;    //�ӿ� 
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
	//1,2,3,4,5��d, e, b ���
	cout<<"1,2,3,4,5��d, e, b ���"<<endl;
	char e[50]={'1','2','3','4','5','d','e','b'};
	while(e[i]!='\0')
	{
		//cout<<i;
		EnQueue(Q,e[i]);
		i++;
	}
	ShowQueue(Q);
	//1,2,3����
	cout<<endl<<endl<<"1,2,3����:"<<endl;
	i=0;
	for(int i=0;i<3;i++)
	{
		DeQueue(Q,a);
	}
	ShowQueue(Q);
	//f, g, h, i, i,k ,h ���
	cout<<endl<<endl<<"f, g, h, i, i,k ,h ���:"<<endl;
	i=0;
	char c[50]={'f','g','h','i','i','k','h'};
	while(c[i]!='\0')
	{
		EnQueue(Q,c[i]);
		i++;
	}
	ShowQueue(Q);
	//4,5,d,e ����
	cout<<endl<<endl<<"4,5,d,e ����:"<<endl;
	i=0;
	for(int i=0;i<4;i++)
	{
		DeQueue(Q,a);
	}
	ShowQueue(Q);
	//n, o, p���
	cout<<endl<<endl<<"n, o, p���:"<<endl;
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
