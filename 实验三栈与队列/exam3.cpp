#include<iostream>
#include<cstdlib>
using namespace std;
#define  STACK_INIT_SIZE  10    /*  ջ��ʼ������С  */
#define STACKINCREMENT 5   /*  �洢�ռ��������  */
#define OK 1
#define MAXSIZE 5
#define ERROR 0
#define OVERFLOW -1
//typedef int SElemType;
typedef  int  ElemType;
typedef struct
{   ElemType  *base;     /*  ջ������ʱֵΪNULL  */
    ElemType  *top;      /*  ջ��ָ��  */
    int   stacksize ;      
}TranSqstack;
int InitStack(TranSqstack &S)    /* ��ʼ��  */
{
S.base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
if(!S.base)exit(OVERFLOW);
S.top = S.base;
S.stacksize = STACK_INIT_SIZE;
return OK;
}
bool IsEmpty(TranSqstack &S)    /*  �ж��Ƿ�Ϊ��ջ  */
{
if(S.top == S.base)
return true;
else
return false;
}
int GetTop(TranSqstack S)    /*  ��ջ���գ�����S��ջ��Ԫ��  */
{
if(S.top != S.base)
return*(S.top - 1);
}


int Push(TranSqstack &S,ElemType e)     /*  ��ջ  */
{
if(S.top - S.base >= S.stacksize)
{
S.base = (ElemType *)realloc(S.base,(S.stacksize + STACKINCREMENT) * sizeof(ElemType));
if(!S.base)return ERROR;
S.top = S.base + S.stacksize;
S.stacksize += STACKINCREMENT;
}
*S.top ++ = e;     //Ԫ��eѹ��ջ����ջ��ָ���1 
return OK;
}


int Pop(TranSqstack &S,ElemType e)     /*  ��ջ  */
{
if(S.top == S.base)return ERROR;
e = * --S.top;         //ջ��ָ���1,��ջ��Ԫ�ظ���e 
return e;
}
int DestroyStack(TranSqstack &S)     /* ����ջS��S���ٴ��� */
 { 
   free(S.base);
   S.base = NULL;
   S.top = NULL;
   S.stacksize = 0;
   return OK;
 }
 int conversion(TranSqstack &S,long n,int base)     /* ����ת������ */
 {   
 	InitStack(S);
    int c,m=0,s[100];
    cout<<"("<<n<<")10="<<"("; 
    while (n!=0)
    {
	//����ת���������������s[m]    
      
        c=n%base;    
        n=n/base;    
        m++;s[m]=c;   //��������˳���������s[m]��    
    }    
    
    for(int k=m;k>=1;k--)
    {
	//���ת���������    
       
        if(s[k]>=10) //��Ϊʮ�����Ƶ���������Ӧ����ĸ 
        {
			Push(S,(char)(s[k]+55));
            cout<<(char)(s[k]+55);    
        }
        else         //����ֱ��������� 
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
	while(i<=(S.top-S.base)- 1)	/*(S.top-S.bottom)- 1����ΪS.top,����ָ����еĶ�β*/
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
