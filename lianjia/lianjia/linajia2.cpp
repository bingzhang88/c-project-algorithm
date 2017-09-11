#include <iostream>
#include <vector>
using namespace std;
const int maxn=2005;

int n,m,dp[maxn][maxn],a[maxn];
int main()
{
    int i,j,k,t;
	while(cin>>n)
	{
		if(n>2000)
			continue;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(i=1;i<=n;i++)
		{
			for(j=1;j+i<=n+1;j++)
			{
				dp[j][i]=max(dp[j+1][i-1]+(n-i+1)*a[j],dp[j][i-1]+(n-i+1)*a[j+i-1]);
			}
		}
		cout<<dp[1][n]<<endl;
	}
    return 0;
}