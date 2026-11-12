时间复杂度：O(V+E)

标准模板

```C++
#include<iostream>
#include<vector>
#include<queue>
using namaspace std;
void bfs(const vector<vector<int>>& graph,int start){
	int n=graph.size();
    vector<bool>visited(n,false);
    queus<int>q;

    q.push(start);
    visited[start]=true;

    while(!q.empty()){
    	int u=q.front();
        q.pop();

        for(int v: graph[u]){
        	if(!visited[v]){
              	visited[i]=true;
              q.push(v);
            }
        }
    }
}
```
