#include<stdio.h>  
#include<string>  
#include<stdlib.h>  
#include<math.h>  
#include<vector>  
#include<iostream>  
using namespace std;

string en_s[10]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
string zh_s[10]={"Ling","Yi","Er","San","Si","Wu","Liu","Qi","Ba","Jiu"};
string double_s="Double";

void process()
{
	string res;
	string s;
	//cin>>s;
	getline(cin,s);
	if(s[0]<65 || s[0]>90)
	{
		cout<<"ERROR"<<endl;
		return;
	}
	vector<int>index;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>=65 && s[i]<=90)
			index.push_back(i);
	}
	bool double_flag=false;
	for(int i=0;i<index.size();i++)
	{
		string temp;
		if(i<index.size()-1)
		{
			//temp=s(s.begin()+index[i],s.begin()+index[i+1]);
			temp.assign(s.begin()+index[i],s.begin()+index[i+1]);
		}
		else
		{
			//temp=s(s.begin()+index[i],s.end());
			temp.assign(s.begin()+index[i],s.end());
			if(temp==double_s)
			{
				cout<<"ERROR"<<endl;
				return;
			}
		}
		if(temp==double_s && double_flag==false)
		{
			double_flag=true;
			continue;
		}
		else if(temp==double_s && double_flag==true)
		{
			cout<<"ERROR"<<endl;
			return;
		}
		int j;
		for(j=0;j<10;j++)
		{
			if(temp==en_s[j])
			{
				res+=zh_s[j];
				if(double_flag==true)
				{
					double_flag=false;
					res+=zh_s[j];
				}
				break;
			}
			else if(temp==zh_s[j])
			{
				res+=en_s[j];
				if(double_flag==true)
				{
					double_flag=false;
					res+=en_s[j];
				}
				break;
			}
			else if(temp==double_s)
				break;
		}
		if(j==10)
		{
			cout<<"ERROR"<<endl;
			return;
		}
	}
	cout<<res<<endl;
	return;
}
int main()
{
	process();
	return 0;
}