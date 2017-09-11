#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> >res;
vector<int> vec;

void helper(int start,int end,int sum){
    if(sum==0)
        res.push_back(vec);
    else if(sum>0){
        for(int i=start;i<=end;i++){
            vec.push_back(i);
            helper(i+1,end,sum-i);
            vec.erase(vec.end()-1);
        }
    }
}

void process(void){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        vec.push_back(i);
        helper(i+1,n,m-i);
        vec.erase(vec.end()-1);
    }
    return;
}

int main()
    {
    process();
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            if(j==0){
                cout<<res[i][j];
            }
            else{
                cout<<" "<<res[i][j];
            }
        }
        cout<<endl;
    }
    return 0;
}