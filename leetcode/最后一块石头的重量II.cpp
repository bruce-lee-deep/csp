#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    int sum=0;
    cin>>n;
    vector<int>stones(n,0);
    for(int i=0;i<n;i++){
        cin>>stones[i];
        sum+=stones[i];
    }
    //背包容量
    int bag=sum/2;
    vector<int>dp(bag+1,0);
    for(int i=0;i<n;i++){
        for(int j=bag;j>=stones[i];j--){
            dp[j]=max(dp[j],dp[j-stones[i]]+stones[i]);
        }
    }
    cout<<sum-2*dp[bag]<<endl;
    return 0;
}