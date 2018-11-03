#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 


int root(int i,vi &ar)
{
    while(ar[i]!=i)
    {
        ar[i]=ar[ar[i]];
        cout<<i<<endl;
        i=ar[i];
    }
    return i;
}
void uni(int a,int b,vi &ar, vi &size1)
{
   int r_a=root(a,ar);
   int r_b=root(b,ar);
   if(r_a==r_b)
   return;
   if(size1[r_a]<size1[r_b])
   {
       ar[r_a]=r_b;
       size1[r_b]+=size1[r_a];
   }
   else
   {
       ar[r_b]=r_a;
       size1[r_a]+=size1[r_b];
   }
}

void populateCoPrime(vector<vector<bool>> &v){
    for (int i = 2; i <= 50; i++){
        for (int j = 2; j <= 50; j++){
            if(gcd(i, j) == 1){
                v[i][j] = true;
            }
        }
    }
}

int main()
{
	int t,j,i;
	cin>>t;
    vector<vector<bool>> coPrime(51, vector<bool>(51, false));
    populateCoPrime(coPrime);
	while(t--)
	{
// 		ios::sync_with_stdio(false);
// 		cin.tie(NULL);
		int n,res=0;
		cin>>n;
// 		int ar1[55],size[55],ar[55];
		vi ar1(55), size1(55), ar(55);
		for(int i=0;i<n;i++)
		{
			cin>>ar1[i];
			ar[ar1[i]]=ar1[i];
			size1[ar1[i]]=1;

		}
// 		cout<<"here\n";
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(coPrime[ar1[i]][ar1[j]]== true)
				{
					uni(ar1[i],ar1[j],ar,size1);
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			if(ar[ar1[i]]==ar1[i])
				res++;
		}
		if(n==1)
		{
			cout<<0<<endl;
			cout<<ar1[0];
		}
		else if(res==1)
		{
			cout<<0<<endl;
			for(int i=0;i<n;i++)
			{
				cout<<ar1[i]<<" ";
			}
		}
		else if(ar1[0]==47)
		{
			cout<<1<<endl;
			for(int i=0;i<n-1;i++)
				cout<<ar1[i]<<" ";
			cout<<"43";
		}
		else
		{
			cout<<1<<endl;
			for(int i=0;i<n-1;i++)
				cout<<ar1[i]<<" ";
			cout<<"47";
		}
        
		cout<<endl;
	}
	return 0;
}