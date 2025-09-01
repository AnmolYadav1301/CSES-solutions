#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int mod=1e9 + 7;

// int f(vector<int>&coins, int DesiredSum , vector<int>&dp){

//     if( DesiredSum < 0){
//         return 0;
//     }
//     if(DesiredSum==0){
//         return dp[DesiredSum]=1;
//     }
//     if(dp[DesiredSum]!=-1)return dp[DesiredSum];

//     int taken=0;
//     for(int i=0;i<(int)coins.size();i++){
//         taken=(taken+f(coins,DesiredSum-coins[i],dp))%mod;
//     }
    
//     return dp[DesiredSum]=(taken)%mod;
// }

int main(){

    //memoization form
    int numOfCOins,DesiredSum;cin>>numOfCOins>>DesiredSum;
    vector<int>coins(numOfCOins);
    for(int i=0;i<(int)numOfCOins;i++){
        cin>>coins[i];
    }
    // vector<int>dp(DesiredSum+1,-1);
    // cout<<f(coins, DesiredSum,dp);

    //tabulation form 
    vector<int>dp(DesiredSum+1);
    dp[0]=1;
    for(int target=1;target<=DesiredSum;target++){
        for(int i=0;i<(int)coins.size();i++){
            if(target-coins[i]>=0)dp[target]=(dp[target]+dp[target-coins[i]])%mod;
        }
    }
    cout<<dp[DesiredSum];

}