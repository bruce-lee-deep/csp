#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int m,n;
    vector<string>strs;
    while(true){
        string s;
        cin>>s;
        strs.push_back(s);
    }

    cin>>m>>n;
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    for(const string& s:strs){
        int zero=0,one=0;
        for(char c:s){
            if(c=='0'){
                zero++;
            }else{
                one++;
            }
        }
        for(int i=m;i>=zero;i--){
            for(int j=n;j>=one;j--){
                dp[i][j]=max(dp[i][j],dp[i-zero][j-one]+1);
            }
        }
    }

    cout<<dp[m][n]<<endl;
    return 0;
}