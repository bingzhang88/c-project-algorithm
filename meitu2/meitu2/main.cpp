#include<iostream>
#include<vector>
using namespace std;
void sec(){
    int n,r;
    cin>>n>>r;
    vector<int> temp;
    vector<vector<int> > v;
    int a;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            cin>>a;
            temp.push_back(a);
        }
        v.push_back(temp);
        temp.clear();
    }
    vector<vector<int> > result(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int tt=v[i][j];
            if(i-1>=0&&i-1<n)
                tt+=v[i-1][j];
            if(i+1>=0&&i+1<n)
                tt+=v[i+1][j];
            if(j-1>=0&&j-1<n)
                tt+=v[i][j-1];
            if(j+1>=0&&j+1<n)
                tt+=v[i][j+1];
            if(i-1>=0&&i-1<n&&j-1>=0&&j-1<n)
                tt+=v[i-1][j-1];
            if(i-1>=0&&i-1<n&&j+1>=0&&j+1<n)
            	tt+=v[i-1][j+1];
            if(i+1>=0&&i+1<n&&j+1>=0&&j+1<n)
                tt+=v[i+1][j+1];
            if(i+1>=0&&i+1<n&&j-1>=0&&j-1<n)
                tt+=v[i+1][j-1];
            result[i][j]=tt;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            cout<<result[i][j]<<' ';
        }
        cout<<result[i][n-1]<<endl;
    }
}
int main(){
    sec();
    return 0;
}

