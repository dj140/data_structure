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
	ofstream outf;                        //定义ofstream类(输出文件流类)对象outfile
	outf.open("ScoresAnalysis.txt");     //使文件流与ScoresAnalysis.txt文件建立关联
	for(int i=0;i<=15;i++)
    {
    	getline (in, line);           //接受一个字符串
    	istringstream is(line);      //从string对象str中读取字符
	    is>>c[i].name>>c[i].analysis>>c[i].algebra>>c[i].analGeo;  //变量赋值 
	    c[i].Average=(c[i].analysis+c[i].algebra+c[i].analGeo)/3;   //计算平均值 
	    if(i==0){
	    	outf<<line<<"	"<<"平均成绩"<<endl;              //第一行 
		}else{
	    outf<<line<<"	        "<<c[i].Average<<endl;       //学生平均成绩 
	    analysis_sum+=c[i].analysis;
	    algebra_sum+=c[i].algebra;
	    Average_sum+=c[i].analGeo;
		}
		
	}
	outf<<"平均"<<"    "<<analysis_sum/15<<"		"<<algebra_sum/15<<"		"<<""<<Average_sum/15;   //科目平均成绩 
	outf.close();          //关闭文件 
	
	//读入ScoresAnalysis.txt
	fp=fopen("ScoresAnalysis.txt","rt");  //打开文本 
	ch=fgetc(fp);     //读取文本中第一个字符 
	
    while (ch!=EOF)
      {
      putchar(ch);		//打印字符到屏幕上
      ch=fgetc(fp);     //指针变量加一 
      }
      fclose(fp);       //关闭文件 
	return 0;
}

