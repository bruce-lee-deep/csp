/*#include<iostream>
#include<vector>
using namespace std;
int n;
vector<vector<int>>map(n,vector<int>(n,0));

int searchPosition(int x,int y){
    int res=0;
    if(x<0||y<0||x>n-1||y>n-1){
        return res;
    }else{
        res=res+searchPosition(x+1,y+2)+searchPosition(x+1,y-2)+searchPosition(x-1,y+2)+searchPosition(x-1,y-2)+searchPosition(x+2,y+1)+searchPosition(x+2,y-1)+searchPosition(x-2,y+1)+searchPosition(x-2,y-1);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k,x,y;
    cin>>n,k;
    cin>>x,y;
    cout<<1+searchPosition(x,y); 
    return 0;

}*/


#include<iostream>
#include<vector>
#include<queue>
#include<cstring>


using namespace std;
int main(){
    int n,k,x,y;
    cin>>n>>k>>x>>y;
    int map[105][105];
    memset(map,-1,sizeof(map));
    int dx[8]={1,1,2,2,-1,-1,-2,-2};
    int dy[8]={2,-2,1,-1,2,-2,1,-1};
    queue<pair<int,int>>que;
    que.push(make_pair(x,y));
    map[x][y]=0;
    while(!que.empty()){
        pair<int,int>start=que.front();
        que.pop();
        int x=start.first;
        int y=start.second;
        if(map[x][y]>=k)continue;
        for(int i=0;i<8;i++){
            if(x+dx[i]<1||x+dx[i]>n||y+dy[i]<1||y+dy[i]>n){
                continue;
            }
            if(map[x+dx[i]][y+dy[i]]==-1){
                map[x+dx[i]][y+dy[i]]=map[x][y]+1;
                que.push(make_pair(x+dx[i],y+dy[i]));
            }else continue;
        }
    }

    int res=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(map[i][j]>=0&&map[i][j]<=k){
                res++;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
