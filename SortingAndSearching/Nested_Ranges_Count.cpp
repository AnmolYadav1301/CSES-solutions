#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;


typedef tree<int,
        null_type,
        less<int>,
        rb_tree_tag,
        tree_order_statistics_node_update>ordered_set;


void print(vector<pair<int,int>>&v){

    for(auto &val:v)cout<<val.first<<" ";
    cout<<endl;
    for(auto &val:v)cout<<val.second<<" ";
    cout<<endl;
}

int main(){

    int n;cin>>n;
    vector<pair<int,pair<int,int>>>v;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        v.push_back({a,{b,i}});
    }

    sort(v.begin(),v.end(),[](const auto & a, const auto &b){
        if(a.first==b.first)return a.second.first>b.second.first;
        else if(a.first<b.first)return true;
        return false;
    });

    ordered_set os1,os2;
    vector<pair<int,int>>ans(n);

    for(int i=n-1;i>=0;i--){
        
        int end=v[i].second.first;
        int cnt1=os1.order_of_key(end+1);
        // upper side elements are those which will go inside
        //cnt of elemnts which are less than and equal to end 
        os1.insert(end);
        ans[v[i].second.second].first=cnt1;
    }

    for(int i=0;i<n;i++){
        
        int end=v[i].second.first;
        os2.insert(end);
        int cnt2=os2.size()-os2.order_of_key(end+1);
        // lower elements are those which will cover this range
       //find out how many elements greater than and equal to end we have
        ans[v[i].second.second].second=cnt2;
    }

    print(ans);
    return 0;
}