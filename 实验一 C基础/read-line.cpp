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
    if(in) // �и��ļ�  
    {  
    /*
        while (getline (in, line)) // line�в�����ÿ�еĻ��з�  
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
    else // û�и��ļ�  
    {  
        cout <<"no such file" << endl;  
    }  
    system("pause");
    //return 0;  
}  
