#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#define MAXSIZE 100
using namespace std;
int m=0,n=0;

int dispArray(int a[], int len)
{
	//显示给定长度len的数组a[];
	for(int i=0;i<len;i++)
	{
		cout<<a[i]<<"   ";
	}
}


/***直接插入排序***/ 
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


/***希尔排序***/
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
    for(step=len/2; step>0;step/=2) //用来控制步长,最后递减到1  
    {  
        // i从第step开始排列，应为插入排序的第一个元素  
        // 可以先不动，从第二个开始排序  
        for(i=step;i<len;i++)  
        {  
            temp = b[i];  
            for(j=i-step;(j>=0 && temp > b[j]);j-=step)  
            {  
                b[j+step] = b[j];  
            }  
            b[j+step] = temp; //将第一个位置填上  
        }  
    }  
    dispArray(b,15);
}  

int BubbleSort(int a[],int len)  
{  
    //冒泡排序  
    int i,j;  
    int t;  
    int b[100];
	for(int k=0;k<len;k++)
	{
		b[k]=a[k];
	}
    for(i=0;i<len-1;i++)//n个数的数列总共扫描n-1次  
    {  
        for(j=0;j<len-i-1;j++)//每一趟扫描到a[n-i-2]与a[n-i-1]比较为止结束  
        {  
            if(b[j]>b[j+1])//后一位数比前一位数小的话，就交换两个数的位置（升序）  
            {  
               t=b[j+1];  
               b[j+1]=b[j];  
               b[j]=t;  
            }  
        }  
    }
    dispArray(b,15);
} 

/***快速排序***/ 
int QuickSort(int b[],int len){  
    int i = 0;  
    int j = len - 1;  
    int k = b[0];  
    if (len>1) {//重复的判断条件，如果长度小于2，则不需排序  
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

/***堆排序***/ 
int HeapAdjust(int b[], int i, int length)  
{  
    int Child;  
    int temp;  
    for(;2 * i + 1 < length; i = Child)  
    {  
        //子节点的位置 = 2 * (parent(父结点)) + 1  
        Child = 2 * i + 1;  
        //得到子结点中较大的结点  
        if(Child < length - 1 && b[Child + 1] > b[Child])  
                ++Child;  
        //如果较大的子结点大于父结点那么把较大的子结点往上移动  
        //替换它的父结点  
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
//堆排序算法  
int HeapSort(int a[], int length)  
{  
	int b[100];
	for(int k=0;k<15;k++)
	{
		b[k]=a[k];
	}
    int i;  
    //调整序列的前半部分元素，调整完之后第一个元素  
    //是序列的最大元素，length/2-1是最后一个非叶子结点  
    for(i = length/2 - 1; i >= 0; --i)  
            HeapAdjust(b, i, length);    
    for(i = length - 1; i > 0; --i)  
    {  
        b[i] = b[0]^b[i];  
        b[0] = b[0]^b[i];  
        b[i] = b[0]^b[i];  
        HeapAdjust(b, 0, i);                      //递归调整  
    }  
    dispArray(b,15);
}  

/***选择排序***/ 
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
		min = i;//每次讲min置成无序组起始位置元素下标   
	    for(j = i;j < n;j++)//遍历无序组，找到最小元素。   
	    {  
	      if(b[min]>b[j])  
	      {  
	       min = j;  
	      }  
	    }  
	    if(min != i)//如果最小元素不是无序组起始位置元素，则与起始元素交换位置   
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
	cout<<"排序前的数组:"<<endl; 
	dispArray(a,15);
	cout<<endl<<endl;
	cout<<"直接插入排序:"<<endl;
	InsertSort(a,15);
	cout<<endl<<endl;
	cout<<"希尔排序:"<<endl;
	ShellSort(a,15);
	cout<<endl<<endl;
	cout<<"冒泡排序:"<<endl;
	BubbleSort(a,15);
	cout<<endl<<endl;
	cout<<"快速排序:"<<endl;
	QuickSort(b,15);
	dispArray(b,15);
	cout<<endl<<endl;
	cout<<"堆排序:"<<endl;
	HeapSort(a,15);
	cout<<endl<<endl;
	cout<<"选择排序:"<<endl;
	SelectSort(a,15);
	return 0;
}
