#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;

//灵活性任务
struct FlexibleTask{
    int cups;                   //最多可以为该灵活任务所提供的咖啡数
    long double gain_per_cup;   //每杯咖啡减少的耗时b/a
};

//普通型任务
struct OrdinaryTask{
    int cups;                   //咖啡数（0或a)
    int gain;                   //耗时
};

//灵活型任务按单位咖啡收益从大到小排序，保证贪心填充最优
bool compare_flexible(const FlexibleTask &x,const FlexibleTask &y){
    return x.gain_per_cup>y.gain_per_cup;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    long double initial=0;
    vector<FlexibleTask>flexible;
    vector<OrdinaryTask>ordinary;

    for(int i=0;i<n;i++){
        int type,t,a,b;
        cin>>type>>t>>a>>b;
        initial+=t;
        if(type==0){        //灵活型
            FlexibleTask task;
            task.cups=a;
            task.gain_per_cup=(long double)b/a;
            flexible.push_back(task);
        }else{
            OrdinaryTask task;
            task.cups=a;
            task.gain=b;
            ordinary.push_back(task);
        }
    }

    //1.灵活型任务：贪心预处理
    //flexible_gain[c]表示将恰好c杯咖啡全部给灵活性任务时的总最大减少量
    sort(flexible.begin(),flexible.end(),compare_flexible);
    vector<long double>flexible_gain(m+1,0);
    for(int capacity=0;capacity<=m;capacity++){
        int left=capacity;      //left表示capacity剩余的
        long double total=0;
        for(int i=0;i<(int)flexible.size();i++){
            int use=min(left,flexible[i].cups); //如果剩余的比需要的大，那可以直接选需要的，否则就是只能给剩下的
            left-=use;
            total+=use*flexible[i].gain_per_cup;
            if(left==0) break;
        }
        flexible_gain[capacity]=total;
    }

    //2.普通型任务
    vector<long long>dp(m+1,0);
    for(int i=0;i<(int)ordinary.size();i++){
        int a=ordinary[i].cups;
        int b=ordinary[i].gain;

        for(int j=m;j>=a;j--){
            dp[j]=max(dp[j],dp[j-a]+b);
        }
    }

    //3.合并两类任务
    long double max_reduction=0;
    for(int used=0;used<=m;used++){
        long double total=dp[used]+flexible_gain[m-used];
        max_reduction=max(max_reduction,total);
    }

    cout<<fixed<<setprecision(6)<<(initial-max_reduction)<<"\n";
    return 0;
}