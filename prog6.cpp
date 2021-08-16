#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;
int table[2000];
int count = 0;
void ShiftTableComputation(char p[]){
	int m,i,j;
	m=strlen(p);
    for (i=0;i<1000;i++)
	    table[i]=m;
	for (j=0;j<=m-2;j++)
	   table[p[j]]=m-1-j;
}
int HPoolStringMatching(char p[],char t[]){
	int m,n,i,j,k;
	ShiftTableComputation(p);
	m=strlen(p);
	n=strlen(t);
	i=m-1;
	while (i<=n-1){
		k=0;
		++count;
		while ((k<=m-1) && t[i-k]==p[m-1-k])
			k++;
		if (k==m)
			return i-m+1;
		else
			i=i+table[t[i]];
	}
	return -1;
}

int main(){
    char str[100],ptr[100];
    int res;
	cout<<"Enter String"<<endl;
	cin>>str;
    cout<<"Enter pattern"<<endl;
	cin>>ptr;
	res=HPoolStringMatching(ptr,str);
	(res == -1)?cout<<"\nNot Found\n":cout<<"\nPattern is at "<<res+1<<"\n";
	cout<<"\n"<<count<<endl;
}
