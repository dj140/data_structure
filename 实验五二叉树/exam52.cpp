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


/***二叉树结构体***/ 
typedef struct BiTrNode{
  int data;
  struct BiTrNode *left, *right;
}BiTrNode,  *BTree;

/***链栈***/ 
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
 
 
/*初始化链栈*/
int InitStack(StackNode &p)    /* 初始化 */
{
    p.next=NULL;
    return OK;
}


/*判断链栈是否为空*/
int StackEmpty(StackNode p)
{
	if(p.next == NULL)return OK;
	else return ERROR;
}


/***压栈***/ 
int push(StackNode &S,BTree e,char c){
	StackPtr p = (StackPtr)malloc(sizeof(StackNode));  //分配空间 
	if(!p)return ERROR;
	p->nodePtr = e;           //nodePtr赋值 
	p->child = c;             //child赋值 
	p->next = S.next;
	S.next = p;
	return OK;
}


/***弹栈***/ 
int pop(StackNode &S)
{
	if(StackEmpty(S))return ERROR;
	S.next = S.next->next;         //改变指针 
	return OK;
}


bool b=false; 

//构造二叉树
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



/***递归先序遍历二叉树***/
void preOrder_DLR(BTree BT) 
{
	if(BT){
		printf("%-4d",BT->data);    //输出节点数据 
		preOrder_DLR(BT->left);    //递归左子树 
		preOrder_DLR(BT->right);   //递归右子树 
	}
}

/***递归中序遍历二叉树***/
void inOrder_LDR(BTree BT) 
{
	if(BT){
		inOrder_LDR(BT->left);    //递归左子树 
		printf("%-4d",BT->data);    //输出节点数据 
		inOrder_LDR(BT->right);   //递归右子树 
	}
}

/***递归后序遍历二叉树***/
void postOrder_LRD(BTree BT) 
{
	if(BT){
		postOrder_LRD(BT->left);    //递归左子树 
		postOrder_LRD(BT->right);   //递归右子树 
		printf("%-4d",BT->data);    //输出节点数据 
	}
}

/***非递归先序遍历二叉树***/
void NoRecursionPreOrderTraverse_DLR(BTree T)
{
	StackNode S;       //创建栈 
	BTree P=T;         //将树指针赋给p 
	InitStack(S);
	while(P||!StackEmpty(S)){
		while(P){
			printf("%-4d",P->data);    //输出节点数据 
			push(S,P,'L');       //将P入栈S 
			P=P->left;           //p指针指向左子树 
		}
		P=S.next->nodePtr;       //将p指针指向栈s的nodePtr 
		pop(S);                 //S的顶点元素出栈 
		P=P->right;            //将P指向P的右子树 
	}
}

/***非递归中序遍历二叉树***/
void NoRecursionInOrderTraverse_LDR(BTree T)
{
	StackNode S;       //创建栈 
	BTree P=T;         //将树指针赋给p 
	InitStack(S);
	while(P||!StackEmpty(S)){
		while(P){
			
			push(S,P,'L');        //将P入栈S 
			P=P->left;           //p指针指向左子树 
		}
		P=S.next->nodePtr;       //将p指针指向栈s的nodePtr 
		printf("%-4d",P->data);    //输出节点数据 
		pop(S);                 //S的顶点元素出栈 
		P=P->right;            //将P指向P的右子树 
	}
}

/***非递归后序遍历二叉树***/
void NoRecursionPostOrderTraverse_LRD(BTree T)
{
	StackNode S;       //创建栈 
	BTree P=T;         //将树指针赋给p 
	InitStack(S);
	while(T){
		push(S,T,'L');        //将左孩子树入栈
		T = T->left;
	}	 
	while(!StackEmpty(S)){
			P=S.next->nodePtr;
			if(!P->right||S.next->child=='R'){
				printf("%-4d",P->data);    //输出节点数据
				pop(S);                 //S的顶点元素出栈 
				T=P;
			}else{
				T=P;
				P=P->right;            //将P指向P的右子树
				S.next->child='R';
			}
			while(P!=T&&P){
				push(S,P,'L');        //将P入栈S 
				P=P->left;           //p指针指向左子树 
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
    cout<<"二叉树这里"; 
    printf("%d",T->data);  //显示结点数据，可以更改为其他对结点操作
    PreOderTraverse(T->left);   //先遍历左子树
    PreOderTraverse(T->right);    //最后遍历右子树 
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

/***计算叶子节点数***/
int Leave(BTree BT)
{
	int ll,lr;
	if(!BT)return 0;
	if(!BT->left&&!BT->right)
		return 1; //判断是否为一个节点的树 
	ll=Leave(BT->left);       //递归左树 
	lr=Leave(BT->right);	  //递归右树 
	return ll+lr; 
} 
 
/***计算树的深度***/
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
	cout<<"先序输入二叉树："<<endl;
	CreateBTree(T);
	cout<<"先序递归遍历二叉树："<<endl;
	preOrder_DLR(T);
	cout<<endl;
	cout<<"中序递归遍历二叉树："<<endl;
	inOrder_LDR(T);
	cout<<endl;
	cout<<"后序递归遍历二叉树："<<endl;
	postOrder_LRD(T);
	cout<<endl;
	cout<<"先序非递归遍历二叉树："<<endl;
	NoRecursionPreOrderTraverse_DLR(T);
	cout<<endl;
	cout<<"中序非递归遍历二叉树："<<endl;
	NoRecursionInOrderTraverse_LDR(T);
	cout<<endl;
	cout<<"后序非递归遍历二叉树："<<endl;
	NoRecursionPostOrderTraverse_LRD(T);
	cout<<endl;
	cout<<"该二叉树的叶子结点数为："<<endl;
	cout<<Leave(T)<<endl;
	cout<<endl;
	cout<<"该二叉树的深度为："<<endl;
	cout<<BTreeDepth(T)<<endl;
	return 0;
}
