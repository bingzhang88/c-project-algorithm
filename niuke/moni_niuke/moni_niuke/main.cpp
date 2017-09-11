#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
#include<queue>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;

int total_yinzi(int n){
    int res=0;
    for(int i=2;i<=sqrt(n*1.0);i++){
        if(n%i==0){
			if(i*i==n)
				res++;
			else
				res+=2;
		}
    }
    return res;
}
const int maxn=1e6;
const int mod=1e9+7;
int visit[maxn];
int legal(int n){
    long long res=1;
    for(int i=2;i<=n;i++){
		if(visit[i]==1)	continue;
        for(int j=i+i;j<=n;j+=i) visit[j]=1;
		int temp=n;
		int count=0;
		while(temp>=i)
		{
			temp/=i;
			count++;
		}
		res=res*(count+1)%mod;
    }
    return res;
}

int main()
{
	int n;
    cin>>n;
    long long ans = 1;
    for(int i = 2; i <= n; i++) {
        if(visit[i]) continue;
        for(int j = i + i; j <= n; j += i) visit[j] = 1;
        int tmp = n, cnt = 0;
        while(tmp >= i) tmp /= i, cnt++;
        ans = ans * (cnt + 1) % mod;
    }
    cout<<ans<<endl;
    return 0;
}