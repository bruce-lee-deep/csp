#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    int n;
    cin>>n;
    unordered_map<int,int>cnt;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        cnt[x]++;
    }
    int ans=0,maxCnt=0;
    for(auto&[val,c]:cnt){
        if(c>maxCnt||(c==maxCnt&&val<ans)){//unordered_map虽然快但是遍历顺序是不确定的，所以需要自己手动处理并列
            maxCnt=c;
            ans=val;
        }
    }
    cout<<ans<<endl;
}