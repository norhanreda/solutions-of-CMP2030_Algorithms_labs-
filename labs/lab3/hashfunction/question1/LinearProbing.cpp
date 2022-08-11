#include<iostream>
#include<string>
#include<fstream>
#include<cmath>
#include<vector>
#include<algorithm>
#include <chrono>
using namespace std::chrono;
using namespace std;

 int stringhashfunc(string s)
{
	int hash=0;
	if(s.size()==1)
		hash=hash+39*int(s[0]);
	else if(s.size()==2)
		hash=hash+39*int(s[0])+392*int(s[1]);
	else if(s.size()==3)
		hash=hash+39*int(s[0])+392*int(s[1])+393*int(s[2]);
	else
	{
	 hash=hash+39*int(s[0])+392*int(s[1])+393*int(s[2])+394*int(s[3]);
	
	}
		return hash;

}
int insert(string * a,int n,int j, string *h,int m)
{
	int probes=0;
	for(int i=j;i<n;i++)
	{
		int index=(stringhashfunc(a[i]) )%m;
		

		while(h[index]!="" )
		{
		index=index+1;
	     probes++;
		 if(index==m)
			 index=0;
		}
		h[index]=a[i];

		 
	
	}
	return probes;

}






void searchanddelete(string * a,int end,int start, string *h,int m,vector<int> &probe)
{
	
	for(int i=start;i<end;i++)
	{
		int probesnum=0;
		bool flag=true;
		int index=(stringhashfunc(a[i]) ) %m;
		

		while(h[index]!="" && flag)
		{
			if(h[index]==a[i])
			{
		        h[index]="$";
				flag=false;
			}
			
			index++;
	     probesnum++;
		 if(index==m)
			 index=0;
			
		}
		probe.push_back(probesnum);
		
	
	}
	
}


int main()
{

	//read
	int n=20000;
	string *A=new string[n];
	int count=0;

	fstream file;
	file.open("words20K.txt",ios::in); //read 
	if(file.is_open())
	{
		cout<<"open successufully "<<endl;
		while (!file.eof())
		{
			file>>A[count];
		  count++;
		}
		
		file.close();
	}

	else
	{
		
		cout<<"error while opening !! "<<endl;
	  
	  
	}
	
	count--;
	int m=24000;
	string* H=new string[m];
	for(int i=0;i<m;i++)
	  H[i]="";
	int num;
	/////////insert each 500 into h/////////
	for(int i=1;i<=40;i++)
	{
	cout<<"-----------insertion of each 500 words  -------------"<<endl;
	int j=500*i;
	auto startinsertion = high_resolution_clock::now();
	num=insert(A,j,j-500,H,m);
	auto endinsertion = high_resolution_clock::now();
	duration<double,std::milli>  timeinsertion=endinsertion-startinsertion;
     cout<<"time for insertion each word of A into H is: "<<timeinsertion.count()/500.0 << " milliseconds \n" ;
	 cout<<"number of probes for insertion: "<<num<<endl;
	 cout<<"------------------------------------------"<<endl;
	 num=0;
	}


	/////////////4-search and delete//////////////

	vector<int> probe;
	cout<<endl;
	cout<<endl;
	cout<<"-----------------probes for searching a specefic word: "<<endl;
	searchanddelete( A, 14999, 14000, H, m, probe);
	sort(probe.begin(),probe.end());
	cout<<"min probe is: "<<probe[0]<<endl;

	cout<<"max probe is: "<<probe[probe.size()-1]<<endl;

	float sumprobe=0;
	float avgprobe=0;
	for(int i=0;i<probe.size();i++)
	{
	sumprobe=sumprobe+probe[i];
	}
	avgprobe=sumprobe/(probe.size());


	cout<<"average probe is: "<<avgprobe<<endl;





	/////////////////////////////////////////////




	
	fstream fout;
	fout.open("out.txt",ios::out); //read 
	if(fout.is_open())
	{
		cout<<"open successufully "<<endl;
		for(int i=0;i<24000;i++)
		{
			fout<<H[i]<<endl;
		 
		}
		



		file.close();
	}

	else
	{
		
		cout<<"error while opening !! "<<endl;
	  
	  
	}
	int check=0;
	for(int i=0;i<m;i++)
	{
	  if(H[i] !="" )
	   check++;
	}
	
	cout<<"check= "<<check<<endl;
	
	
	return 0;
}