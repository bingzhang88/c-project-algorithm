#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
using namespace std;

void process()
{
	int n;
	cin>>n;
	vector<double> vec(n);
	for(int i=0;i<n;i++)
	{
		cin>>vec[i];
	}
	double max_dis=0.0;
	double min_dis_180=180.0;
	sort(vec.begin(),vec.end());
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			double dis=abs(vec[i]-vec[j]);
			dis=dis<=180.0?dis:360.0-dis;
			if(180.0-dis<min_dis_180)
			{
				min_dis_180=180.0-dis;
				max_dis=dis;
			}
            else
            {
                break;
            }
            if(abs(max_dis-180.0)<0.000000001)
            {
                printf("%.8f\n",max_dis);
				return;
            }
		}
	}
	printf("%.8f\n",max_dis);
	return;
}

int main()
{
	process();
	return 0;
}