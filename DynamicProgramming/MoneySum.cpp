#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;


void print(vector<int>&ans){

    cout<<ans.size()<<'\n';

    for(auto & v: ans)cout<<v<<" ";

}
// bool f(vector<int>&coins, int idx, vector<vector<int>>&dp,int target){

//     if(idx<0)return false;
//     if(target==0)return dp[idx][target]=true;
//     if(idx==0){
//         if(target==coins[idx])return dp[idx][target]=true;
//         return dp[idx][target]=false;
//     }

//     if(dp[idx][target]!=-1)return dp[idx][target];

//     bool taken=false;
//     if(target-coins[idx]>=0)taken=f(coins,idx-1,dp,target-coins[idx]);
//     bool nottaken=f(coins,idx-1,dp,target);

//     return dp[idx][target]=taken || nottaken;
// }
int main(){

    int n;cin>>n;

    vector<int>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }

    int sum=0,min_val=INT_MAX;
    for(int val:coins){
        sum+=val;
        min_val=min(min_val,val);
    }

    // vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));

    // f(coins,n-1,dp,sum);

    // vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
    // dp[0][0]=true;
    // // for(int i=1;i<=n;i++)dp[i][coins[i-1]]=true;

    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<=sum;j++){

    //         if(j-coins[i-1]>=0)dp[i][j]=dp[i-1][j] || dp[i-1][j-coins[i-1]];
    //         else dp[i][j]=dp[i-1][j];

    //     }
    // }

    vector<bool>dp(sum+1,false),prev(sum+1,false);
    prev[0]=true;
    // for(int i=1;i<=n;i++)dp[i][coins[i-1]]=true;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){

            if(j-coins[i-1]>=0)dp[j]=prev[j] || prev[j-coins[i-1]];
            else dp[j]=prev[j];

        }
        prev=dp;
    }


    vector<int>ans;
    for(int i=min_val;i<=sum;i++){
        if(dp[i])ans.push_back(i);
    }

    print(ans);

}