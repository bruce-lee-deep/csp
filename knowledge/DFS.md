模板

```C++
void dfs(int x,int y){
	vis[x][y]=true;
  	for(int i=0;i<4;i++){
    	int nx=x+dx[i];
      	int ny=y+dy[i];

      	if(nx<0||nx>=n||ny<0||ny>n)
        	 continue;

      dfs(nx,ny);
  }
}
```
