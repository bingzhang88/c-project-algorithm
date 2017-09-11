#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

void process()
{

	return;
}

int foo(int a)
{
	cout<<a<<endl;
	return a<0?a:foo(--a)-1;
}

int main()
{
	int x=5;
	int y=x++*3;
	cout<<foo(10);
	process();
	return 0;
}
