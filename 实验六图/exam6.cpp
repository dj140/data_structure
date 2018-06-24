#include<stdlib.h>
#include <iostream>
#include<string>
#define MaxInt 32767
#define MVNum 100
#define MAX_VERTEX_NUM 20
#define ERROR 1
typedef char InfoType;
typedef char VerTexType;
typedef int ArcType;
typedef int OhterInfo;
typedef int Status;
bool visited[MVNum];
using namespace std;
/***邻接矩阵存储结构***/
typedef struct
{
	VerTexType vexs[MVNum];
	ArcType arcs[MVNum][MVNum];
	int vexnum,arcnum;
}AMGraph;


/***邻接表存储结构***/
typedef struct ArcNode                 //边结点
{
    int adjvex;                        //改变所指向的顶点的位置
    struct ArcNode *nextarc;           //指向下一条边的指针
    string info;                       //和边相关的信息
}ArcNode;
typedef struct VNode                   //顶点信息
{                 
    VerTexType data;                   
    ArcNode *firstarc;                 //指向第一条依附该顶点的边的指针
}VNode, AdjList[MVNum];                //AdList表示邻接表类型
typedef struct                         //邻接表
{
    AdjList vertices; 
    int vexnum, arcnum;                //图的当前顶点数和边数
}ALGraph;


/***十字链表储存结构***/
typedef struct ArcBox
{
    int tailvex, headvex;              //该弧的尾和头顶点的位置
    struct ArcBox *hlink, *tlink;      //分别为弧头相同和弧尾相同的弧的链域
    InfoType *info;                    //改弧相关信息的指针
}ArcBox;
typedef struct
{
    char data;
    ArcBox *firstin, *firstout;        //分别指向该顶点第一条入弧和出弧
}VexNode;
typedef struct
{
    VexNode xlist[MAX_VERTEX_NUM];     //表头向量
    int vexnum, arcnum;                //有向图的当前顶点数和弧数
}OLGraph;





int createGraphByAdjMatrix(AMGraph &G);
int createGraphByAdjList(ALGraph &G);
int createGraphByOrthLkList(OLGraph &G);
int coutAMGraph(AMGraph &G);
int coutUDG(ALGraph G);
int Display(OLGraph G);

int main()
{
	//邻接矩阵 
	AMGraph MG;
	createGraphByAdjMatrix(MG);
	coutAMGraph(MG);
	cout<<"\n"<<endl;
	//邻接表 
	ALGraph LG;
	createGraphByAdjList(LG);
	coutUDG(LG);
	cout<<"\n"<<endl;
	//十字链表 
	OLGraph KG;
	createGraphByOrthLkList(KG);
	Display(KG);
	return 0;
}


/*****邻接矩阵*****/ 
int createGraphByAdjMatrix(AMGraph &G)
{
	int i, j;
	VerTexType vetices[7]={'A','B','C','D','E','F','G'};
	ArcType arcs[7][7]={MaxInt,7,MaxInt,18,MaxInt,MaxInt,
	MaxInt,MaxInt,MaxInt,2,MaxInt,MaxInt,MaxInt,MaxInt,MaxInt,MaxInt,
	MaxInt,MaxInt,MaxInt,9,MaxInt,MaxInt,MaxInt,MaxInt,
	MaxInt,20,MaxInt,MaxInt,MaxInt,MaxInt,MaxInt,MaxInt,
	MaxInt,MaxInt,MaxInt,MaxInt,MaxInt,MaxInt,3,MaxInt,
	MaxInt,MaxInt,14,MaxInt,6,MaxInt,MaxInt,5,MaxInt
	};
	G.vexnum=7;
	G.arcnum=9;       //输入总顶点数、总边数
	for (i = 0; i < G.vexnum; i++)     //依次输入点的信息
	{
		G.vexs[i]=vetices[i];
	}
	for (i = 0; i < G.vexnum; i++)     //初始化邻接矩阵，编的权值均为极大值MaxInt
		for (j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = arcs[i][j];
	return 0;
}

/***无向网的输出***/
int coutAMGraph(AMGraph &G)           
{
	int i, j;
	cout << "该图的邻接矩阵为：" << endl;
	cout << "\t";
	for (i = 0; i < G.vexnum; i++)
		cout << G.vexs[i] << "\t";
	cout << endl;
	for (i = 0; i < G.vexnum; i++)
	{
		cout << G.vexs[i] << "\t";
		for (j = 0; j < G.vexnum; j++)
		{
			cout << G.arcs[i][j] << "\t";
		}
		cout << endl;
	}
}

/*****邻接表*****/
int LocateVex(ALGraph &G, char &v1)    //定位函数   
{
    int i;
    for (i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].data == v1)
            return i;
    }
    if (i >= G.vexnum)
        return ERROR;
    else
        return 0;
}

/***创建无向图***/
int createGraphByAdjList(ALGraph &G)             
{
    ArcNode *p1, *p2;
    int i, j, k;
    char v1, v2;
    VerTexType vetices[7]={'A','B','C','D','E','F','G'};
	G.vexnum=7;
	G.arcnum=9;       //输入总顶点数、总边数
    for (i = 0; i < G.vexnum; i++)
    {
        G.vertices[i].data=vetices[i];     //输入顶点值
        G.vertices[i].firstarc = NULL; //初始化表头结点的指针域为NULL
    }
    char A[50]={'A','A','B','C','D','F','G','G','G'};
    char B[50]={'B','D','C','F','E','D','A','F','C'};
    for (k = 0; k < G.arcnum; k++)     
    {
        v1=A[k];
		v2=B[k];               //输入各边，构造邻接表
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        p1 = new ArcNode;              //生成一个新结点*p1
        p1->adjvex = j;                //邻接点序号为j
        p1->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p1;
        p2 = new ArcNode;
        p2->adjvex = i;
        p2->nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc = p2;
    }
}

/***输出邻接表***/ 
int coutUDG(ALGraph G)                //输出函数
{
    int i, j;
    cout << "该图邻接表为:" << endl;
    for (i = 0; i<G.vexnum; i++)
    {
        cout << i;
        ArcNode *p;
        p = G.vertices[i].firstarc;
        while (p != NULL)
        {
            cout << "-> " << p->adjvex;
            p = p->nextarc;
        }
        cout << endl;
    }
}

/*****十字链表*****/
int LocateVex(OLGraph G, char v)       //// 返回顶点v在有向图G中的位置(序号),如不存在则返回-1  
{
    for (int u = 0; u<G.vexnum; u++)
        if(G.xlist[u].data == v)
            return u;
    return -1;
}

/***十字链表存储表示*/
int createGraphByOrthLkList(OLGraph &G)              // 采用十字链表存储表示,构造有向图G
{
    int i, j, k;
    int IncInfo;
    ArcBox *p;
    char v1, v2;
    VerTexType vetices[7]={'A','B','C','D','E','F','G'};
	G.vexnum=7;
	G.arcnum=9;       //输入总顶点数、总边数
    for (i = 0; i<G.vexnum; ++i)
    {
        G.xlist[i].data=vetices[i];
        G.xlist[i].firstin = NULL;
        G.xlist[i].firstout = NULL;
    }
    char A[50]={'A','A','B','C','D','F','G','G','G'};
    char B[50]={'B','D','C','F','E','D','A','F','C'};
    for (k = 0; k<G.arcnum; ++k)
    {
    	v1=A[k];
		v2=B[k];               //输入各边
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        p = new ArcBox;
        p->tailvex = i;
        p->headvex = j;
        p->hlink = G.xlist[j].firstin;
        p->tlink = G.xlist[i].firstout;
        G.xlist[j].firstin = G.xlist[i].firstout = p;
    }
}

/***输出有向图***/
int Display(OLGraph G)                
{
    int i;
    ArcBox *p; 
    cout << "该图十字链表为:" << endl;
    cout << "共" << G.vexnum << "个顶点," << G.arcnum << "条弧:" << endl;
    for (i = 0; i<G.vexnum; i++)
    {
        cout << "顶点" << G.xlist[i].data << ": 入度: ";
        p = G.xlist[i].firstin;
        while (p)
        {
            cout << G.xlist[p->tailvex].data<<" ";
            p = p->hlink;
        }
        cout << "出度: ";
        p = G.xlist[i].firstout;
        while (p)
        {
            cout << G.xlist[p->headvex].data<<" ";
            p = p->tlink;
        }
        cout << endl;
    }
} 
