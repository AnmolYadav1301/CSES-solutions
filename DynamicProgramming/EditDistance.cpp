#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// int f(string & s1, string & s2, int i, int j, vector<vector<int>>&dp){

//     if(i<0 && j<0)return 0;// both matched
//     else  if(i<0)return j+1;//add operations
//     else if(j<0)return i+1;//remove operations

//     if(dp[i][j]!=-1)return dp[i][j];

//     if(s1[i]==s2[j]){
//         return dp[i][j]=f(s1,s2,i-1,j-1,dp);
//     }
//     else{
//         return dp[i][j]=1+min(f(s1,s2,i,j-1,dp),min(f(s1,s2,i-1,j,dp),f(s1,s2,i-1,j-1,dp)));
//     }

// }

int main(){
    string s1,s2;
    cin>>s1>>s2;
    //convert s1 into s2

    //memoization approach
    // vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,-1));
    // cout<<f(s1,s2,s1.length()-1,s2.length()-1, dp)<<endl;

    //tabulation approach
    // vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,0));
    // int n=s1.length(),m=s2.length();
    // for(int i=1;i<=n;i++)dp[i][0]=i;
    // for(int j=1;j<=m;j++)dp[0][j]=j;

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         if(s1[i-1]==s2[j-1]){
    //             dp[i][j]=dp[i-1][j-1];
    //         }
    //         else{
    //             int add=dp[i][j-1];
    //             int remove=dp[i-1][j];
    //             int replace=dp[i-1][j-1];
    //             dp[i][j]=1+min(add, min(remove,replace));
    //         }
    //     }
    // }

    // cout<<dp[n][m]<<'\n';

    //space optimisation approach

    vector<int>curr(s2.length()+1,0),prev(s2.length()+1,0);
    int n=s1.length(),m=s2.length();
    // for(int i=1;i<=n;i++)dp[i][0]=i;
    for(int j=1;j<=m;j++)prev[j]=j;

    for(int i=1;i<=n;i++){
        curr[0]=i;
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                curr[j]=prev[j-1];
            }
            else{
                int add=curr[j-1];
                int remove=prev[j];
                int replace=prev[j-1];
                curr[j]=1+min(add, min(remove,replace));
            }
        }
        prev=curr;
    }

    cout<<prev[m]<<'\n';


    

    return 0;
}