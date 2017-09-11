#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void sohu1()
{
	int m,n;
	cin>>n>>m;
	vector<int> vec(m);
	for(int i=0;i<m;i++)
	{
		cin>>vec[i];
	}
	int index=0;
	vector<int> res;
	int count;
	while(res.size()<n)
	{
		if(res.size()==index)
			count=vec[index%m];
		else
			count=res[index];
		while(count--)
		{
			res.push_back(vec[index%m]);
		}
		index++;
	}
	for(int i=0;i<n;i++)
	{
		cout<<res[i]<<endl;
	}
	return;
}

void sohu2()
{
	vector<int> vec(6,0);
	while(1)
	{
		int sum=0;
		for(int i=0;i<6;i++)
		{
			cin>>vec[i];
			sum+=vec[i];
		}
		if(sum==0)
			break;
		else
		{
			int res=0;
			res+=vec[5];
			res+=vec[4];
			vec[0]-=vec[4]*11;
			res+=vec[3];
			vec[1]-=vec[3]*5;
			res+=vec[2]/4;
			int last=vec[2]%4;


			cout<<res<<endl;
		}
		
	}
	return;
}

int main()
{
	//sohu1();
	sohu2();
	return 0;
}