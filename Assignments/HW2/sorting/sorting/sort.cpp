#include<iostream>
#include "stdio.h"
#include<string>
#include<fstream>
#include <chrono>
using namespace std::chrono;
using namespace std;

void swap(long &a, long &b)
{
	long t=a;
	a=b;
	b=t;
}
int median(long * arr,long n)
{
	if(n%2==0)
		return arr[n/2]+arr[(n/2)+1];
	else
		return arr[n/2];
}
void insertion2(long * arr ,long small,long max)
{
	 long i, j,key;

	long k=small+1;
	
    for (j =k ; j <=max; j++)
    {
        key = arr[j];
        i = j-1 ;
        while (i >=small && arr[i] > key)
        {
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }

}

///////////////////////selection sort/////////////////
 void SelectionSort(long * arr ,long n)
 {
  long min_index;
  long i,j;
    for (long i=0;i<n-1;i++)
	{
		min_index=i;
		 for(long j=i+1;j<n;j++)
		 {
		    if (arr[j]<arr[min_index] )
				min_index=j;
		 
		 
		 }
		 
			 swap(arr[i],arr[min_index]);

	}
	
  
 }
 ////////////////////////////////////////////////////////

 ////////////////////////insertion sort//////////////////
 void InsertionSort(long * arr ,long n)
 {
     long i, j,key;
    for (j = 1; j < n; j++)
    {
        key = arr[j];
        i = j - 1;
        while (i >= 0 && arr[i] > key)
        {
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }
 
 }

 ////////////////////////////////////////////////////////////

 /////////////////////////////// merge sort////////////////////////
 void merge(long * a, long const p, long  const q, long const r)
{
    long const n1 = q-p+1;
    long  const n2 = r-q;
  
   
    long *l = new long[n1];
    long  *R = new long[n2];
  
    
    for (long i = 0; i < n1; i++)
        l[i] = a[p+ i];
    for (long j = 0; j < n2; j++)
        R[j] = a[q + 1 + j];
  
     long i = 0; 
     long j = 0; 
     long k = p; 

    while (i < n1 && j <n2) {
        if (l[i] <= R[j]) {
            a[k] = l[i];
           i++;
        }
        else {
            a[k] = R[j];
           j++;
        }
        k++;
    }
    
    while (i < n1) {
        a[k] = l[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}
  

void mergeSort(long *arr, long p, long r )
{
    if (p >= r)
        return; 
  
    long q = (p+r) / 2;
    mergeSort(arr, p, q);
    mergeSort(arr, q + 1, r);
    merge(arr, p, q, r);
}
/////////////////////////////////////////////////////



////////////////quick sort///////////////////////////

int partition (long * arr, long p, long r) 
{ 
    long x = arr[r];
    long i = p - 1; 
  
    for (long j = p; j <= r - 1; j++) 
    { 
       
        if (arr[j] <= x) 
        { 
            i++;  
			
            swap(arr[i], arr[j]); 
        } 
    } 
    swap(arr[i + 1], arr[r]); 
    return (i + 1); 
} 
  
void quickSort(long* arr,long p, long r) 
{ 
   
	if(p<r)
    { 
       long q = partition(arr, p, r); 
        
	 
	  quickSort(arr,p, q - 1); 
	   quickSort(arr ,q+1, r);

    } 
	
} 
  //////////////////////////////////////////////////////

///////////////////Hybrid Sort//////////////////////

//mix between insertion ,merge

void HybridSort(long * arr ,long p,long r)
{

	if(r-p<55) 
	
		insertion2(arr,p,r);
	
	else
	{
		
    
	  long q = (p+r) / 2;
       HybridSort(arr, p, q);
       HybridSort(arr, q + 1, r);
       merge(arr, p, q, r);
	   
	   
	}
	  

	
}


///////////////////////////////////////////////////


int main(int argc,char *argv[])

{
	
	 
	if(argc !=5)
		cout<<"number of command line arguments is not equal to 4 \n";
	else
	{
		cout<<"you entered  a correct number of command line arguments  \n";
		long n=500000;
	

	long *a=new long[n];
	
	long count=0;
	fstream file;
	file.open(argv[2],ios::in); //read 
	if(file.is_open())
	{
		cout<<"open successufully "<<endl;
		while (!file.eof())
		{
			file>>a[count];
		  count++;
		}
		



		file.close();
	}

	else
	{
		
		cout<<"error while opening !! "<<endl;
	  
	  
	}
	
	count--;
	

	//  sorting operation 
	string s=argv[1];
	int q=0;
	auto start = high_resolution_clock::now();
	if(s.compare("0")==0)
	{
	SelectionSort(a,count);
	q=1;
	}
	else if(s.compare("1")==0)
	{
	InsertionSort(a,count);
	q=2;
	}
	else if(s.compare("2")==0)
	{
	mergeSort(a,0, count-1 );
	q=3;
	}
	else if(s.compare("3")==0)
	{
	quickSort(a,0,count-1);
	q=4;
	}
	else if(s.compare("4")==0)
	{
	HybridSort(a,0,count-1);
	q=5;
	}


	auto end = high_resolution_clock::now();
	 duration<double,std::milli>  time=end-start;
	
	
	fstream file2;
	file2.open(argv[3],ios::out); //write
	if(file2.is_open())
	{
		cout<<"open successufully "<<endl;
		for(long i=0;i<count;i++)
		  file2<<a[i]<<"\n";



		file2.close();
	}

	else
	{
		cout<<"error while opening !! "<<endl;
	  
	  
	}


	
	fstream file3;
	file3.open(argv[4],ios::out); //write
	if(file3.is_open())
	{
		cout<<"open successufully "<<endl;
		
		file3 << "Time taken is: ";
        file3 << time.count() << " milliseconds \n" ;
		 if(q==1)
			 file3 << "by selection sort \n ";
		 else if(q==2)
			 file3 << "by insertion sort \n ";
		 else if(q==3)
			 file3 << "by merge sort \n ";
		 else if(q==4)
			 file3 << "by quick sort \n ";
		 else if(q==5)
			  file3 << "by hybird sort \n ";

		file3.close();
	}

	else
	{
		cout<<"error while opening !! "<<endl;
	  
	  
	}

	


	}
	

	return 0;
}
