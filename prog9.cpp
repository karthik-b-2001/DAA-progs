#include <iostream>
#include <cstdlib>
using namespace std;
void dijs(int n,int sv, int cost[10][10],int dist[],int pred[]){
	int i,v,count,w,j,visited[23],min;
	for (i=0;i<n;i++){
		visited[i]=0;
		dist[i]=cost[sv][i];
		if( dist[i] !=999)
		   pred[i]=sv;
	}
	visited[sv]=1;
	dist[sv]=0;
	pred[sv]=-1;
	count=1;
	while (count< n){
		min=999;
		for (w=0;w<n;w++)
			if (dist[w]<min && !visited[w])
			{
				min =dist[w];
				v=w;
			}
		visited[v]=1;
		count++;
		for (w=0;w<n;w++)
			if (!visited[w] &&  dist[v]+cost[v][w]<dist[w]){
				      dist[w]=dist[v]+cost[v][w];
				      pred[w]=v;
			    } 
	}
}

int main(){
	int n,sv,i,j,dist[10],cost[10][10],pred[10];
	cout<<"Enter the number of vertices"<<endl;
	cin>>n;
	cout<<"Enter cost matrix"<<endl;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			cin>>cost[i][j];
			if (cost[i][j]==0)
				cost[i][j]=999;

	cout<<"Enter the source vertex"<<endl;
	cin>>sv;
	dijs(n,sv,cost,dist,pred);
	cout<<"Shortest path: "<<endl;
	for(i=0;i<n;i++)
        if(i!=sv){
        	cout<<"Distance of vertex "<<i<<" is "<<dist[i]<<endl;
         	cout<<"Path is "<<i;
          	j=i;
          	do{
            	j=pred[j];
            	cout<<"<- "<<j;
           }while(j!=sv);
		   cout<<"\n\n";
        }
}