#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
int len,a[1000],count=0;
void heapify(int i){
	int heap=0,j,v,k;
    k=i;
    v=a[k];  
	while (!heap && 2*k<=len){
		j=2*k;
		if (j<len)  {
            count++;
			if (a[j]<a[j+1])
				j=j+1;
		}
        count++;
		if (v>=a[j])
			heap=1; 
		else
		{
			a[k]=a[j];  
			k=j;
		}
	}
	a[k]=v;
}

void heap(){
	int i,t;
	for (i=len/2;i>0;i--)
		heapify(i);
	for (i=len; i>1 ;i--){
        count++;
		t=a[len];
		a[len]=a[1];
		a[1]=t;
		len--;
		heapify(1);
	}
}

int main(){
	int i,j,n,c1,c2,c3;
	cout<<"Enter number of elements"<<endl;
	cin>>n;
	len=n;
	cout<<"Enter "<<n<<" elements"<<endl;
	for (i=1;i<=len;i++)
		cin>>a[i];
	heap();
	cout<<"\nSorted array is \n"<<endl;
	for (i=1;i<=n;i++)
		cout<<a[i]<<"  ";
	cout<<"\nCOUNT: "<<count<<endl;
    cout<<"N\t   Ascending order\t  Descending order\t  Random Case\tnlog2n"<<endl;
    i = 8;   
    while(i<=512){
        count = 0;
        len = i;
        for (j=1;j<=i;j++)
			a[j]=j;
        heap();
		c1=count;
		count=0;
		len=i;
		for (j=1;j<=i;j++)
			a[j]=i-j;
		heap();
		c2=count;
		count=0;len=i;
		for (j=1;j<=i;j++)
			a[j]=rand()%12500;
		heap();
		c3=count;
        cout<<i<<"\t\t"<<c1<<"\t\t\t"<<c2<<"\t\t\t"<<c3<<"\t "<<int(i*log2(i))<<"\n";
        i*=2;
    }
}
