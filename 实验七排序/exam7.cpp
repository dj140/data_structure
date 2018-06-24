#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#define MAXSIZE 100
using namespace std;
int m=0,n=0;

int dispArray(int a[], int len)
{
	//��ʾ��������len������a[];
	for(int i=0;i<len;i++)
	{
		cout<<a[i]<<"   ";
	}
}


/***ֱ�Ӳ�������***/ 
int InsertSort(int a[],int len)
{
	int j,key;
	int b[100];
	for(int k=0;k<len;k++)
	{
		b[k]=a[k];
	}
	//dispArray(b,15);
	for(int i=0;i<len;i++)
	{
		key=b[i];
		for(j=i-1;j>=0;j--){
			if(b[j]>key)
			{
			b[j+1]=b[j];
			}else
			break;
		}
		b[j+1]=key;
	}
	dispArray(b,15);
}


/***ϣ������***/
void ShellSort(int a[],int len)  
{  
    int step;  
    int i,j;  
    int temp; 
	int b[100];
	for(int k=0;k<len;k++)
	{
		b[k]=a[k];
	}
    for(step=len/2; step>0;step/=2) //�������Ʋ���,���ݼ���1  
    {  
        // i�ӵ�step��ʼ���У�ӦΪ��������ĵ�һ��Ԫ��  
        // �����Ȳ������ӵڶ�����ʼ����  
        for(i=step;i<len;i++)  
        {  
            temp = b[i];  
            for(j=i-step;(j>=0 && temp > b[j]);j-=step)  
            {  
                b[j+step] = b[j];  
            }  
            b[j+step] = temp; //����һ��λ������  
        }  
    }  
    dispArray(b,15);
}  

int BubbleSort(int a[],int len)  
{  
    //ð������  
    int i,j;  
    int t;  
    int b[100];
	for(int k=0;k<len;k++)
	{
		b[k]=a[k];
	}
    for(i=0;i<len-1;i++)//n�����������ܹ�ɨ��n-1��  
    {  
        for(j=0;j<len-i-1;j++)//ÿһ��ɨ�赽a[n-i-2]��a[n-i-1]�Ƚ�Ϊֹ����  
        {  
            if(b[j]>b[j+1])//��һλ����ǰһλ��С�Ļ����ͽ�����������λ�ã�����  
            {  
               t=b[j+1];  
               b[j+1]=b[j];  
               b[j]=t;  
            }  
        }  
    }
    dispArray(b,15);
} 

/***��������***/ 
int QuickSort(int b[],int len){  
    int i = 0;  
    int j = len - 1;  
    int k = b[0];  
    if (len>1) {//�ظ����ж��������������С��2����������  
        while (i != j) {  
            for (; i<j; j--) {  
                m++;  
                if (b[j]>k) {  
                    b[i] = b[j];  
                    n++;
                    break; 
                }  
            }  
            for (; i<j; i++) {  
                m++;  
                if (b[i]<k) {  
                    b[j] = b[i];  
                    n++;
                    break;  
                }  
            }  
            b[i] = k;  
        }  
          
        QuickSort(b, i);  
        QuickSort(b+i+1, len-i-1);  
    }
}

/***������***/ 
int HeapAdjust(int b[], int i, int length)  
{  
    int Child;  
    int temp;  
    for(;2 * i + 1 < length; i = Child)  
    {  
        //�ӽڵ��λ�� = 2 * (parent(�����)) + 1  
        Child = 2 * i + 1;  
        //�õ��ӽ���нϴ�Ľ��  
        if(Child < length - 1 && b[Child + 1] > b[Child])  
                ++Child;  
        //����ϴ���ӽ����ڸ������ô�ѽϴ���ӽ�������ƶ�  
        //�滻���ĸ����  
        if(b[i] < b[Child])  
        {  
            temp = b[i];  
            b[i] = b[Child];  
            b[Child] = temp;  
        }  
        else  
                break;  
    }  
}  
//�������㷨  
int HeapSort(int a[], int length)  
{  
	int b[100];
	for(int k=0;k<15;k++)
	{
		b[k]=a[k];
	}
    int i;  
    //�������е�ǰ�벿��Ԫ�أ�������֮���һ��Ԫ��  
    //�����е����Ԫ�أ�length/2-1�����һ����Ҷ�ӽ��  
    for(i = length/2 - 1; i >= 0; --i)  
            HeapAdjust(b, i, length);    
    for(i = length - 1; i > 0; --i)  
    {  
        b[i] = b[0]^b[i];  
        b[0] = b[0]^b[i];  
        b[i] = b[0]^b[i];  
        HeapAdjust(b, 0, i);                      //�ݹ����  
    }  
    dispArray(b,15);
}  

/***ѡ������***/ 
int SelectSort(int a[],int n)  
{
	int i = 0;  
	int min = 0;  
	int j = 0;  
	int tmp = 0;  
	int b[100];
	for(int k=0;k<15;k++)
	{
		b[k]=a[k];
	}
	for(i = 0;i < n-1;i++)  
	{  
		min = i;//ÿ�ν�min�ó���������ʼλ��Ԫ���±�   
	    for(j = i;j < n;j++)//���������飬�ҵ���СԪ�ء�   
	    {  
	      if(b[min]>b[j])  
	      {  
	       min = j;  
	      }  
	    }  
	    if(min != i)//�����СԪ�ز�����������ʼλ��Ԫ�أ�������ʼԪ�ؽ���λ��   
	    {  
	      tmp = b[min];  
	      b[min] = b[i];  
	      b[i] = tmp;  
	    }  
	 }  
	 dispArray(b,15);
}  
  



int main()
{
	int a[]={23, 15, 7, 14, 1, 8, 92, 43, 5, 2, 16, 19, 80, 72, 34};
	int b[100];
	for(int k=0;k<15;k++)
	{
		b[k]=a[k];
	}
	cout<<"����ǰ������:"<<endl; 
	dispArray(a,15);
	cout<<endl<<endl;
	cout<<"ֱ�Ӳ�������:"<<endl;
	InsertSort(a,15);
	cout<<endl<<endl;
	cout<<"ϣ������:"<<endl;
	ShellSort(a,15);
	cout<<endl<<endl;
	cout<<"ð������:"<<endl;
	BubbleSort(a,15);
	cout<<endl<<endl;
	cout<<"��������:"<<endl;
	QuickSort(b,15);
	dispArray(b,15);
	cout<<endl<<endl;
	cout<<"������:"<<endl;
	HeapSort(a,15);
	cout<<endl<<endl;
	cout<<"ѡ������:"<<endl;
	SelectSort(a,15);
	return 0;
}
