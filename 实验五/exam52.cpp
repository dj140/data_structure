#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h> 
#define OK 1 
#define DATAEND  0
#define EMPTY     -1
#define ERROR  0
typedef  int  ElemType ;
using namespace std;


/***�������ṹ��***/ 
typedef struct BiTrNode{
  int data;
  struct BiTrNode *left, *right;
}BiTrNode,  *BTree;

/***��ջ***/ 
typedef struct StackNode{
        BiTrNode* nodePtr; 
        char  child;
        StackNode* next;
} *StackPtr;

//StackPtr    S;

 
 
int addNode(BTree &treeHead,int num);
int initStack(StackPtr &S);
BTree createBiTreeNonRecursive(void);
void PreOderTraverse(BTree T);
 
 
/*��ʼ����ջ*/
int InitStack(StackNode &p)    /* ��ʼ�� */
{
    p.next=NULL;
    return OK;
}


/*�ж���ջ�Ƿ�Ϊ��*/
int StackEmpty(StackNode p)
{
	if(p.next == NULL)return OK;
	else return ERROR;
}


/***ѹջ***/ 
int push(StackNode &S,BTree e,char c){
	StackPtr p = (StackPtr)malloc(sizeof(StackNode));  //����ռ� 
	if(!p)return ERROR;
	p->nodePtr = e;           //nodePtr��ֵ 
	p->child = c;             //child��ֵ 
	p->next = S.next;
	S.next = p;
	return OK;
}


/***��ջ***/ 
int pop(StackNode &S)
{
	if(StackEmpty(S))return ERROR;
	S.next = S.next->next;         //�ı�ָ�� 
	return OK;
}


bool b=false; 

//���������
void CreateBTree(BTree &BT){
	int data;
	if(b){
		BT = NULL;
		return;
	}
	cin>>data;
	if(data==DATAEND){
		BT=NULL;
		b=true;
	}else if(data==EMPTY){
		BT=NULL;
	}else{
		BT=(BTree)malloc(sizeof(BiTrNode));
		BT->data=data;
		CreateBTree(BT->left);
		CreateBTree(BT->right);
	}
}



/***�ݹ��������������***/
void preOrder_DLR(BTree BT) 
{
	if(BT){
		printf("%-4d",BT->data);    //����ڵ����� 
		preOrder_DLR(BT->left);    //�ݹ������� 
		preOrder_DLR(BT->right);   //�ݹ������� 
	}
}

/***�ݹ��������������***/
void inOrder_LDR(BTree BT) 
{
	if(BT){
		inOrder_LDR(BT->left);    //�ݹ������� 
		printf("%-4d",BT->data);    //����ڵ����� 
		inOrder_LDR(BT->right);   //�ݹ������� 
	}
}

/***�ݹ�������������***/
void postOrder_LRD(BTree BT) 
{
	if(BT){
		postOrder_LRD(BT->left);    //�ݹ������� 
		postOrder_LRD(BT->right);   //�ݹ������� 
		printf("%-4d",BT->data);    //����ڵ����� 
	}
}

/***�ǵݹ��������������***/
void NoRecursionPreOrderTraverse_DLR(BTree T)
{
	StackNode S;       //����ջ 
	BTree P=T;         //����ָ�븳��p 
	InitStack(S);
	while(P||!StackEmpty(S)){
		while(P){
			printf("%-4d",P->data);    //����ڵ����� 
			push(S,P,'L');       //��P��ջS 
			P=P->left;           //pָ��ָ�������� 
		}
		P=S.next->nodePtr;       //��pָ��ָ��ջs��nodePtr 
		pop(S);                 //S�Ķ���Ԫ�س�ջ 
		P=P->right;            //��Pָ��P�������� 
	}
}

/***�ǵݹ��������������***/
void NoRecursionInOrderTraverse_LDR(BTree T)
{
	StackNode S;       //����ջ 
	BTree P=T;         //����ָ�븳��p 
	InitStack(S);
	while(P||!StackEmpty(S)){
		while(P){
			
			push(S,P,'L');        //��P��ջS 
			P=P->left;           //pָ��ָ�������� 
		}
		P=S.next->nodePtr;       //��pָ��ָ��ջs��nodePtr 
		printf("%-4d",P->data);    //����ڵ����� 
		pop(S);                 //S�Ķ���Ԫ�س�ջ 
		P=P->right;            //��Pָ��P�������� 
	}
}

/***�ǵݹ�������������***/
void NoRecursionPostOrderTraverse_LRD(BTree T)
{
	StackNode S;       //����ջ 
	BTree P=T;         //����ָ�븳��p 
	InitStack(S);
	while(T){
		push(S,T,'L');        //����������ջ
		T = T->left;
	}	 
	while(!StackEmpty(S)){
			P=S.next->nodePtr;
			if(!P->right||S.next->child=='R'){
				printf("%-4d",P->data);    //����ڵ�����
				pop(S);                 //S�Ķ���Ԫ�س�ջ 
				T=P;
			}else{
				T=P;
				P=P->right;            //��Pָ��P��������
				S.next->child='R';
			}
			while(P!=T&&P){
				push(S,P,'L');        //��P��ջS 
				P=P->left;           //pָ��ָ�������� 
			}
		}
}
int processEmptyData(BTree &treeHead)
{
	
}

void PreOderTraverse(BTree T)
{
    if(T==NULL)
        return;
    cout<<"����������"; 
    printf("%d",T->data);  //��ʾ������ݣ����Ը���Ϊ�����Խ�����
    PreOderTraverse(T->left);   //�ȱ���������
    PreOderTraverse(T->right);    //������������ 
 } 
int PostOrder(BTree T) {
    if(T){
        PostOrder(T->left);
        PostOrder(T->right);
        printf("%d",T->data);
        return OK;
    }
    else return ERROR;
}

/***����Ҷ�ӽڵ���***/
int Leave(BTree BT)
{
	int ll,lr;
	if(!BT)return 0;
	if(!BT->left&&!BT->right)
		return 1; //�ж��Ƿ�Ϊһ���ڵ���� 
	ll=Leave(BT->left);       //�ݹ����� 
	lr=Leave(BT->right);	  //�ݹ����� 
	return ll+lr; 
} 
 
/***�����������***/
int BTreeDepth(BTree BT)
{
	if(BT==NULL)
		return 0;
	else{
		int dep1=BTreeDepth(BT->left);
		int dep2=BTreeDepth(BT->right);
		if(dep1>dep2)
			return dep1+1;
		else
			return dep2+1; 
		}
 } 
int main()
{
	BTree T;
	cout<<"���������������"<<endl;
	CreateBTree(T);
	cout<<"����ݹ������������"<<endl;
	preOrder_DLR(T);
	cout<<endl;
	cout<<"����ݹ������������"<<endl;
	inOrder_LDR(T);
	cout<<endl;
	cout<<"����ݹ������������"<<endl;
	postOrder_LRD(T);
	cout<<endl;
	cout<<"����ǵݹ������������"<<endl;
	NoRecursionPreOrderTraverse_DLR(T);
	cout<<endl;
	cout<<"����ǵݹ������������"<<endl;
	NoRecursionInOrderTraverse_LDR(T);
	cout<<endl;
	cout<<"����ǵݹ������������"<<endl;
	NoRecursionPostOrderTraverse_LRD(T);
	cout<<endl;
	cout<<"�ö�������Ҷ�ӽ����Ϊ��"<<endl;
	cout<<Leave(T)<<endl;
	cout<<endl;
	cout<<"�ö����������Ϊ��"<<endl;
	cout<<BTreeDepth(T)<<endl;
	return 0;
}
