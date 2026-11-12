#include<iostream>
using namespace std;

int b;
int c;
int func(int x){
    return x*x+b*x+c;
}

int main(){
    int l,r;
    cin>>b>>c>>l>>r;
    int first;
    if(l%2==0){
        first=l;
    }else{
        first=l+1;
    }

    int s=0;
    for(int i=first;i<=r;i+=2){
        s+=func(i);
    }
    s*=2;
    cout<<s<<endl;
    return 0;
}