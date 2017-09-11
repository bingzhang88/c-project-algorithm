#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

long long sum_vec(vector<int>&vec,int start,int end)
{
	long long res=0;
	for(int i=start;i<=end;i++)
		res+=vec[i];
	return res;
}

void meituan1()
{
	int N;
	cin>>N;
	vector<int> vec(N);
	for(int i=0;i<N;i++)
	{
		cin>>vec[i];
	}
	int k;
	cin>>k;
	int len=N;
	while(len)
	{
		int temp=sum_vec(vec,0,len-1);
		if(temp%k==0)
		{
			cout<<len<<endl;
			return;
		}
		for(int i=1;i<=N-len;i++)
		{
			temp-=vec[i-1];
			temp+=vec[i+len-1];
			if(temp%k==0)
			{
				cout<<len<<endl;
				return;
			}
		}
		len--;
	}
	cout<<0<<endl;
	return;
}

void meituan2()
{
	int n;
	cin>>n;
	vector<int>vec(n);
	for(int i=0;i<n;i++)
	{
		cin>>vec[i];
	}
	sort(vec.begin(),vec.end());
	reverse(vec.begin(),vec.end());
	int sum=vec[0];
	for(int i=1;i<n;i++)
	{
		if(sum<vec[i])
		{
			cout<<"No"<<endl;
			return;
		}
	}
	for(int i=1;i<n;i++)
	{
		sum-=vec[i];
	}
	if(sum>0)
		cout<<"No"<<endl;
	cout<<"Yes"<<endl;

	return;
}

int main()
{
	meituan2();
	return 0;
}