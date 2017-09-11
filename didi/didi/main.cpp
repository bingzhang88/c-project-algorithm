#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
int helper(vector<int> &vec,int start,int end){
    if(start==end)
        return 1;
    if(start>end)
        return 0;
    int begin=vec[start];
    int i;
	int temp=start;
    for(i=start+1;i<=end;i++){
        begin^=vec[i];
        if(begin==0)
            temp=i;
    }
	if(temp==start) i=start;
	else i=temp;
    int j;
	temp=end;
    begin=vec[end];
    for(j=end-1;j>=start;j--){
        begin^=vec[j];
        if(begin==0)
            temp=j;
    }
	if(temp==end) j=end;
	else j=temp;
	if(i<j) return helper(vec,i+1,j-1)+2;
	else if(i==j) return 1;
	else if(i==end || j==start) return 1;
	else return( min(helper(vec,i+1,end-1) , helper(vec,start+1,j-1)) + 2);
}
int process()
{
	int n;
    cin>>n;
    int count=0;
	int xor = 0;
    for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		xor ^= a;
		if(a == 0 || xor ==0){
			count ++;
			xor =0;
		}
	}
	return count;
}
int main()
{
	cout<<process()<<endl;
	return 0;
}