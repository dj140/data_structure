#include<fstream>  
#include<stdlib.h>  
#include <iostream> 
#include <iomanip>
using namespace std;  
/*构造结构体结点*/  
typedef struct data{  
    int num;  
    data*next;  
}Data;  
Data *CreatL(int*a,int size);  
void view_list(Data*L);  
void view_length(Data*L);  
int output_length(Data*L);  
void view_location(Data *L,int a);  
void delete_num(Data*L,int a);  
void Insert(Data*L,int a);  
Data * MergeLists(Data*LA,Data*LB);  
int main(){  
    int a[]={78, 64, 37, 30, 29, 24, 18, 12, 9, 2};  
    int b[]={93, 82, 73, 65, 44, 35, 31, 28, 26, 17, 15};  
    Data*LA=CreatL(a,10);  
    Data*LB=CreatL(b,11);     
    Data*LC=MergeLists(LA,LB);  
    cout<<"LC: ";
    view_list(LC);
    cout<<endl;
    view_length(LC);
    cout<<endl;
    //（1）找到LC中元素65的位置并显示在屏幕上  
    view_location(LC,65);  
    //（2）删除LC中的如下值：82,73,64,29;  
    delete_num(LC,82);  
    delete_num(LC,73);  
    delete_num(LC,64);  
    delete_num(LC,29);  
    //（3）显示上一步操作完成后LC的数据。  
    cout<<"删除LC中的如下值：82,73,64,29"<<endl;
    cout<<"LC: ";
    view_list(LC); 
	cout<<endl<<endl; 
    //（4）再向LC中插入数55，43；然后屏幕显示LC中所有数据。  
    Insert(LC,55);  
    Insert(LC,43);  
    cout<<"向LC中插入数55，43"<<endl;
    cout<<"LC: ";
    view_list(LC);  
    return 0;  
}  
Data *CreatL(int*a,int size){
    /*初始化单链表表a*/
    Data*head=(Data*)malloc(sizeof(Data));  //分配空间 
    head->num=0;  
    head->next=NULL;  
    Data *p=head,*q;  
    q=p;  
    for(int i=0;i<size;i++){  
        p=(Data*)malloc(sizeof(Data));  
        p->num=a[i];  
        q->next=p;  
        q=p;  
    }p->next=NULL;  
    return head;  
}  
  
void view_list(Data*L){
	/*查看链表数据*/  
    Data*p=L;  
    while(p->next){  
        p=p->next;  
        cout<<p->num<<setw(3);    
    }  
}  
void view_length(Data*L){
	/*输出链表长度*/ 
    Data*p=L;  
    int i=0;  
    while(p->next){  
        p=p->next;  
        i++;      
    }  
    cout<<"The length of the list is "<<i<<endl;  
}  
int output_length(Data*L){  
	/*返回链表长度*/ 
    Data*p=L;  
    int i=0;  
    while(p->next){  
        p=p->next;  
        i++;      
    }  
    return i;  
}  
void view_location(Data *L,int a){  
	/*输出a在单链表L的位置*/ 
    Data*p=L;  
    int i=0;  
    while((p->num!=a)&&(p->next!=NULL)){  
        p=p->next;  
        if(p->num==a)  
        cout<<"The location of num:"<<a<<" in the list is "<<i<<" !"<<endl;  
        i++;      
    }  
}  
void delete_num(Data*L,int a){
	/*删除L中第一个出现的a*/ 
    Data*p=L,*q=p;  
    int i=0;  
    while(p->next){  
        p=p->next;  
        if(p->num==a){  
            q->next=p->next;  
            free(p);  
            break;  
        }  
        q=p;  
    }  
    if(!p->next)cout<<"Cannot find num:"<<a<<" to delete!"<<endl;  
}  
void Insert(Data*L,int a){
	/*单链表按降序插入*/  
    Data*p=L,*q=p,*ptemp;  
    int i=0;  
    while(p->next){  
        p=p->next;  
        if((p->num)<=a){  
            ptemp=(Data*)malloc(sizeof(Data)); //给指针变量ptemp分配一个数据空间 
            ptemp->num=a;   //将节点*ptemp的数据域置为a 
            ptemp->next=p;  //将节点*ptemp的指针域指向
            q->next=ptemp;  //将节点*q的指针域指向*ptemp
            break;  
        }  
        q=p;  
        i++;  
    }  
    if(i==output_length(L)){  
        ptemp=(Data*)malloc(sizeof(Data));  
        ptemp->next=NULL;  
        ptemp->num=a;  
        p->next=ptemp;  
    }  
}  
Data * MergeLists(Data*LA,Data*LB){  
	/*单链表合并*/ 
    Data *LC=LB;  
    Data *p1=LA->next;  
    Data *p2=p1;  
    while(p2->next){  
        p2=p1;  
        Insert(LB,p1->num);  //将LA的数据域赋给LB 
        p1=p1->next;  
    }  
    return LC;  
}
