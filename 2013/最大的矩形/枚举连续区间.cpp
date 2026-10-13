#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n;
long long h[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    long long ans=0;
    for(int left=1;left<=n;left++){
        long long minH=h[left];
        for(int right=left;right<=n;right++){
            minH=min(minH,h[right]);
            ans=max(ans,(right-left+1)*minH);
        }
    }
    cout<<ans<<endl;
    return 0;
}