// LONGEST COMMON SUBSEQUENCE - DP (2 STRINGS)
#include<bits/stdc++.h>
typedef long long ll;
typedef double dl;
using namespace std;
int main()
{
	string a,b;
	cout<<"\nEnter the strings: ";
	cin>>a>>b;
	
	int x=a.length(),y=b.length();
	
	int i,j,k;
	vector<int> c(x+1,0);
	vector<vector<int> >v(y+1,c);
	
	
	for(i=0;i<y;i++)
	{
		for(j=0;j<x;j++)
		{
			if(b[i]==a[j])
			{
				v[i+1][j+1]=v[i][j]+1;
			}
			else
			{
				v[i+1][j+1]=max(v[i][j+1],v[i+1][j]);
			}
		}
	}
	
	cout<<"\nLENGTH OF LCS IS: "<<v[y][x];  // length of (an) lcs

	int l=min(x,y);
	
	string lcs="";
	for(i=j=l;i>=0 && j>=0;)
	{
			if(b[i]==a[j])
			{
				lcs+=b[i];
				i--,j--;
			}
			else if(v[i+1][j]>=v[i][j+1])
			{
				j--;
			}
			else i--;
	} 	
	
	reverse(lcs.begin(),lcs.end());
	cout<<"\nLCS IS: "<<lcs<<endl;		   //(one of the) longest common subsequence(s)
	return 0;
}
