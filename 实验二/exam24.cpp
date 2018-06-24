#include<fstream>  
#include<stdlib.h>  
#include <iostream> 
#include <iomanip>
using namespace std;  
/*����ṹ����*/  
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
    //��1���ҵ�LC��Ԫ��65��λ�ò���ʾ����Ļ��  
    view_location(LC,65);  
    //��2��ɾ��LC�е�����ֵ��82,73,64,29;  
    delete_num(LC,82);  
    delete_num(LC,73);  
    delete_num(LC,64);  
    delete_num(LC,29);  
    //��3����ʾ��һ��������ɺ�LC�����ݡ�  
    cout<<"ɾ��LC�е�����ֵ��82,73,64,29"<<endl;
    cout<<"LC: ";
    view_list(LC); 
	cout<<endl<<endl; 
    //��4������LC�в�����55��43��Ȼ����Ļ��ʾLC���������ݡ�  
    Insert(LC,55);  
    Insert(LC,43);  
    cout<<"��LC�в�����55��43"<<endl;
    cout<<"LC: ";
    view_list(LC);  
    return 0;  
}  
Data *CreatL(int*a,int size){
    /*��ʼ���������a*/
    Data*head=(Data*)malloc(sizeof(Data));  //����ռ� 
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
	/*�鿴��������*/  
    Data*p=L;  
    while(p->next){  
        p=p->next;  
        cout<<p->num<<setw(3);    
    }  
}  
void view_length(Data*L){
	/*���������*/ 
    Data*p=L;  
    int i=0;  
    while(p->next){  
        p=p->next;  
        i++;      
    }  
    cout<<"The length of the list is "<<i<<endl;  
}  
int output_length(Data*L){  
	/*����������*/ 
    Data*p=L;  
    int i=0;  
    while(p->next){  
        p=p->next;  
        i++;      
    }  
    return i;  
}  
void view_location(Data *L,int a){  
	/*���a�ڵ�����L��λ��*/ 
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
	/*ɾ��L�е�һ�����ֵ�a*/ 
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
	/*�������������*/  
    Data*p=L,*q=p,*ptemp;  
    int i=0;  
    while(p->next){  
        p=p->next;  
        if((p->num)<=a){  
            ptemp=(Data*)malloc(sizeof(Data)); //��ָ�����ptemp����һ�����ݿռ� 
            ptemp->num=a;   //���ڵ�*ptemp����������Ϊa 
            ptemp->next=p;  //���ڵ�*ptemp��ָ����ָ��
            q->next=ptemp;  //���ڵ�*q��ָ����ָ��*ptemp
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
	/*������ϲ�*/ 
    Data *LC=LB;  
    Data *p1=LA->next;  
    Data *p2=p1;  
    while(p2->next){  
        p2=p1;  
        Insert(LB,p1->num);  //��LA�������򸳸�LB 
        p1=p1->next;  
    }  
    return LC;  
}
