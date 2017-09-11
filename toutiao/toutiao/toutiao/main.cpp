#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct ss{
	double i;
	char c;
	char* ptr;
	int a[10];
int s[];

};
int get_min(vector<int> &a,int begin,int end)
{
	int res=100;
	for(int i=begin;i<=end;i++)
	{
		if(a[i]<res)
			res=a[i];
	}
	return res;
}


int max(vector<int> &A,int begin,int end){
        if(end<begin)
                return 0;
        if(end==begin)
                return A[begin];
        int m=begin+(end-begin)/2;
        int sum,lmax,rmax;
        int i=m;sum=0;lmax=0;
        for(;i>=begin;i--){
            sum+=A[i];
        }
		lmax=sum*get_min(A,begin,m);
        i=m+1;sum=0;rmax=0;
        for(;i<=end;i++){
            sum+=A[i];
        }
		rmax=sum*get_min(A,m+1,end);
        int left=max(A,begin,m);
        int right=max(A,m+1,end);
        int max_sum=max(lmax,rmax);
        if(max_sum<left) max_sum=left;
        if(max_sum<right) max_sum=right;
    return max_sum;

}

int main()
{
	/*int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<max(a,0,n-1)<<endl;
	*/
	/*vector<vector<int> >vec;
	vector<int> temp(2);
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			int num;
			cin>>temp[j];
		}
		vec.push_back(temp);
	}
	for(int i=0;i<vec.size();i++)
		sort(vec[i].begin(),vec[i].end());
	return 0;*/
	/*int n=0;
	int m=1234;
	while(m)
	{
		n++;
		m=(m-1)&m;
	}
	cout<<n<<endl;
	return 0;*/
	ss s;
	cout<<sizeof(s)<<endl;
	return 0;
}