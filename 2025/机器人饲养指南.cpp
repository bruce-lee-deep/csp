#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<long long>happiness(m+1,-(1LL<<60));
    for(int i=1;i<=m;i++){
        cin>>happiness[i];
    }

    vector<long long>dp(n+1,0);
    dp[0]=0;
    for(int apples=1;apples<=n;apples++){
        int limit=min(m,apples);
        for(int today=1;today<=limit;today++){
            dp[apples]=max(dp[apples],dp[apples-today]+happiness[today]);
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}