#include <iostream>
#include <cstdlib>
#include <cmath>
#include<ctime>
using namespace std;
int count=0;
int part(int a[],int low,int high){
    //int mid = (low+high)*0.5;
    int p = a[low],i=low+1,j=high,t;
    while(1){
        while(a[i]<=p&&i<high){
            i++;
            count++;
        }
        while(a[j]>=p&&j>low){
            j--;
            count++;
        }
        //cout<<i<<" "<<j<<endl;
        if(i<j)
          swap(a[i],a[j]);
        else{
        swap(a[low],a[j]);
        return j;
        }
    }
}

void quick(int a[],int low,int high){
    int s;
    if(low<high)
    {
        s = part(a,low,high);
        quick(a,low,s-1);
        quick(a,s+1,high);
    }
}

void print(int a[],int n){
    int i;
    for(i=0;i<n;i++)
        cout<<a[i]<<"  ";
        cout<<"\n";
}
int main (){
    int a[5],b[600],n,asc,des,ran,i;
    cout<<"Enter 5 elements: "<<endl;
    for(i=0;i<5;i++)
        cin>>a[i];
    cout<<"Before sorting: "<<endl;
    print(a,5);
    quick(a,0,4);
    cout<<"After sorting: "<<endl;
    print(a,5);
    n = 8;
    cout<<"N\t   Ascending order\t  Descending order\t  Random Case\tnlog2n\tn*n"<<endl;
    while(n<=512){
        count=0;
        for(i=0;i<n;++i)
            a[i] = i;
        quick(a,0,n-1);
        asc=count;
        count=0;
        for(i=0;i<n;++i)
            a[i] = n-i;
        quick(a,0,n-1);
        des=count;
        count=0;
        srand(time(0));
        for(i=0;i<n;i++)
            a[i]=rand()%212690;
        quick(a,0,n-1);
        ran=count;    
        cout<<i<<"\t\t"<<asc<<"\t\t\t"<<des<<"\t\t\t"<<ran<<"\t "<<int(n*log2(n))<<"\t "<<int(n*n)<<"\n";
        n*=2;
    }
} // on anverage case quick sort, has theta(nlogn) and worst case is bigO(N^2)
