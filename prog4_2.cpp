#include <iostream>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
stack<int> s;
vector<int> v;
void dfs(int a[10][10],int n,bool visit[10],int cur){
    int j;
    s.push(cur);
    visit[cur] = true;
    for(j=0;j<n;j++){
        if(a[cur][j]==1&&visit[j]==false)
            dfs(a,n,visit,j);
    }
   cout<<s.top()<<" ";
   v.push_back(s.top());
   s.pop();
}
void DFS(int a[10][10],int n){
    bool visit[10];
    int c = 0,i;
    for(i=0;i<n;i++)
        visit[i] = false;
    cout<<"Popback  "<<endl;
    for(i=0;i<n;i++){
        if(visit[i]==false){
            dfs(a,n,visit,i);
            c++;
        }
    }
    (c>1)?cout<<"\nGraph disconnected with "<<c<<" components"<<endl:cout<<"\nGraph is connected"<<endl;    
}
int TopoSort(int n, int a[10][10],int indegree[10],int output[10])
{
	int i,j,k=0;
	for (i=0;i<n;i++)
	{
		if (indegree[i]==0)
		{
			indegree[i]=-1;  
			output[k++]= i;   

			for (j=0;j<n;j++){
				if (indegree[j]!=-1&&a[i][j]==1) 
				{
					indegree[j]--;
				}
			}
			i=0;
		}
	}
	return k;
}

int main()
{
	int i,j,adj[10][10],m,n,b[10],indegree[10];
	cout<<"Enter no. of vertices:"<<endl;
	cin>>n;
    for (i=0;i<n;i++)
		indegree[i]=0;    
	cout<<"Enter adjacency matrix:"<<endl;;
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			cin>>adj[i][j];
			if (adj[i][j]==1) // update the indegree of vertex j because there is an edge from i to j
				indegree[j]++;
		}
	}
        
	m=TopoSort(n,adj,indegree,b);
	if (m!=n) 
	{
		cout<<"\nCycle Detected.Topological sort not possible"<<endl;
		exit(1);
	}
	else
	{
		cout<<"\nTopological ordering is:"<<endl;;
		for (i=0;i<n;i++)
			cout<<b[i]<<" ";
		cout<<"\n";
	}
	cout<<"Topoloogical Sorting By DFS"<<endl;
	DFS(adj,n);
    for(auto i = v.end()-1;i>=v.begin();i--)
        cout<<*i<<"  ";
    cout<<"\n";
	return 0;
}