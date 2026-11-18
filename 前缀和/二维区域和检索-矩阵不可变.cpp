#include<iostream>
#include<vector>
using namespace std;
int main(){
    int m,n,q;
    cin>>m>>n>>q;
    vector<vector<long long>>matrix(m+1,vector<long long>(n+1,0));
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int x;
            cin>>x;
            matrix[i][j]=x+matrix[i-1][j]+matrix[i][j-1]-matrix[i-1][j-1];
        }
    }

    while(q--){
        int r1,c1,r2,c2;
        cin>>
    }

}