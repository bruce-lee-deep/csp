#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int num[n]={0};
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>num[i];
        int numOf1=0,numOf0=0; 
        while(num[i]!=0){
            if(num[i]%2==0){
                numOf0++;
            }else{
                numOf1++;
            }
            num[i]=num[i]/2;
        }
        if(numOf1==numOf0){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
    
}