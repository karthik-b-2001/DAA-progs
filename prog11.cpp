#include <iostream>
#include <cstdlib>
using namespace std;

int place(int p,int x[]){
	int i;
	for (i=1;i<=(p-1);i++)
		if ((x[i]==x[p])||(abs(x[i]-x[p])==(abs(i-p))))
			return 0;
		return 1;
}
int main(){
	int i,j,k,n,count=1,x[1500],flag =0;
	cout<<"Enter number of queens"<<endl;
    cin>>n;
	x[1]=0;    //x[k] column no, k is row number
    k=1;
	while(k!=0){
		x[k]=x[k]+1;   
		while (x[k]<=n && !place(k,x))
			x[k]=x[k]+1;
		if (x[k]<=n){
			if (k==n){
				cout<<"Solution: "<<++count<<endl;
				flag =1;
				for (i=1;i<=n;i++){
					for (j=1;j<x[i];j++)       
						cout<<"* ";
					cout<<"Q ";
					for (j=x[i]+1;j<=n;j++)
						cout<<"* ";
					cout<<"\n";
					}
				}
		    else{
			    k+=1;
			    x[k]=0;
		    }
		}
		else  
			k-=1;
		}
		if (flag == 0)
		    cout<<"No Solution"<<endl;

}
		
