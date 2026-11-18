#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;

    vector<long long>pre(n+1,0);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        pre[i+1]=pre[i]+x;
    }

    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<pre[r+1]-pre[l]<<endl;
    }
    return 0;

}
