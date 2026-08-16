#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,k,t;
    int count=0;
    cin>>n>>t>>k;
    vector<int>tem(n);
    for(int i=0;i<n;i++){
        cin>>tem[i];
        if(tem[i]>=t){
            count++;
            if(count>=k){
                cout<<"YES"<<" "<<i+1<<endl;
                return 0;
            }
        }
        else{
            count=0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
