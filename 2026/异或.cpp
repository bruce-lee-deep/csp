/*#include<iostream>
#include<vector>
using namespace std;

long long k;

//处理异或的函数
long long xor_func(long long a,long long b){
    long long res=0;
    long long bit=1;
    while(a>0||b>0){
        long long x=a%k;
        long long y=b%k;
        res+=(x+y)%k*bit;
        bit*=k;
        a/=k;
        b/=k;
    }
    return res;
}

long long func_n(long long n){
    if(n==0) return 0;
    return xor_func(n,func_n(n-1)); 
}
void opreation1(long long &l,long long &r,long long &v,vector<long long> &queue){
    for(int i=l;i<=r;i++){
        queue[i]=xor_func(queue[i],v);
    }
}

long long operation2(long long &l,long long &r,vector<long long> &queue){
    long long res=func_n(queue[l]);
    for(int i=l+1;i<=r;i++){
        res=xor_func(res,func_n(queue[i]));
    }
    return res;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n,m;
    cin>>n>>m>>k;

    vector<long long>queue(n+1);
    vector<vector<long long>>operation(m+1,vector<long long>(4));
    
    for(int i=1;i<=n;i++){
        cin>>queue[i];
    }

    while(m){
        cin>>operation[m][0]>>operation[m][1]>>operation[m][2];
        if(operation[m][0]==1){
            cin>>operation[m][3];
            opreation1(operation[m][1],operation[m][2],operation[m][3],queue);
        }else{
            cout<<operation2(operation[m][1],operation[m][2],queue)<<endl;
        }
        m--;
    }
    return 0;
}*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN=500000;
const int MAXM=10000;
const int MAXD=20;
const int MAXNODE=MAXN*4+5;

struct Operation{
    int type;
    int l;
    int r;
    long long v;
};

struct Info{
    int s0;         //第0位d0之和
    int s00;        //d0^2之和
    int sp[MAXD];   //第p位dp之和
    int sp0[MAXD];  //dp^2之和
};

int n,m;
long long base_k;
int digits;         //当前有效位数
vector<long long>value_array;
vector<Operation>operations;

int sum0[MAXNODE];
int sum00[MAXNODE];
int sum_p[MAXD][MAXNODE];
int sum_p0[MAXD][MAXNODE];
int lazy_shift[MAXD][MAXNODE];  //懒标记：每个数位当前平移量

//把x拆成K进制各位，结果写入result[0..digits-1]
void split_digits(long long x,int result[MAXD]){
    for(int i=0;i<MAXD;i++){
        result[i]=0;
    }
    for(int i=0;i<digits;i++){
        result[i]=(int)(x%base_k);
        x/=base_k;
    }
}

//给节点P的整体加shift：所有位各自平移。length是节点覆盖的区间长度
//核心是利用完全平方公式：(d+c)^2=d^2+2cd+c^2逐项更新各统计量

void apply_shift(int p,int length,int shift[MAXD]){
    int old_s0=sum0[p];     //保存旧的节点P所有元素的第0位的d0的和
    int old_s00=sum00[p];
    int s0_shift=shift[0];
    long long len_mod=length%base_k;

    //更新sum0和sum00
    sum0[p]=(int)((old_s0+len_mod*s0_shift)%base_k);
    sum00[p]=(int)((old_s00+2LL*s0_shift*old_s0+len_mod*s0_shift%base_k*s0_shift)%base_k);

    for(int digit=1;digit<digits;digit++){
        int old_sp=sum_p[digit][p];
        int old_sp0=sum_p0[digit][p];
        int digit_shift=shift[digit];

        long long next_sp0=old_sp0;
        next_sp0+=1LL*s0_shift*old_sp;
        next_sp0+=1LL*digit_shift*old_s0;
        next_sp0+=len_mod*digit_shift%base_k*s0_shift;
        sum_p[digit][p]=(int)((old_sp+len_mod*digit_shift)%base_k);
        sum_p0[digit][p]=(int)(next_sp0%base_k);
    }

    for(int digit=0;digit<digits;digit++){
        lazy_shift[digit][p]=(int)((lazy_shift[digit][p]+shift[digit])%base_k);
    }
}

//用左右孩子合并当前节点的统计量
void pull(int p){
    int left=p*2;
    int right=left+1;
    sum0[p]=(int)((sum0[left]+(long long)sum0[right])%base_k);
    for(int digit=1;digit<digits;digit++){
        sum_p[digit][p]=(int)((sum_p[digit][left]+(long long)sum_p[digit][right])%base_k);
        sum_p0[digit][p]=(int)((sum_p0[digit][left]+(long long)sum_p0[digit][right])%base_k);
    }
}

//建树：叶子节点直接保存原数的各位统计量
void build(int p,int l,int r){
    if(l==r){
        int digit_value[MAXD];
        split_digits(value_array[l],digit_value);
        sum0[p]=digit_value[0]%base_k;
        sum00[p]=(int)(1LL*digit_value[0]*digit_value[0]%base_k);
        for(int digit=1;digit<=digits;digit++){
            sum_p[digit][p]=digit_value[digit]%base_k;
            sum_p0[digit][p]=(int)(1LL*digit_value[digit]*digit_value[0]%base_k);
        }
        return;
    }
    int mid=(l+r)/2;
    build(p*2,1,mid);
    build(p*2+1,mid+1,r);
    pull(p);
}

//把节点p的懒标记下传给两个孩子
void push_down(int p,int l,int r){
    bool has_lazy=false;
    int shift[MAXD];
    for(int digit=0;digit<=digits;digit++){
        shift[digit]=lazy_shift[digit][p];
        if(shift[digit]!=0){
            has_lazy=true;
        }
    }
    if(!has_lazy||l==r){
        return;
    }
    int mid=(l+r)/2;
    apply_shift(p*2,mid-l+1,shift);
    apply_shift(p*2+1,r-mid,shift);
    for(int digit=0;digit<digits;digit++){
        lazy_shift[digit][p]=0;
    }
}


