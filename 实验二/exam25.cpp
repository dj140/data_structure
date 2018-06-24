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
    /*������ṹ��*/   
    char name[10];  
    int analysis;  
    int algebra;  
    int anaGeo;  
}student;  
typedef struct{  
    /*����˳���ṹ��*/  
    //����ṹ�����һ��˳��������е�����������Ϣ;   
    student *elem;//˳�����׵�ַ;   
    int length;//˳������Ч���ݳ���;  
    int listsize;//˳�����ռϵͳ������ڴ�ռ�;   
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
    gradeList L;//����һ��˳������L;  
    Initlist(L);//��ʼ��L;   
    student stu[14];//����һ��ѧ���ṹ������stu;   
    char info[10];  
    FILE *fp;   
    file_to_stu(fp,stu);  
    for(int i=0;i<14;i++){  
        //���ṹ������stu�е�14��ѧ����Ϣ�ӵ�˳���L��;   
        Add(L,stu[i]);  
    }  
    //��Ŀ2:�� gradeList�в������¼�¼:"����, 85,77,92"�˼�¼����7����¼��  
    student stu1={"��ƽ",92,83,79};  
    Insert(L,stu1,2);
    student stu2={"����",85,77,92};  
    Insert(L,stu2,7);
	student stu3={"���ĳ�",77,68,80};  
    Insert(L,stu3,17); 
    //��Ŀ3:��Ѱ gradeList���ҵ���12����¼  
	search_num(L,2);   
    search_num(L,12); 
	search_num(L,17);   
    //��Ŀ4:��Ѱ gradeList���ҵ�"�����"�����гɼ���  
    strcpy(info,"�����");  
    search_stu(L,info);  
    //��Ŀ5:ɾ�� gradeList �� "����Ⱥ"�ĳɼ���¼   
    strcpy(info,"����Ⱥ");  
    delete_stu(L,info);  
    show_all(L);  
    return 0;  
}  
void Initlist(gradeList&L){//init����initialize(��ʼ��)����д��;   
    /*��ʼ��˳���L*/  
    L.elem=(student*)malloc(20*sizeof(student));  
    if(!L.elem)exit(1);//�ж��Ƿ��ʼ���ɹ�;   
    L.length=0;//��Ϊ��ʼ����˳�������Ч���ݹ�Ϊ0;   
    L.listsize=20;//��ʱ˳���L��ռϵͳ�����ڴ�Ϊ20(��student�ṹ��);  
}  
void Add (gradeList&L,student stu){  
    /*�������ʵ�ֽ�һ��ѧ���ṹ��ӵ�˳������β�� 
       ��Ϊ��ʵ��һ��ʼ��14��ѧ����Ϣ�ӵ�˳�����õ�*/   
    L.length++;//ÿ������һ��ѧ����Ϣ��˳���L����Ч���ݳ��Ⱦͼ�һ;  
    L.elem[L.length-1]=stu;//��˳���L�����һ��λ�ü���Ҫ�������ӵ�ѧ���ṹ��;  
}  
int Insert (gradeList&L,student stu,int e){  
    /*ʵ����˳����eλ�ò���ѧ���ṹ��stu�Ĺ��ܣ��ο�����22ҳ�Ĵ���*/   
    student *newbase;//����ָ���µķ����ڴ��ָ��;  
    student *p=NULL,*q=NULL;  
      
    if(L.length+1<e||e<1){  
        /*��ֹ�û������λ�ó���˳���L����Ч�ռ�*/   
        printf("�������Խ��˳�������");  
        return 0;  
    }  
    if(L.length>=L.listsize){  
        //��ǰ����Ŀռ䲻���ã����ӷ���;   
        newbase=(student*)realloc(L.elem,(L.listsize+Addsize)*sizeof(student));  
        if(!newbase){  
        printf("�����¿ռ�ʧ�ܣ�");   
        exit(1);  
        }  
        L.elem=newbase;//��ԭ��˳���L�ĳ�Աָ��ָ���·���Ŀռ䣻   
        L.listsize+=Addsize; //˳���L��ռ�÷���ռ�Ҫ�ǵü��������Ŀռ�;  
    }  
    q=&(L.elem[e-1]);//��ָ��q��ָ����Ҫ�����λ�õ�ַ;   
    for(p=&(L.elem[L.length-1]);p>=q;--p){  
        //�����һ���ṹ�����������˵���e-1��λ��Ϊֹ;   
        *(p+1)=*p;  
    }  
    *q=stu;//�øո�ָ���e��Ϊֹ��ָ��q��Ԫ��ֵ����stu   
    L.length++;//��Ϊ����һ���µĽṹ�壬������Ч����Ҫ��һ��   
    return 1;  
}  
void show_all(gradeList &L){  
    /*��˳���L��������Ч���ݴ�ӡ����Ļ��*/  
    for(int i=0;i<L.length;i++){  
        printf("%s\t",L.elem[i].name);  
        printf("%d\t",L.elem[i].analysis);  
        printf("%d\t",L.elem[i].algebra);  
        printf("%d\n",L.elem[i].anaGeo);  
    }  
}  
void search_stu(gradeList&L,char *info){  
    /*��˳���L���������Ϊinfo�Ľṹ�壬������Ϣ��ӡ����Ļ��*/  
    for(int i=0;i<L.length;i++){  
        if(!strcmp(L.elem[i].name,info))  
        {//�����˳���L�ҵ���infoͬ���Ľṹ�������ѭ��;  
         //����ѧ���ṹ�����Ϣ��ӡ����Ļ��;  
            printf("����Ҫ��������Ϣ����:\n");  
            printf("%s\t",L.elem[i].name);  
            printf("%d\t",L.elem[i].analysis);  
            printf("%d\t",L.elem[i].algebra);  
            printf("%d\n\n",L.elem[i].anaGeo);break;  
        }  
    }  
}  
void search_num(gradeList&L,int num){  
    /*��˳���L����ҵ�num���Ľṹ�壬������Ϣ��ӡ����Ļ��*/  
    for(int i=0;i<L.length;i++){  
        if(i==num-1){  
            printf("����Ҫ��������Ϣ����:\n");  
            printf("%s\t",L.elem[i].name);  
            printf("%d\t",L.elem[i].analysis);  
            printf("%d\t",L.elem[i].algebra);  
            printf("%d\n\n",L.elem[i].anaGeo);break;  
        }  
    }  
}  
void file_to_stu(FILE*fp,student*stu){  
    if((fp=fopen("Scores.txt","rt"))==NULL){  
    //����ļ����Ƿ����������ļ���  
        printf("open error!");  
        exit(1);  
    }  
    for(int i=0;i<14;i++){  
    //���ļ���scores.txt�������14��ѧ����ϢŪ���ṹ������stu��;   
    fscanf(fp,"%s%d%d%d",&stu[i].name,&stu[i].analysis,&stu[i].algebra,&stu[i].anaGeo);  
          
    }  
}  
void delete_stu(gradeList&L,char *info){  
    /*��˳���L���������Ϊinfo�Ľṹ�壬�����ýṹ��ɾ��*/  
    for(int i=0;i<L.length;i++){  
        if(!strcmp(L.elem[i].name,info)){  
            //�����˳���L�ҵ���infoͬ���Ľṹ�������ѭ��;  
            for(int j=i;j<L.length;j++){  
                L.elem[j]=L.elem[j+1];  
            }break;  
        }  
    }L.length--;//��Ϊɾ����һ�����ݣ�������Ч����Ҫ��һ;  
}  
