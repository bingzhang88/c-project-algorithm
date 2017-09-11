#include<iostream>

void Max_optimize_val(int n);

const int maxn=1e5;
int total,total_v[maxn],total_w[maxn],v[maxn],m[maxn],w[maxn],f[maxn];
int main()
{   int V, n;
	std::cin>>n>>V;
	for(int i=1;i<=n;i++)
		std::cin>>m[i]>>w[i]>>v[i];
	Max_optimize_val(n);
	for(int i=1;i<=total;i++)
		for(int j=V;j>=total_w[i];j--)
			f[j]=std::max(f[j],f[j-total_w[i]]+total_v[i]);
	std::cout<<f[V] <<std::endl;
	system("pause");
	return 0;
}
void Max_optimize_val(int n) 
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m[i];j<<=1)
		{
			total_w[++total]=j*w[i];
			total_v[total]=j*v[i];
			m[i]-=j;
		}
		if(m[i])
		{
			total_w[++total]=m[i]*w[i];
			total_v[total]=m[i]*v[i];
		}
	}
}