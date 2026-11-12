#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>nums;
    while(true){
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }
    int n=nums.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
    }
    if(sum%2!=0)return 0;
    int target=sum/2;
    //dp[i]表示能否凑出i
    vector<bool>dp(target+1,false);
    dp[0]=true;
    for(int num:nums){
        for(int i=target;i>=num;i--){
            dp[i]=dp[i]||dp[i-num];
        }
    }
    cout<<dp[target]<<endl;
    return 0;
}