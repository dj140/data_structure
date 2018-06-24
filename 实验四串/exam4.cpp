#include <string.h>
#include <iostream>
#define MAX_LEN 100
using namespace std;


//定义顺序串
typedef struct newstr{
	char str[MAX_LEN];
	int str_len;
}Sstring;
//串赋值 
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
//获取串长度
int strLength(Sstring s){
	return s.str_len;
} 
//串连接
Sstring concat(Sstring s,Sstring t)
{
	int i;
    Sstring str;
    str.str_len=s.str_len+t.str_len;  //连接后的长度 
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
//求子串
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
//插入字符串 
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
//串删除
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
//显示串
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
	//串赋值 
	string1 = assign(s,t);
	string2 = assign(s,t2);
	//串连接  
	string3 = concat(string1,string2);
	//显示串 
	dispStr(string3);
	printf("\n");
	//串长度 
	printf("The length of string3 is:%d \n\n",strLength(string3));
	//找出顺序串
	printf("string3第7个字符开始的连续5个字符是 %s \n\n",subStr(string3,7,5));
	printf("string3第19个字符开始的连续4个字符是 %s \n\n",subStr(string3,19,4));
	//串删除
	string3 = delStr(string3,7,8);
	//串插入
	char t3[100]="Data Structure";
	string3 = insStr(string3,7,t3);
	dispStr(string3);  //显示串 
	printf("The length of string3 is:%d \n\n",strLength(string3));
	return 0;
}
