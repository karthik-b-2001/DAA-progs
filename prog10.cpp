#include <iostream>
#include <vector>
using namespace std;
#define max 10
int d,flag=0,s[max],x[max];
void sub(int p,int k,int r)
{
        static int b=0;
        int i;
        x[k]=1;
        if(p+s[k]==d){
                cout<<"\n Subset "<<++b<<" { ";
                for(i=1;i<=k;i++)
                {
                        if(x[i]==1)
                              cout<<s[i]<<"\t";
                }
                cout<<" }"<<endl;
                flag=1;
        }
        else
                if(p+s[k]+s[k+1]<=d)
                        sub(p+s[k],k+1,r-s[k]);

        if((p+r-s[k]>=d)&&(p+s[k+1]<=d))
        {
                x[k]=0;
                sub(p,k+1,r-s[k]); 
        }
}

int main(){
        int i,n,sum=0;
        cout<<"Enter no of elements "<<endl;
	cin>>n;
        cout<<"Enter elements in ascending order"<<endl;
        for(i=1;i<=n;i++)
        {
                cin>>s[i];
                sum+=s[i];
        }
        cout<<"Enter max subset value"<<endl;
        cin>>d;
        if(sum<d||s[1]>d)
                cout<<"\n no subset possible"<<endl;
        else{
                sub(0,1,sum);         
                if(flag ==0)
                    cout<<"\n no subset possible"<<endl;
        }




}
