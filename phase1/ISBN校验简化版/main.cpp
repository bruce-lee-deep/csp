#include<iostream>
using namespace std;
int main(){
    string str;
    int s=0;
    cin>>str;
    if(str.length()!=10){
        return 1;
    }
    for(int i=0;i<9;i++){
        int num=str[i]-'0';
        s+=num*(i+1);
    }
    int t=s%11;
    if((t==10&&str[9]=='X')||(t==str[9]-'0')){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}