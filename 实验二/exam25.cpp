#include<stdlib.h>  
#include<string.h>  
#define Addsize 5  


#include <fstream>  
#include <string>   
#include <sstream>
#include<stdlib.h>  
#include<string.h>
using namespace std; 
typedef struct{  
    /*定义结点结构体*/   
    char name[10];  
    int analysis;  
    int algebra;  
    int anaGeo;  
}student;  
typedef struct{  
    /*定义顺序表结构体*/  
    //这个结构体包含一个顺序表所具有的三个基本信息;   
    student *elem;//顺序表的首地址;   
    int length;//顺序表的有效数据长度;  
    int listsize;//顺序表所占系统分配的内存空间;   
}gradeList;  
  
void Initlist(gradeList&L);  
void file_to_stu(FILE*fp,student*stu);  
void Add(gradeList&L,student stu);  
void show_all(gradeList &L);  
void search_stu(gradeList&L,char *info);  
void search_num(gradeList&L,int num);  
void delete_stu(gradeList&L,char *info);  
int  Insert(gradeList&L,student stu,int e);  
  
int main(){  
    gradeList L;//定义一个顺序表变量L;  
    Initlist(L);//初始化L;   
    student stu[14];//定义一个学生结构体数组stu;   
    char info[10];  
    FILE *fp;   
    file_to_stu(fp,stu);  
    for(int i=0;i<14;i++){  
        //将结构体数组stu中的14个学生信息加到顺序表L中;   
        Add(L,stu[i]);  
    }  
    //题目2:向 gradeList中插入如下记录:"张兰, 85,77,92"此记录插入7条记录上  
    student stu1={"王平",92,83,79};  
    Insert(L,stu1,2);
    student stu2={"张兰",85,77,92};  
    Insert(L,stu2,7);
	student stu3={"冯文成",77,68,80};  
    Insert(L,stu3,17); 
    //题目3:搜寻 gradeList，找到第12条记录  
	search_num(L,2);   
    search_num(L,12); 
	search_num(L,17);   
    //题目4:搜寻 gradeList，找到"令狐冲"的所有成绩。  
    strcpy(info,"令狐冲");  
    search_stu(L,info);  
    //题目5:删除 gradeList 中 "岳不群"的成绩记录   
    strcpy(info,"岳不群");  
    delete_stu(L,info);  
    show_all(L);  
    return 0;  
}  
void Initlist(gradeList&L){//init既是initialize(初始化)的缩写词;   
    /*初始化顺序表L*/  
    L.elem=(student*)malloc(20*sizeof(student));  
    if(!L.elem)exit(1);//判断是否初始化成功;   
    L.length=0;//因为初始化的顺序表无有效数据故为0;   
    L.listsize=20;//此时顺序表L所占系统分配内存为20(个student结构体);  
}  
void Add (gradeList&L,student stu){  
    /*这个函数实现将一个学生结构体加到顺序表的最尾端 
       是为了实现一开始将14个学生信息加到顺序表而用的*/   
    L.length++;//每次增加一个学生信息，顺序表L的有效数据长度就加一;  
    L.elem[L.length-1]=stu;//让顺序表L的最后一个位置加上要等于增加的学生结构体;  
}  
int Insert (gradeList&L,student stu,int e){  
    /*实现在顺序表的e位置插入学生结构体stu的功能，参考书里22页的代码*/   
    student *newbase;//用于指向新的分配内存的指针;  
    student *p=NULL,*q=NULL;  
      
    if(L.length+1<e||e<1){  
        /*防止用户输入的位置超出顺序表L的有效空间*/   
        printf("插入序号越出顺序表！！！");  
        return 0;  
    }  
    if(L.length>=L.listsize){  
        //当前分配的空间不够用，增加分配;   
        newbase=(student*)realloc(L.elem,(L.listsize+Addsize)*sizeof(student));  
        if(!newbase){  
        printf("分配新空间失败！");   
        exit(1);  
        }  
        L.elem=newbase;//让原来顺序表L的成员指针指向新分配的空间；   
        L.listsize+=Addsize; //顺序表L的占用分配空间要记得加上新增的空间;  
    }  
    q=&(L.elem[e-1]);//让指针q先指向所要插入的位置地址;   
    for(p=&(L.elem[L.length-1]);p>=q;--p){  
        //从最后一个结构体依次往后退到第e-1个位置为止;   
        *(p+1)=*p;  
    }  
    *q=stu;//让刚刚指向第e个为止的指针q的元素值等于stu   
    L.length++;//因为插入一个新的结构体，所以有效长度要加一；   
    return 1;  
}  
void show_all(gradeList &L){  
    /*将顺序表L的所有有效数据打印在屏幕上*/  
    for(int i=0;i<L.length;i++){  
        printf("%s\t",L.elem[i].name);  
        printf("%d\t",L.elem[i].analysis);  
        printf("%d\t",L.elem[i].algebra);  
        printf("%d\n",L.elem[i].anaGeo);  
    }  
}  
void search_stu(gradeList&L,char *info){  
    /*在顺序表L里查找姓名为info的结构体，并将信息打印在屏幕上*/  
    for(int i=0;i<L.length;i++){  
        if(!strcmp(L.elem[i].name,info))  
        {//如果在顺序表L找到和info同名的结构体则进入循环;  
         //将该学生结构体的信息打印在屏幕上;  
            printf("你所要搜索的信息如下:\n");  
            printf("%s\t",L.elem[i].name);  
            printf("%d\t",L.elem[i].analysis);  
            printf("%d\t",L.elem[i].algebra);  
            printf("%d\n\n",L.elem[i].anaGeo);break;  
        }  
    }  
}  
void search_num(gradeList&L,int num){  
    /*在顺序表L里查找第num个的结构体，并将信息打印在屏幕上*/  
    for(int i=0;i<L.length;i++){  
        if(i==num-1){  
            printf("你所要搜索的信息如下:\n");  
            printf("%s\t",L.elem[i].name);  
            printf("%d\t",L.elem[i].analysis);  
            printf("%d\t",L.elem[i].algebra);  
            printf("%d\n\n",L.elem[i].anaGeo);break;  
        }  
    }  
}  
void file_to_stu(FILE*fp,student*stu){  
    if((fp=fopen("Scores.txt","rt"))==NULL){  
    //检测文件打开是否正常并打开文件。  
        printf("open error!");  
        exit(1);  
    }  
    for(int i=0;i<14;i++){  
    //将文件“scores.txt”里面的14个学生信息弄到结构体数组stu中;   
    fscanf(fp,"%s%d%d%d",&stu[i].name,&stu[i].analysis,&stu[i].algebra,&stu[i].anaGeo);  
          
    }  
}  
void delete_stu(gradeList&L,char *info){  
    /*在顺序表L里查找姓名为info的结构体，并将该结构体删除*/  
    for(int i=0;i<L.length;i++){  
        if(!strcmp(L.elem[i].name,info)){  
            //如果在顺序表L找到和info同名的结构体则进入循环;  
            for(int j=i;j<L.length;j++){  
                L.elem[j]=L.elem[j+1];  
            }break;  
        }  
    }L.length--;//因为删除了一个数据，所以有效数据要减一;  
}  
