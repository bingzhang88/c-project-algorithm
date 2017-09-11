#include <memory>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;

const int maxn = 2000 + 5;
int v[maxn];
int n;
int dp[maxn][maxn];
int solve(int la, int lb) {
	int now = max(la,lb) + 1;
	if(now == n + 1) return 0;
	if(dp[la][lb] != -1) return dp[la][lb];
	return dp[la][lb] = min(solve(now, lb) + (la ? abs(v[now] - v[la]) : 0), solve(la, now) + (lb ? abs(v[now] - v[lb]) : 0));
}
int main() {
	scanf("%d", &n);
	v[0] = -1;
	for(int i = 1; i <= n; i++) scanf("%d", &v[i]);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", solve(0, 0));
	return 0;
}