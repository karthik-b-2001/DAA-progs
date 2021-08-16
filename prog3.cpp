#include <iostream>
#include <cstdbool>
#include <queue>
using namespace std;
void dfs(int a[10][10],int n,bool visit[10],int cur){
    int j;
    visit[cur] = true;
    cout<<cur<<"  ";
    for(j=0;j<n;j++){
        if(a[cur][j]==1&&visit[j]==false)
            dfs(a,n,visit,j);
    }
}
void DFS(int a[10][10],int n){
    bool visit[10];
    int c = 0,i;
    for(i=0;i<n;i++)
        visit[i] = false;
    cout<<"DFS:  "<<endl;
    for(i=0;i<n;i++){
        if(visit[i]==false){
            dfs(a,n,visit,i);
            c++;
        }
    }
    (c>1)?cout<<"\nGraph disconnected with "<<c<<" components"<<endl:cout<<"\nGraph is connected"<<endl;    
}
void bfs(int a[10][10],int n,bool visit[10],int cur){
    int i,m;
    queue<int> q;
    q.push(cur);
    visit[cur] = true;
    while(!q.empty()){
        m = q.front();
        q.pop();
        cout<<m<<"  ";
        for(i = 0;i<n;i++){
            if(a[m][i] == 1&&visit[i]==false){
                q.push(i);
                visit[i]=true;
            }
        }
    }
}
void BFS(int a[10][10],int n){
    bool visit[10];
    int c = 0,i;
    for(i=0;i<n;i++)
        visit[i] = false;
    cout<<"BFS: "<<endl;
    for(i=0;i<n;i++)
        if(visit[i]==false)
        {
            bfs(a,n,visit,i);
            ++c;
        }
    (c>1)?cout<<"\nThe graph is disconnected with "<<c<<" components"<<endl:cout<<"\nGraph is connected"<<endl;
}
int main(){
    int a[10][10],n,i,j;
    cout<<"Enter number of vertices"<<endl;
    cin>>n;
    cout<<"Enter adjacency matrix"<<endl;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(a[j][i]==1)
                a[i][j]=1;
    DFS(a,n);
    cout<<"\n";
    BFS(a,n);
}