#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

int count_value[1005];

struct Item{
    int value;
    int count;
};

bool compare_item(const Item &left,const Item &right){
    if(left.count!=right.count) return left.count>right.count;
    return left.value<right.value;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int number;
        cin>>number;
        count_value[number]++;
    }

    vector<Item>items;
    for(int i=0;i<=1000;i++){
        if(count_value[i]!=0){
            Item current={i,count_value[i]};
            items.push_back(current);
        }
    }

    sort(items.begin(),items.end(),compare_item);

    for(int i=0;i<(int)items.size();i++){
        cout<<items[i].value<<" "<<items[i].count<<endl;
    }

    return 0;
}