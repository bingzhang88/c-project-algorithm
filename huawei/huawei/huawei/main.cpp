#include <string>
#include <vector>
#include<iostream>
#include <algorithm>
using namespace std;
int main()
{
    long long num;
    while(cin>>num)
    {
        string str(to_string(num));
        int n=str.size();
        vector<string> dp(n);
        dp[0]=str[0];
        for(int i=1;i<n;i++)
        {
            char a=str[i];
            int dex=dp[i-1].find(a);
            if(dex==-1)
            {
                dp[i]=dp[i-1]+a;

            }
            else
            {
                string s=dp[i-1].substr(0,dex)+dp[i-1].substr(dex+1)+a;
                long long cur=stol(s);
                long long pre=stol(dp[i-1]);
                if(cur>pre)
                    dp[i]=to_string(cur);
                else
                    dp[i]=dp[i-1];
            }
        }

        cout<<dp[n-1]<<endl;
    }


    return 0;
}
