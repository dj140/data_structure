#include<iostream>
#include<cstdlib>
using namespace std;
#define  STACK_INIT_SIZE  10    /*  栈初始向量大小  */
#define STACKINCREMENT 5   /*  存储空间分配增量  */
#define OK 1
#define MAXSIZE 5
#define ERROR 0
#define OVERFLOW -1
//typedef int SElemType;
typedef  int  ElemType;
typedef struct
{   ElemType  *base;     /*  栈不存在时值为NULL  */
    ElemType  *top;      /*  栈顶指针  */
    int   stacksize ;      
}TranSqstack;
int InitStack(TranSqstack &S)    /* 初始化  */
{
S.base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
if(!S.base)exit(OVERFLOW);
S.top = S.base;
S.stacksize = STACK_INIT_SIZE;
return OK;
}
bool IsEmpty(TranSqstack &S)    /*  判断是否为空栈  */
{
if(S.top == S.base)
return true;
else
return false;
}
int GetTop(TranSqstack S)    /*  若栈不空，返回S的栈顶元素  */
{
if(S.top != S.base)
return*(S.top - 1);
}


int Push(TranSqstack &S,ElemType e)     /*  进栈  */
{
if(S.top - S.base >= S.stacksize)
{
S.base = (ElemType *)realloc(S.base,(S.stacksize + STACKINCREMENT) * sizeof(ElemType));
if(!S.base)return ERROR;
S.top = S.base + S.stacksize;
S.stacksize += STACKINCREMENT;
}
*S.top ++ = e;     //元素e压入栈顶，栈顶指针加1 
return OK;
}


int Pop(TranSqstack &S,ElemType e)     /*  弹栈  */
{
if(S.top == S.base)return ERROR;
e = * --S.top;         //栈顶指针减1,将栈顶元素赋给e 
return e;
}
int DestroyStack(TranSqstack &S)     /* 销毁栈S，S不再存在 */
 { 
   free(S.base);
   S.base = NULL;
   S.top = NULL;
   S.stacksize = 0;
   return OK;
 }
 int conversion(TranSqstack &S,long n,int base)     /* 进制转换函数 */
 {   
 	InitStack(S);
    int c,m=0,s[100];
    cout<<"("<<n<<")10="<<"("; 
    while (n!=0)
    {
	//数制转换，结果存入数组s[m]    
      
        c=n%base;    
        n=n/base;    
        m++;s[m]=c;   //将余数按顺序存入数组s[m]中    
    }    
    
    for(int k=m;k>=1;k--)
    {
	//输出转换后的序列    
       
        if(s[k]>=10) //若为十六进制等则输出相对应的字母 
        {
			Push(S,(char)(s[k]+55));
            cout<<(char)(s[k]+55);    
        }
        else         //否则直接输出数字 
		{  
        	Push(S,s[k]);
            cout<<s[k];    
        }
    }    
    
    cout<<")"<<base<<endl; 
    /*
  while(n > 0)
  {
  //Push(S,digit[n % base]);
  //printf("%s",digit[n % base]);
  printf("%d",n);
  n /= base;
}
*/
	return 0;
}
int visit(ElemType c)
{
	printf("%d ",c);
	return OK;
}
int StackTraverse(TranSqstack S)
{
	int i=0;
	while(i<=(S.top-S.base)- 1)	/*(S.top-S.bottom)- 1是因为S.top,总是指向队列的队尾*/
	{
		visit(S.base[i++]);
	}
	printf("\n");
	return OK;
}
int main()
{
	TranSqstack MS;
	int n;
	scanf("%d", &n);
	conversion(MS, n, 2);
	conversion(MS, n, 8);
	conversion(MS, n, 16);
	cout<<GetTop(MS);
	DestroyStack(MS);
	return 0; 
}
