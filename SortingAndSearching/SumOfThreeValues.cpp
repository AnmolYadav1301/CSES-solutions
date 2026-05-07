#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    int n,x;cin>>n>>x;
    vector<pair<int,int>>arr;

    for(int i=0;i<n;i++){
        int val;cin>>val;
        arr.push_back({val,i});
    }

    sort(arr.begin(),arr.end());
    vector<int>v;
    for(int i=0;i<n;i++){
        int sum=x-arr[i].first;
        int j=i+1,k=n-1;
        while(j<k){
           
            int newSum=arr[j].first + arr[k].first;
            if(newSum<sum){
                j++;
            }
            else if(newSum>sum)k--;
            else{
                v.push_back(arr[i].second);
                v.push_back(arr[j].second);
                v.push_back(arr[k].second);
                sort(v.begin(),v.end());
                break;
            }
        }
        if(v.size())break;
    }

    if(v.size()){
        for(int & val:v)cout<<val+1<<" ";
    }
    else cout<<"IMPOSSIBLE";

    cout<<endl;
}