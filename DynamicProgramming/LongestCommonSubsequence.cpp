#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// int f(vector<int>&a1, vector<int>& a2, int i, int j){

//     if(i==a1.size() || j==a2.size())return 0;

//     if(a1[i]==a2[j]){
//         return 1+f(a1,a2,i+1,j+1);
//     }
//     else{
//         return max(f(a1,a2,i+1,j),f(a1,a2,i,j+1));
//     }
// }

int main(){

    int n,m;cin>>n>>m;
    vector<int>a1(n),a2(m);
    for(int i=0;i<n;i++)cin>>a1[i];
    for(int j=0;j<m;j++)cin>>a2[j];
    //memoization approach
    // cout<<f(a1,a2,0,0);

    vector<vector<int>>dp(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a1[i-1]==a2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[n][m]<<'\n';

    int len=dp[n][m];
    vector<int>ans(len);
    len--;
    int i=n,j=m;
    while(i>0 && j>0){
        if(a1[i-1]==a2[j-1]){
            ans[len--]=a1[i-1];
            i--,j--;
        }
        else{
            if(dp[i-1][j]==dp[i][j])i--;
            else j--;
        }
    }

    for(auto v:ans)cout<<v<<" ";


}