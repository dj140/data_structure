#include <string.h>
#include <iostream>
#define MAX_LEN 100
using namespace std;


//����˳��
typedef struct newstr{
	char str[MAX_LEN];
	int str_len;
}Sstring;
//����ֵ 
Sstring assign(Sstring s,char t[]){
	int i;
    for(i=0;t[i]!='\0';i++)
    {
        s.str[i]=t[i];
    }
    s.str_len=i;
    return s;
}
int test(int a,int b){
	int c;
	c=a+b;
}
//��ȡ������
int strLength(Sstring s){
	return s.str_len;
} 
//������
Sstring concat(Sstring s,Sstring t)
{
	int i;
    Sstring str;
    str.str_len=s.str_len+t.str_len;  //���Ӻ�ĳ��� 
    for(i=0;i<s.str_len;i++)
    {
        str.str[i]=s.str[i];
    }
    for(i=0;i<t.str_len;i++)
    {
        str.str[i+s.str_len]=t.str[i];
    }
    return str;
}
//���Ӵ�
Sstring subStr(Sstring s,int k,int len)
{
	Sstring str;
    int i;
    str.str_len=0;
    if(k<0||k>s.str_len||k+len-1>s.str_len)
    {
        return str;     
    }
    for(i=0;i<len;i++)
    {
        str.str[i]=s.str[k+i-1];
    }
    str.str_len=len;
    return str;
 } 
//�����ַ��� 
Sstring insStr(Sstring s,int i,char *t)
{
	int len,j,p,k;
	if (i<1 || i>s.str_len) printf("cannot insert!");
    len=strlen(t);
    
    for (j=0; j<len; j++) {
       p=i+j;
       for (k=0; k<s.str_len -p +1; k++){
          s.str[s.str_len-k]=s.str[s.str_len -k-1];
       }
       s.str[i+j-1] = *(t+j);
       s.str_len++;
    }  
    return s;
}
//��ɾ��
Sstring delStr(Sstring s,int i,int j)
{
	int l,k;
	l=strLength(s);
	if (i<1 || i>s.str_len) printf("cannot insert!");
    for (l=0; l<j; l++) {
       for (k=0; i+k<s.str_len ; k++){
          s.str[i-1+k]=s.str[i+k];
       } 
       s.str_len--;
    } 
    return s;
 }
//��ʾ��
int dispStr(Sstring s){
	int i=0;
    if(s.str_len>0)
    {
        for(i=0;i<s.str_len;i++)
        {
            printf("%c",s.str[i]);
        }
        printf("\n");
    }
} 
int main(){
	Sstring s,string1,string2,string3;
	char t[100]="Hello everyone, ";
	char t2[100]="I love you! ";
	//����ֵ 
	string1 = assign(s,t);
	string2 = assign(s,t2);
	//������  
	string3 = concat(string1,string2);
	//��ʾ�� 
	dispStr(string3);
	printf("\n");
	//������ 
	printf("The length of string3 is:%d \n\n",strLength(string3));
	//�ҳ�˳��
	printf("string3��7���ַ���ʼ������5���ַ��� %s \n\n",subStr(string3,7,5));
	printf("string3��19���ַ���ʼ������4���ַ��� %s \n\n",subStr(string3,19,4));
	//��ɾ��
	string3 = delStr(string3,7,8);
	//������
	char t3[100]="Data Structure";
	string3 = insStr(string3,7,t3);
	dispStr(string3);  //��ʾ�� 
	printf("The length of string3 is:%d \n\n",strLength(string3));
	return 0;
}
