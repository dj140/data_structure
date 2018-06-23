#include <fstream>  
#include <string>  
#include <iostream>  
#include <sstream>
using namespace std;  
  
int main()  
{  
    ifstream in("scores.txt");  
    string filename;  
    string line;  
    string stdr;
	char  name[50];
   int  analysis;
   int  algebra;
   int  analGeo;
   int  Average;
    int i;
    if(in) // 有该文件  
    {  
    /*
        while (getline (in, line)) // line中不包括每行的换行符  
        {   
        	cout<<in;
            cout << line << endl; 
        } 
    */
    for(i=0;i<3;i++)
    {
    	if(i==0) getline (in, line);
    	getline (in, line);
    	istringstream is(line);
	    is>>name>>analysis>>algebra;
	    cout<<name<<","<<analysis<<","<<algebra<<endl;
    	cout << line << endl; 
	}
    }  
    else // 没有该文件  
    {  
        cout <<"no such file" << endl;  
    }  
    system("pause");
    //return 0;  
}  
