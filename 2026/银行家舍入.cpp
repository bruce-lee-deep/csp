#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    float data[n];
    for(int i=0;i<n;i++){
        cin>>data[i];
    }

    for(int i=0;i<n;i++){
        float dis=data[i]-(int)data[i];
        if(dis>=0.5){
            cout<<(int)data[i]+1<<" ";
        }else{
            cout<<(int)data[i]<<" ";
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        float dis=data[i]-(int)data[i];
        if(dis>0.5){
            cout<<(int)data[i]+1<<" ";
        }else if(dis==0.5){
            if((int)data[i]%2==0){
                cout<<(int)data[i]<<" ";
            }else{
                cout<<(int)data[i]+1<<" ";
            }
        }else{
            cout<<(int)data[i]<<" ";
        }
    }
    return 0;
}