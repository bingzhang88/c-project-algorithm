#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

int helper(vector<long long> &vec,int start,int end,int day)
{
  int val;
  int temp1,temp2;
  if(start>end)
	  return 0;
  temp1=(vec[start]*day+helper(vec,start+1,end,day+1));
  temp2=(vec[end]*day+helper(vec,start,end-1,day+1));
  if(temp1>temp2)
    val=temp1;
  else
    val=temp2;
  return val;
}


void process() 
{
  int n;
  //cin>>n;
  scanf("%d",&n);
  vector<long long> vec(n);
  for(int i=0;i<n;i++)
  {
    //cin>>vec[i];
    scanf("%ld",&vec[i]);
  }
  int start=0,end=n-1;
  long long val=0;
  long long day=1;
  int temp1,temp2;
  temp1=vec[0]*day+helper(vec,1,end,day+1);
  temp2=vec[end]*day+helper(vec,0,end-1,day+1);
  if(temp1>temp2)
    val=temp1;
  else
    val=temp2;
  cout<<val<<endl;
  return;
}


int main()
{
  process();
  return 0;
}