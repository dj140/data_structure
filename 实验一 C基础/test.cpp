#include <fstream>  
#include <string>  
#include <iostream>  
#include <sstream>
#define N 10
using namespace std; 
struct studentInfo
{
   	char  name[50];
   	int  analysis;
   	int  algebra;
   	int  analGeo;
   	int  Average;	
} c[N];
int main()
{
	int i;
	int analysis_sum=0;
	int algebra_sum=0;
	int Average_sum=0;
   	string line;  
    string stdr;
    string writ;
    FILE *fp;
    char ch;
	ifstream in("Scores.txt"); 
	ofstream outf;                        //����ofstream��(����ļ�����)����outfile
	outf.open("ScoresAnalysis.txt");     //ʹ�ļ�����ScoresAnalysis.txt�ļ���������
	for(int i=0;i<=15;i++)
    {
    	getline (in, line);           //����һ���ַ���
    	istringstream is(line);      //��string����str�ж�ȡ�ַ�
	    is>>c[i].name>>c[i].analysis>>c[i].algebra>>c[i].analGeo;  //������ֵ 
	    c[i].Average=(c[i].analysis+c[i].algebra+c[i].analGeo)/3;   //����ƽ��ֵ 
	    if(i==0){
	    	outf<<line<<"	"<<"ƽ���ɼ�"<<endl;              //��һ�� 
		}else{
	    outf<<line<<"	        "<<c[i].Average<<endl;       //ѧ��ƽ���ɼ� 
	    analysis_sum+=c[i].analysis;
	    algebra_sum+=c[i].algebra;
	    Average_sum+=c[i].analGeo;
		}
		
	}
	outf<<"ƽ��"<<"    "<<analysis_sum/15<<"		"<<algebra_sum/15<<"		"<<""<<Average_sum/15;   //��Ŀƽ���ɼ� 
	outf.close();          //�ر��ļ� 
	
	//����ScoresAnalysis.txt
	fp=fopen("ScoresAnalysis.txt","rt");  //���ı� 
	ch=fgetc(fp);     //��ȡ�ı��е�һ���ַ� 
	
    while (ch!=EOF)
      {
      putchar(ch);		//��ӡ�ַ�����Ļ��
      ch=fgetc(fp);     //ָ�������һ 
      }
      fclose(fp);       //�ر��ļ� 
	return 0;
}

