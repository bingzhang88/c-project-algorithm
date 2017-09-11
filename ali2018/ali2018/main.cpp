#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int Get(int n)
{
	int x;
	long long start=1;
	int sum=0;
	n-=1;
	string s;
	string temp="1";
	while(n>=s.size()+temp.size())
	{
		s.append(to_string(start));
		n-=s.size();
		start++;
		temp=to_string(start);

	}
	s.append(to_string(start));
	x=s[n]-'0';
	return x;
}

int main()
{
	for(int i=1;i<10000;i++)
		cout<<Get(i);
	cout<<endl;
	return 0;
}