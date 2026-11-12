#include<bits/stdc++.h>
using namespace std;

const long long INF=40000000000000000LL;

//一个进程接口对应的队列：占用的空间与最近一次写入位置
struct QueueInfo{
    long long left;
    long long right;
    long long last;

};

map<long long,long long>free_by_left;
set<pair<long long,long long>>free_by_size;

void erase_free(long long left){
    map<long long,long long>::iterator it=free_by_left.find(left);
    long long right=it->second;
    free_by_left.erase(make_pair(right-left+1,left));
    free_by_size.erase(it);
}

void add_free(long long left,long long right){
    map<long long,long long>::iterator it=free_by_left.lower_bound(left);
    if(it!=free_by_left.begin()){
        map<long long,long long>::iterator previous=it;
        --previous;
        if(previous->second+1>=left){
            left=previous->first;
            right=max(right,previous->second);
            erase_free(previous->first);
        }
    }

    it=free_by_left.lower_bound(right);
    while(it!=free_by_left.end()&&it->first<=right+1){
        right=max(right,it->second);
        map<long long,long long>::iterator next=it;
        ++next;
        erase_free(it->first);
        it=next;
    }
    free_by_left[left]=right;
    free_by_size.insert(make_pair(right-left+1,left));
}
int main(){

}