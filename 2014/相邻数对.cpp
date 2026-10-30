#include<iostream>
#include<algorithm>
using namespace std;
const int maxN=1e3+5;
int numbers[maxN];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>numbers[i];
    }
    sort(numbers,numbers+n);
    int ans=0;
    for(int i=1;i<n;i++){
        if(numbers[i]-numbers[i-1]==1){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}