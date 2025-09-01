// #include<iostream>
// using namespace std;
// const int mod=1e9 + 7;
// int f(int prev,int ind, int m, int n){

//     if(ind==n){
//         return 1;
//     }

//     int sub=0;
//     for(int i=1;i<=m;i++){
//         if(i*prev<=m)sub=(sub+f(i,ind+1,m,n))%mod;
//         else break;
//     }
//     return sub;

// }
// int main(){
//     int n,m;cin>>n>>m;
//     int prev=1,ind=0;
//     cout<<f(prev,ind,m,n);
// }

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

    vector<int>larget_ele_in_left(vector<int>&arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()<=arr[i]){
                st.pop();
            }
            if(st.empty())ans[i]=-1;
            else ans[i]=st.top();
            st.push(arr[i]);
        }

        return ans;
        
    }
    vector<int> farthestSmallestInRight(vector<int>&nums){

        int n=nums.size();
        vector<int>min_ele_indices(n);
        vector<int>minTillHere(n);
        minTillHere[n-1]=nums[n-1];
        for(int j=n-2;j>=0;j--){
            minTillHere[j]=min(minTillHere[j+1],nums[j]);
        }
        
        for(int i=0;i<n;i++){

            int low=i+1,high=n-1;
            int farthest_ind=-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(minTillHere[mid]<nums[i]){
                    farthest_ind=mid;
                    low=mid+1;
                }
                else high=mid-1;
            }
            min_ele_indices[i]=farthest_ind;
        }

        return min_ele_indices;
        
    }

    vector<int> maxValue(vector<int>& nums) {

        vector<int>farthestSmall=farthestSmallestInRight(nums);
        vector<int>largestInLeft=larget_ele_in_left(nums);

        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(farthestSmall[i]==-1 && largestInLeft[i]==-1)ans.push_back(nums[i]);
            else if(farthestSmall[i]==-1)ans.push_back(largestInLeft[i]);
            else ans.push_back(largestInLeft[farthestSmall[i]]);
        }

        return ans;
    }


int main(){
    int n;cin>>n;
    vector<int>input(n);
    for(int i=0;i<n;i++){
        cin>>input[i];
    }

    vector<int>ans=maxValue(input);
    for(auto v:ans)cout<<v<<" ";
    return 0;
}