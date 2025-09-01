#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int mod=1e9 + 7;

// int f(vector<int>&coins, int DesiredSum , vector<vector<int>>&dp ,int index){

//     if( DesiredSum < 0 || index>=(int)coins.size()){
//         return 0;
//     }
//     if(index==coins.size()-1){
//         if(DesiredSum%coins[index]==0)return dp[index][DesiredSum]=1;
//     }
//     if(DesiredSum==0){
//         return dp[index][DesiredSum]=1;
//     }
//     if(dp[index][DesiredSum]!=-1)return dp[index][DesiredSum];

//     int taken=0,nottaken=0;
    
//     if(DesiredSum-coins[index]>=0)taken=f(coins,DesiredSum-coins[index],dp,index);
//     nottaken=f(coins, DesiredSum,dp,index+1);
    
//     return dp[index][DesiredSum]=(taken + nottaken)%mod;

// }

int main(){

    //memoization form
    int numOfCOins,DesiredSum;cin>>numOfCOins>>DesiredSum;
    vector<int>coins(numOfCOins);
    for(int i=0;i<(int)numOfCOins;i++){
        cin>>coins[i];
    }
    // vector<vector<int>>dp(numOfCOins,vector<int>(DesiredSum+1,-1));
    // cout<<f(coins, DesiredSum, dp, 0);

    // tabulation form 
    vector<vector<int>>dp(numOfCOins+1,vector<int>(DesiredSum+1,0));
    for(int i=0;i<numOfCOins;i++)dp[i][0]=1;

    for(int j=numOfCOins-1;j>=0;j--){
        for(int i=1;i<=DesiredSum;i++){

            int taken=0,nottaken=0;
            
            if(i-coins[j]>=0)taken=dp[j][i-coins[j]];
            nottaken = dp[j+1][i];
            
            dp[j][i] = (taken + nottaken)%mod;

        }
    }
    cout<<dp[0][DesiredSum]<<'\n';

    //space optimized tabulation form
    
    
    return 0;
}