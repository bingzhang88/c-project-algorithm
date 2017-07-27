#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
#include<queue>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;
int m,n;
vector<vector<int> > vec(100,vector<int>(100));
vector<int> res;
int max_step=0;
void movingCount(int index,int i,int j)
{
	if(i>=m || j>=n)
	{
		//res.push_back(index-1);
		if(index-1>max_step)
			max_step=index-1;
		return;
	}
	if(vec[i+1][j]<vec[i][j])
		movingCount(index+1,i+1,j);
	if(vec[i][j+1]<vec[i][j])
		movingCount(index+1,i,j+1);
	if(i==0 && j>0)
	{
		if(vec[i][j-1]<vec[i][j])
			movingCount(index+1,i,j-1);
	}
	else if(j==0&& i>0)
	{
		if(vec[i-1][j]<vec[i][j])
			movingCount(index+1,i-1,j);
	}
	else if(j>0 && i>0)
	{
		if(vec[i][j-1]<vec[i][j])
			movingCount(index+1,i,j-1);
		if(vec[i-1][j]<vec[i][j])
			movingCount(index+1,i-1,j);
	}
	//res.push_back(index);
	if(index>max_step)max_step=index;
    return;
}

int main()
{
	cin>>m>>n;
	int weight;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>weight;
			vec[i][j]=weight;
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			movingCount(0,i,j);
	}
	cout<<max_step+1<<endl;
    return 0;
}