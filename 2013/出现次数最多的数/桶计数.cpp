//给定n n 个正整数，输出出现次数最多的那个数；若有多个数并列最多，输出其中最小的数。
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> numbers(n);
    for(int i=0;i<n;i++){
        cin>>numbers[i];
    }
    vector<int>count(10001,0);
    for(int i=0;i<n;i++){
        if(numbers[i]!=0){
            count[numbers[i]]++;
        }
    }
    int maxCount=0;
    for(int i=1;i<=10000;i++){
        if(count[i]>maxCount){
            maxCount=count[i];
        }
    }
    for(int i=1;i<=10000;i++){
        if(count[i]==maxCount){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}