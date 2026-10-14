#include<iostream>
#include<cmath>
using namespace std;
const int maxValue=1e3+5;
int bucket[maxValue];
const int N=500;
int num[N];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(bucket[abs(num[i])]!=0&&(bucket[abs(num[i])]+num[i]==0)){
            ans++;
        }else{
            bucket[abs(num[i])]=num[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}

