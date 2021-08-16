#include <iostream>
#include <cstdlib>
using namespace std;
int max(int a,int b){ return (a>b?a:b); }
void Knapsack(int n,int m, int w[20],int V[20][20],int p[20])
{
	int i,j;
	for (i=0;i<=n;i++)
	{
		for (j=0;j<=m;j++)
		{
			if (i==0||j==0)
			{
				V[i][j]=0;
			}
			else if (j < w[i])
			{
				V[i][j]=V[i-1][j];
			}
			else
			{
				V[i][j]=max(V[i-1][j], p[i]+V[i-1][j-w[i]]);
			}
			cout<<V[i][j]<<"\t";
		}
		cout<<"\n";;
	}
}
void optimal(int n,int m,int w[20],int v[20][20]){
	int i,j,x[20];
	if (v[n][m]==0){
		cout<<"Not Possible"<<endl;
		return;
	}
	cout<<"Optimal solution is "<<v[n][m]<<endl;
	for (i=0;i<n;i++)
		x[i]=0;
	i=n;
	j=m;
	cout<<"Objects Selected: "<<endl;
	while (i!=0 && j!=0)
	{
		if (v[i][j]!=v[i-1][j])
		{
			x[i]=1;
			cout<<"\n"<<i;
			j=j-w[i];
		}
		i--;
	}
	cout<<"\n";
}

int main(){
	int m,n,i,j,p[20],w[20],v[20][20];
	cout<<"Enter no. of objects:"<<endl;
	cin>>n;
	cout<<"Enter weight of "<<n<< " objects: "<<endl;
	for (i=1;i<=n;i++)
		cin>>w[i];
	cout<<"Enter Profits:"<<endl;
	for (i=1;i<=n;i++)
		cin>>p[i];
	cout<<"Enter capacity: "<<endl;
	cin>>m;
	Knapsack(n,m,w,v,p);
	optimal(n,m,w,v);
}