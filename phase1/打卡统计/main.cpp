#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n,k,m;
    int allOfDays=0;
    int longestDays=0;
    int temp=0;
    cin>>n>>k>>m;
    vector<int> days(n);
    for(int i=0;i<n;i++){
        cin>>days[i];
        if(days[i]==0){
            longestDays=max(longestDays,temp);
            temp=0;
        }
        else{
            temp++;
            allOfDays++;
        }
    }
    longestDays=max(longestDays,temp);
    cout<<allOfDays<<endl;
    cout<<longestDays<<endl;
    if(allOfDays>=k&&longestDays>=m){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
