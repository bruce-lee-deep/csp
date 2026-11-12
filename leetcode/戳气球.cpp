#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a(n+2,1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<vector<long long>>dp(n+2,vector<int>(n+2,0));
    for(int len=2;len<=n+1;len++){
        for(int i=0;i+len<=n+1;i++){
            int j=i+len;
            for(int k=i+1;k<j;k++){
                long long coins=
                    dp[i][k]+
                    dp[k][j]+
                    1LL*a[i]*a[k]*a[j];
                
                dp[i][j]=max(dp[i][j],coins);
            }
        }
    }
    cout<<dp[0][n+1]<<endl;
    return 0;
}