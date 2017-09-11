#include<string>
#include<iostream>
#include<vector>
using namespace std;
void sec(){
	long long L;
	long long R;
	cin>>L;
	cin>>R;
	if(R<=10)
		cout<<0<<endl;
	else{
		string temp;
		long long num=0;
		long long flag;
		if(L<=10)
			flag=11;
		else{
			flag=L;
		}
        if(R<100){
            for(long long i=flag;i<=R;i++){	
			temp=to_string(i);
			if(temp[temp.size()-1]==temp[temp.size()-2]){
				num++;
				int tt=temp[temp.size()-1]-'0';
				i=i+(9-tt);
				}	
			}
		}
        else{
            int start=L/100;
            int end=R/100-1;
            num=end-start+1;
            num*=10;
            for(long long i=R/100*100;i<=R;i++){	
                temp=to_string(i);
                if(temp[temp.size()-1]==temp[temp.size()-2]){
                    num++;
                    int tt=temp[temp.size()-1]-'0';
                    i=i+(9-tt);
                }	
			}
            for(long long i=flag;i<100;i++){	
                temp=to_string(i);
                if(temp[temp.size()-1]==temp[temp.size()-2]){
                    num++;
                    int tt=temp[temp.size()-1]-'0';
                    i=i+(9-tt);
                }	
			}
        }
		cout<<num<<endl;
	}
}
int main(){
	sec();
	return 0;
}