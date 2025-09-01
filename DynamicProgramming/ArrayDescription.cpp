#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

const int mod=1e9 + 7;
// long long int f(vector<int>&arr, int ind, int bound, int prev, vector<vector<long long>>& dp){

//     if(ind<0)return 1;
//     if(dp[ind][prev]!=-1)return dp[ind][prev];
    
//     long long int sub=0;
//     if(arr[ind]==0){
//         for(int i=1;i<=bound;i++){
//             if(ind==(int)arr.size()-1 || abs(prev-i)<=1){
//                 sub=(sub + f(arr,ind-1,bound,i,dp))%mod;
//             }
            
//         }
//     }
//     else{
//         if(ind==(int)arr.size()-1 || abs(prev-arr[ind])<=1){
//             sub=(sub + f(arr,ind-1,bound,arr[ind],dp))%mod;
//         }
       
//     } 
//     return dp[ind][prev]=sub;
// }

int main(){

    int n,m;cin>>n>>m;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

//    vector<vector<long long int>>dp(n,vector<long long>(m+1,-1));
//     cout<<f(arr,n-1,m,0,dp)<<endl;

    //tabulation approach
    vector<vector<long long int>>dp(n+1,vector<long long>(m+1,0));
    // for(int j=1;j<=m;j++){
    //     if(arr[0]==0 || arr[0]==j)dp[0][j]=1;            
    // }

    // for(int i=1;i<n;i++){
    //     for(int j=1;j<=m;j++){
            
    //         if(arr[i]==0 || arr[i]==j) 
    //             for(int d=-1;d<=1;d++){
    //                 int prev=j+d;
    //                 if(prev>=1 && prev<=m){
    //                     dp[i][j]=(dp[i][j]+dp[i-1][prev])%mod;
    //                 }
    //             }         

    //     }
    // }

    // long long ans=0;
    // for(int j=0;j<=m;j++)ans+=dp[n-1][j];

    // cout<<ans<<'\n';


    //space optimised approach
    vector<long long int>curr1(m+1,0),curr2(m+1,0);
    for(int j=1;j<=m;j++){
        if(arr[0]==0 || arr[0]==j)curr1[j]=1;            
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<=m;j++){
            
            if(arr[i]==0 || arr[i]==j){
                for(int d=-1;d<=1;d++){
                    int prev=j+d;
                    if(prev>=1 && prev<=m){
                        curr2[j]=(curr2[j]+curr1[prev])%mod;
                    }
                }         
            }
        }
        curr1.swap(curr2);
        for(int k=0;k<=m;k++)curr2[k]=0;
    }

    long long ans=0;
    for(int j=0;j<=m;j++)ans=(ans+curr1[j])%mod;

    cout<<ans<<'\n';

    return 0;

}