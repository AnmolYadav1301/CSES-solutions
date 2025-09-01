#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

// int f(vector<int>& prices, vector<int>&pages, int max_expense, int ind, vector<vector<int>>&dp){

//     if( max_expense < 0 || ind < 0 )return 0;
//     if(dp[ind][max_expense]!=-1)return dp[ind][max_expense];
//     int taken=INT_MIN, nottaken=INT_MIN;

//     if(max_expense-prices[ind]>=0)taken=f(prices,pages,max_expense-prices[ind],ind-1,dp)+pages[ind];
//     nottaken=f(prices,pages,max_expense,ind-1,dp);

//     return dp[ind][max_expense]=max(taken,nottaken);


// }
int main(){

    int n,x;cin>>n>>x;
    vector<int>prices(n);
    vector<int>pages(n);
    for(int i=0;i<n;i++)cin>>prices[i];
    for(int i=0;i<n;i++)cin>>pages[i];

    //memoization form
    // vector<vector<int>>dp(n+1,vector<int>(x+1,-1));
    // cout<<f(prices,pages,x,n-1,dp);

    //tabulation form
    // vector<vector<int>>dp(n+1,vector<int>(x+1,0));
    // for(int booksexplored=1;booksexplored<=n;booksexplored++){
    //     for(int costAvailable=0;costAvailable<=x;costAvailable++){
        
    //         int taken=0,nottaken=0;
    //         if(costAvailable-prices[booksexplored-1]>=0 )taken=pages[booksexplored-1]+dp[booksexplored-1][costAvailable-prices[booksexplored-1]];
    //         nottaken=dp[booksexplored-1][costAvailable];

    //         dp[booksexplored][costAvailable]=max(taken,nottaken);
    //     }
    // }

    // cout<<dp[n][x]; //dp[i][j] represent with the first i books and with budget j how many max pages u can get

    //space optimisation
    vector<int>prev(x+1,0),curr(x+1);
    for(int booksexplored=1;booksexplored<=n;booksexplored++){
        for(int costAvailable=0;costAvailable<=x;costAvailable++){
        
            int taken=0,nottaken=0;
            if(costAvailable-prices[booksexplored-1]>=0 )taken=pages[booksexplored-1]+prev[costAvailable-prices[booksexplored-1]];
            nottaken=prev[costAvailable];

            curr[costAvailable]=max(taken,nottaken);
        }
        prev=curr;
    }
    cout<<prev[x];


}