#include<iostream>
long long  Differenttable(int ,int );
const long long  mol = 1e9+7;
long long  dp[105][105];
long long  N,M,P;

int main()
{
    std::cin >> N >> M >> P;
    for (int i=0;i<=P;i++)
        for (int j=0;j<=N;j++)
            dp[i][j]=-1;
    std::cout<<Differenttable(0,0) << std::endl;
	//system("pause");
    return 0;
}

long long  Differenttable(int i,int j)
{
	if (dp[i][j]!=-1)
		return dp[i][j];
	if (i==P)
	{
		if (j==N){
			dp[i][j]=1;
			return 1;
		}
		else{
			dp[i][j]=0;
			return 0;
		}  
	}
	dp[i][j]=0;
	if (j>M)
		dp[i][j] = Differenttable(i+1,j) * (j-M);
	if (j<N)
		dp[i][j] += Differenttable(i+1,j+1)*(N-j);
	if (dp[i][j] >= mol) 
		dp[i][j] %= mol;
	return dp[i][j];
}