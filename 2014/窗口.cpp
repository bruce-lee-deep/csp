#include<iostream>
using namespace std;

struct Window{
    int x1,y1,x2,y2;
    int priority;
};
int n,m;
Window window[15];
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>window[i].x1>>window[i].y1>>window[i].x2>>window[i].y2;
        window[i].priority=i;
    }
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        int maxPriority = -1;
        int index = -1;
        for(int j = 0; j < n; ++j){
            if(x >= window[j].x1 && x <= window[j].x2 && y >= window[j].y1 && y <= window[j].y2){
                if(window[j].priority > maxPriority){
                    maxPriority = window[j].priority;
                    index = j;
                }
            }
        }
        if(index == -1){
            puts("IGNORED");
        }else{
            for(int j = 0; j < n; ++j){
                if(window[j].priority > maxPriority){
                    window[j].priority--;
                }
            }
            window[index].priority = n - 1;
            cout << index + 1 << endl;
        }
    }
    return 0;
}