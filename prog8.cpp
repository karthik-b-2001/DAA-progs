#include <iostream>
using namespace std;
void prims(int g[20][20], int n)
{
	int vt[20],vr[20],e[20],min,u1,v1;
	int ne,i,j,cost=0;      
	for (i=0;i<n;i++) 
		vt[i]=0;     
       	for (i=0;i<n;i++)
		vr[i]=1;
        vr[0]=0;  
        vt[0]=1;
	cout<<"Minimum spanning tree edges: "<<endl;
    ne=1;
	while (ne<n){
		min=999;
		for (i=0;i<n;i++)
		{
			for (j=0;j<n;j++)
			{
				if (g[i][j]<min)
				{
					if (i!=j && vt[i]==1 && vr[j]==1)  
					{
						min=g[i][j];
						u1=i;
						v1=j;
					}
				}
			}
		}
		cost+=min;
		vt[v1]=1;
		vr[v1]=0;
		ne++;
		cout<<"Edge from vertex "<<u1+1<<" to "<<v1+1<<endl;
	}
	cout<<"The weight of the minimum spanning tree is "<<cost<<endl;
}
int main(){
	int n,g[20][20],i,j;
	cout<<"Enter the number of vertices"<<endl;
    cin>>n;
	cout<<"Enter adjacency matrix"<<endl;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			cin>>g[i][j];
	prims(g,n);
}