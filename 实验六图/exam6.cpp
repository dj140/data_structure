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
/***�ڽӾ���洢�ṹ***/
typedef struct
{
	VerTexType vexs[MVNum];
	ArcType arcs[MVNum][MVNum];
	int vexnum,arcnum;
}AMGraph;


/***�ڽӱ�洢�ṹ***/
typedef struct ArcNode                 //�߽��
{
    int adjvex;                        //�ı���ָ��Ķ����λ��
    struct ArcNode *nextarc;           //ָ����һ���ߵ�ָ��
    string info;                       //�ͱ���ص���Ϣ
}ArcNode;
typedef struct VNode                   //������Ϣ
{                 
    VerTexType data;                   
    ArcNode *firstarc;                 //ָ���һ�������ö���ıߵ�ָ��
}VNode, AdjList[MVNum];                //AdList��ʾ�ڽӱ�����
typedef struct                         //�ڽӱ�
{
    AdjList vertices; 
    int vexnum, arcnum;                //ͼ�ĵ�ǰ�������ͱ���
}ALGraph;


/***ʮ��������ṹ***/
typedef struct ArcBox
{
    int tailvex, headvex;              //�û���β��ͷ�����λ��
    struct ArcBox *hlink, *tlink;      //�ֱ�Ϊ��ͷ��ͬ�ͻ�β��ͬ�Ļ�������
    InfoType *info;                    //�Ļ������Ϣ��ָ��
}ArcBox;
typedef struct
{
    char data;
    ArcBox *firstin, *firstout;        //�ֱ�ָ��ö����һ���뻡�ͳ���
}VexNode;
typedef struct
{
    VexNode xlist[MAX_VERTEX_NUM];     //��ͷ����
    int vexnum, arcnum;                //����ͼ�ĵ�ǰ�������ͻ���
}OLGraph;





int createGraphByAdjMatrix(AMGraph &G);
int createGraphByAdjList(ALGraph &G);
int createGraphByOrthLkList(OLGraph &G);
int coutAMGraph(AMGraph &G);
int coutUDG(ALGraph G);
int Display(OLGraph G);

int main()
{
	//�ڽӾ��� 
	AMGraph MG;
	createGraphByAdjMatrix(MG);
	coutAMGraph(MG);
	cout<<"\n"<<endl;
	//�ڽӱ� 
	ALGraph LG;
	createGraphByAdjList(LG);
	coutUDG(LG);
	cout<<"\n"<<endl;
	//ʮ������ 
	OLGraph KG;
	createGraphByOrthLkList(KG);
	Display(KG);
	return 0;
}


/*****�ڽӾ���*****/ 
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
	G.arcnum=9;       //�����ܶ��������ܱ���
	for (i = 0; i < G.vexnum; i++)     //������������Ϣ
	{
		G.vexs[i]=vetices[i];
	}
	for (i = 0; i < G.vexnum; i++)     //��ʼ���ڽӾ��󣬱��Ȩֵ��Ϊ����ֵMaxInt
		for (j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = arcs[i][j];
	return 0;
}

/***�����������***/
int coutAMGraph(AMGraph &G)           
{
	int i, j;
	cout << "��ͼ���ڽӾ���Ϊ��" << endl;
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

/*****�ڽӱ�*****/
int LocateVex(ALGraph &G, char &v1)    //��λ����   
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

/***��������ͼ***/
int createGraphByAdjList(ALGraph &G)             
{
    ArcNode *p1, *p2;
    int i, j, k;
    char v1, v2;
    VerTexType vetices[7]={'A','B','C','D','E','F','G'};
	G.vexnum=7;
	G.arcnum=9;       //�����ܶ��������ܱ���
    for (i = 0; i < G.vexnum; i++)
    {
        G.vertices[i].data=vetices[i];     //���붥��ֵ
        G.vertices[i].firstarc = NULL; //��ʼ����ͷ����ָ����ΪNULL
    }
    char A[50]={'A','A','B','C','D','F','G','G','G'};
    char B[50]={'B','D','C','F','E','D','A','F','C'};
    for (k = 0; k < G.arcnum; k++)     
    {
        v1=A[k];
		v2=B[k];               //������ߣ������ڽӱ�
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        p1 = new ArcNode;              //����һ���½��*p1
        p1->adjvex = j;                //�ڽӵ����Ϊj
        p1->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p1;
        p2 = new ArcNode;
        p2->adjvex = i;
        p2->nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc = p2;
    }
}

/***����ڽӱ�***/ 
int coutUDG(ALGraph G)                //�������
{
    int i, j;
    cout << "��ͼ�ڽӱ�Ϊ:" << endl;
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

/*****ʮ������*****/
int LocateVex(OLGraph G, char v)       //// ���ض���v������ͼG�е�λ��(���),�粻�����򷵻�-1  
{
    for (int u = 0; u<G.vexnum; u++)
        if(G.xlist[u].data == v)
            return u;
    return -1;
}

/***ʮ������洢��ʾ*/
int createGraphByOrthLkList(OLGraph &G)              // ����ʮ������洢��ʾ,��������ͼG
{
    int i, j, k;
    int IncInfo;
    ArcBox *p;
    char v1, v2;
    VerTexType vetices[7]={'A','B','C','D','E','F','G'};
	G.vexnum=7;
	G.arcnum=9;       //�����ܶ��������ܱ���
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
		v2=B[k];               //�������
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

/***�������ͼ***/
int Display(OLGraph G)                
{
    int i;
    ArcBox *p; 
    cout << "��ͼʮ������Ϊ:" << endl;
    cout << "��" << G.vexnum << "������," << G.arcnum << "����:" << endl;
    for (i = 0; i<G.vexnum; i++)
    {
        cout << "����" << G.xlist[i].data << ": ���: ";
        p = G.xlist[i].firstin;
        while (p)
        {
            cout << G.xlist[p->tailvex].data<<" ";
            p = p->hlink;
        }
        cout << "����: ";
        p = G.xlist[i].firstout;
        while (p)
        {
            cout << G.xlist[p->headvex].data<<" ";
            p = p->tlink;
        }
        cout << endl;
    }
} 
