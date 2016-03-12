//0-1 knapsack DP
#include<iostream>
#include<vector> 
#include<string>
typedef long long ll;
using namespace std;

int fees[105];
ll fun[105];
ll t[105][505];

int main()
{
		ll b,n;
		
		do
		{
				cin>>b>>n;
				if(b==0 && n==0)break;
				
				ll i,j,val=0,ind;
				for(i=1;i<=n;i++)
				{
					cin>>fees[i]>>fun[i];	
				}
				
				for(i=0;i<=n;i++)
				{
					for(j=0;j<=b;j++)
					{
						if(i==0 || j==0)t[i][j]=0;
						else
						{
							if(fees[i]>j)t[i][j]=t[i-1][j];
							else if(fees[i]<=j)
							{
								t[i][j]=max(fun[i]+t[i-1][j-fees[i]],t[i-1][j]);
							}
						}
						
					}
				}
				
				for(i=n,j=b,val=t[n][b];j>=0;j--)
				{
					if(t[i][j]==val)ind=j;
				}
				
				cout<<ind<<" "<<t[n][b]<<endl;
		}while(true);
		
		return 0;
}
