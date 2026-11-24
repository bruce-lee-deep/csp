/*#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void fill_board(int x,int y,char c,vector<vector<char>> &board){
    board[x][y]=c;
    int pos_x[]={-1,1};
    int pos_y[]={-1,1};
    int m=board.size();
    int n=board[0].size();
    for(int i=0;i<2;i++){
        int new_x=x+pos_x[i];
        for(int j=0;j<2;j++){
            int new_y=y+pos_y[j];
            if(new_x<0||new_x>(n-1)||new_y<0||new_y>(m-1)||(!board[new_x][new_y]=='c')){
                return;
            }else{
                fill_board(new_x,new_y,c,board);
            }
        }
    }
}
int main(){
    int m,n,q;
    cin>>m>>n>>q;
    vector<vector<char>>board(m,vector<char>(n,'.'));\
    for(int i=0;i<q;i++){
        string s;
        cin>>s;
        if(s[0]=='0'){
            int x1=s[1],y1=s[2],x2=s[3],y2=s[4];
            if(x1==x2){ //横坐标相等，竖着画
                int max_y=max(y1,y2);
                int min_y=min(y1,y2);
                for(int j=min_y;j<=max_y;j++){
                    if(board[x1][n-j-1]=='-'){
                        board[x1][n-j-1]='+';
                    }else{
                        board[x1][n-j-1]='|';
                    }
                }
            }else if(y1==y2){
                int max_x=max(x1,x2);
                int min_x=min(x1,x2);
                for(int j=min_x;j<=max_x;j++){
                    if(board[x1][n-j-1]=='|'){
                        board[x1][n-j-1]='+';
                    }else{
                        board[x1][n-j-1]='-';
                    }
                }
            }
        }else{
            int x=s[1],y=n-s[2]-1;
            char c=s[3];
            fill_board(x,y,c,board);
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }
    return 0;
}*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

bool is_wall(char ch) {
    return ch == '-' || ch == '|' || ch == '+';
}

void draw_line(int x1, int y1, int x2, int y2,
               vector<string>& board) {
    if (x1 == x2) {
        // 竖线：x 不变，y 变化
        for (int y = min(y1, y2); y <= max(y1, y2); ++y) {
            char& cell = board[y][x1];
            cell = (cell == '-' || cell == '+') ? '+' : '|';
        }
    } else {
        // 横线：y 不变，x 变化
        for (int x = min(x1, x2); x <= max(x1, x2); ++x) {
            char& cell = board[y1][x];
            cell = (cell == '|' || cell == '+') ? '+' : '-';
        }
    }
}

void fill_board(int x, int y, char color, vector<string>& board) {
    int height = board.size();
    int width = board[0].size();
    if (is_wall(board[y][x])) return;

    vector<vector<bool>> visited(height, vector<bool>(width, false));
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[y][x] = true;

    const int dx[] = {1, -1, 0, 0};
    const int dy[] = {0, 0, 1, -1};

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        board[cy][cx] = color;

        for (int d = 0; d < 4; ++d) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if (nx < 0 || nx >= width || ny < 0 || ny >= height)
                continue;
            if (visited[ny][nx] || is_wall(board[ny][nx]))
                continue;

            // 入队时就标记，避免同一个格子重复入队
            visited[ny][nx] = true;
            q.push({nx, ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n, q; // m 是宽，n 是高
    cin >> m >> n >> q;

    vector<string> board(n, string(m, '.'));

    for (int i = 0; i < q; ++i) {
        int op;
        cin >> op;

        if (op == 0) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            draw_line(x1, y1, x2, y2, board);
        } else {
            int x, y;
            char color;
            cin >> x >> y >> color;
            fill_board(x, y, color, board);
        }
    }

    for (int y = n - 1; y >= 0; --y) {
        cout << board[y] << '\n';
    }

    return 0;
}
