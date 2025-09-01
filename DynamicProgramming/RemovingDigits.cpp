#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int f(int n, vector<int>&dp){

    if(n==0)return dp[0]=0;
    else if(n<0)return 1e9;
    
    if(dp[n]!=-1)return dp[n];

    int x=n,min_steps=INT_MAX;
    while(x>0){
        int sub=INT_MAX;
        if(x%10!=0)sub=f(n-x%10,dp);
        if(sub!=INT_MAX)min_steps=min(min_steps,sub+1);
        x/=10;
    }
    return dp[n]=min_steps;
}
int main(){

    int n;cin>>n;
    
    vector<int>dp(n+1,-1);
    cout<<f(n,dp);

    return 0;
}