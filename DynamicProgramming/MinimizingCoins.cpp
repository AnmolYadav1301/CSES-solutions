#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

// int f(int target, vector<int>& coins, vector<int>&dp){

//     if(target<0 ){
//         return INT_MAX;
//     }
//     if(target==0){
//         return dp[target]=0;
//     }

//     if(dp[target] != -1)return dp[target];

//     int taken=INT_MAX;
//     for(int i=0;i<(int)coins.size();i++){
//         int sub = f(target-coins[i], coins, dp);
//         if(sub!=INT_MAX)taken=min(taken,sub+1);
//     }

//     return dp[target]=taken;
// }

int main(){

    int n,target; cin>>n>>target;
    vector<int>coins(n);

    for(int i=0;i<n;i++){
        cin>>coins[i];
    }

    //memoization
    // vector<int>dp(target+1,-1);
    // long long val=f(target, coins, dp);
    
    // if(val == INT_MAX)cout<<-1<<'\n';
    // else cout<<dp[target]<<'\n';

    //tabulation form
    vector<int>dp(target+1,-1);
    dp[0]=0;
    for(int curr_target=1; curr_target<=target; curr_target++){

        int taken=INT_MAX;
        for(int i=0;i<(int)coins.size();i++){
            int sub=INT_MAX;
            if(curr_target-coins[i]>=0)sub = dp[curr_target-coins[i]];
            if(sub!=INT_MAX)taken=min(taken,sub+1);
        }
        dp[curr_target]=taken;
    }

    if(dp[target]==INT_MAX)cout<<-1<<'\n';
    else cout<<dp[target]<<'\n';
    
    
}