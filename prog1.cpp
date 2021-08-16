 #include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int c=0;
void merge(int a[],int low,int mid,int high)
{
    int t1 = mid - low + 1,t2=high-mid;
    int left[t1],right[t2],i,j,k;
    for(i=0;i<t1;i++)
        left[i] = a[low+i];
    for(j=0;j<t2;j++)
        right[j] = a[mid+1+j];
    i=0;
    j=0;
    k=low;
    while(i<t1&&j<t2){
        c+=1;
        if(left[i]<=right[j]){
            a[k]=left[i];
            i+=1;
        }
        else{
            a[k]=right[j];
            j+=1;
        }
        k+=1;
        
    }
    while(i<t1){
        a[k]=left[i];
        i+=1;
        k+=1;
    }
    while(j<t2){
        a[k]=right[j];
        j+=1;
        k+=1;

    }
}
void mergesort(int a[],int low,int high){
    if(low>=high)
        return;
    int mid=(low+high)/2;
    mergesort(a,low,mid);
    mergesort(a,mid+1,high);
    merge(a,low,mid,high);
}
int main(){
    int a[600],i,j,n,b1[]={8,7,3,2,9,87,565,20},best,worst,ran,b[600],b2[]= {1,3,2,5,4};
    cout<<"Unsorted array"<<endl;
     for(i=0;i<8;i++)  
        cout<<b1[i]<<"\t";
    cout<<"\n";
    mergesort(b1,0,7);
    cout<<"Sorted array"<<endl;
    for(i=0;i<8;i++)  
        cout<<b1[i]<<"\t";
    cout<<"\nUnsorted array"<<endl;
    for(i=0;i<5;i++)  
        cout<<b2[i]<<"\t";
    cout<<"\n";
    mergesort(b2,0,4);
    cout<<"Sorted array"<<endl;
    for(i=0;i<5;i++)  
        cout<<b2[i]<<"\t";
    cout<<"\n";
    cout<<"N\t   Best Case\t  Worst Case\t  Random Case"<<endl;
    n = 16;
    while(n<=512)
    {
        c=0;
        for(i=1;i<n;i++)
            a[i] = i;
        mergesort(a,0,n);
        best = c;
        
        c=0;
        for(i=0;i<n;i++)
            a[i] = n-i-1;
        mergesort(a,0,n);
        worst = c;
        
        c=0;
        srand(time(0));
        for(i=0;i<n;i++)
            a[i] = rand()%21604;
        mergesort(a,0,n);
        ran = c;
        
        cout<<i<<"\t\t"<<best<<"\t\t"<<worst<<"\t\t"<<ran<<"\n";
        n*=2;
    }
} 
