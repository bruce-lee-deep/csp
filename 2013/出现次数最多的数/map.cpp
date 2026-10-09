#include<iostream>
#include<map>
using namespace std;
int main(){
    int n;
    cin>>n;
    map<int,int>cnt;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        cnt[x]++;
    }
    int ans=0,maxCnt=0;
    for(auto&[val,c]:cnt){
        if(c>maxCnt){
            maxCnt=c;
            ans=val;
        }
    }
    cout<<ans<<endl;
}