#include<iostream>
using namespace std;
int main(){
    string isbn;
    cin>>isbn;
    int sum=0;
    int cnt=1;
    for(size_t i=0;i<isbn.size()-1;i++){
        if(isbn[i]=='-')continue;
        sum+=(isbn[i]-'0')*cnt;
        cnt++;
    }
    int mod=sum%11;
    int last=isbn.size()-1;
    if(mod==10){
        if(isbn[last]=='X'){
            cout<<"Right"<<endl;
        }else{
            isbn[last]='X';
            cout<<isbn<<endl;
        }
    }else{
        if(mod==isbn[last]-'0'){
            cout<<"Right"<<endl;
        }else{
            isbn[last]=mod+'0';
            cout<<isbn<<endl;
        }
    }
    return 0;
}