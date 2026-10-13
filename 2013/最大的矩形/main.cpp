#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;

int n;
long long h[MAXN];
int st[MAXN], top;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    h[n+1]=0;
    long long ans=0;
    for(int i=1;i<=n;i++){
        while(top && h[st[top]]>=h[i]){
            int mid=st[top];
            top--;
            int left=st[top];
            long long width=i-left-1;
            long long area=h[mid]*width;
            ans=max(ans,area);
        }
        st[++top]=i;
    }

    cout<<ans<<endl;
    return 0;
}
