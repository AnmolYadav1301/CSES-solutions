#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

// int f(int a,int b, vector<vector<int>>&dp){
//     if(a<0 || b<0)return 0;
//     else if(a==b)return dp[a][b]=0;

//     if(dp[a][b]!=-1)return dp[a][b];
    
//     //greedy approach will not work here 
//     // return 1+f(min(a,b),max(a,b)-min(a,b));

//     int numOfCuts=INT_MAX;
//     for(int i=1;i<a;i++){//horizontal cut
//         numOfCuts=min(numOfCuts,f(a-i,b,dp)+f(i,b,dp)+1);
//     }
//     for(int j=1;j<b;j++){
//         numOfCuts=min(numOfCuts,f(a,b-j,dp)+f(a,j,dp)+1);
//     }
//     return dp[a][b]=numOfCuts;
    
// }
int main(){

    int a,b;cin>>a>>b;

    //memoization approach
    // vector<vector<int>>dp(a+1,vector<int>(b+1,-1));
    // cout<<f(a,b,dp);

    //tabulation approach
    vector<vector<int>>dp(a+1,vector<int>(b+1,0));
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){

            if(i==j){
                dp[i][j]=0;
                continue;
            }
            int numOfCuts=INT_MAX;
            for(int horizontal_cut=1;horizontal_cut<i;horizontal_cut++){//horizontal cut
                numOfCuts=min(numOfCuts,dp[i-horizontal_cut][j]+dp[horizontal_cut][j]+1);
            }
            for(int vertical_cut=1;vertical_cut<j;vertical_cut++){
                numOfCuts=min(numOfCuts,dp[i][j-vertical_cut]+dp[i][vertical_cut]+1);
            }
            dp[i][j]=numOfCuts;

        }
    }

    cout<<dp[a][b]<<'\n';


}