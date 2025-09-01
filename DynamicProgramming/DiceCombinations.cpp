#include<iostream>
#include<vector>

using namespace std;

const int mod = 1e9 + 7;

int f(int target, vector<int>&dp){
    if(target<0){
        return 0;
    }

    if(target==0){
        return dp[target]=1;
    }

    if(dp[target]!=-1)return dp[target];
    

    int taken=0;
    for(int numOnDice=1;numOnDice<=6;numOnDice++){
        taken=(taken+f(target-numOnDice, dp)) % mod;
    }

    return dp[target]=taken;

}

int main(){
    int n;cin>>n;

    // vector<int>dp(n+1,-1);
    // cout<<f(n,dp)<<'\n';

    // vector<vector<int>>dp(7,vector<int>(n+1,0));

    //tabulation form 
    vector<int>dp(n+1);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        int taken=0;
        for(int numOnDice=1;numOnDice<=6;numOnDice++){
           if(i-numOnDice>=0) taken = (taken + dp[i-numOnDice]) % mod;
        }
        dp[i]=taken;
    }
    cout<<dp[n]<<'\n';


    return 0;
}