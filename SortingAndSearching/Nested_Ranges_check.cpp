#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<stack>
#include<climits>

using namespace std;

void print(vector<pair<int,int>>&ans){
    for(auto &val:ans)cout<<val.first<<" ";
    cout<<endl;
    for(auto &val:ans)cout<<val.second<<" ";
    cout<<endl;
}

int main(){

    int n;cin>>n;
    vector<pair<int,pair<int,int>>>v;
    multiset<pair<int,int>>ms;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        v.push_back({a,{b,i}});
    }

    // if the start are equal then the ends must be arranged in the descending order 
    sort(v.begin(),v.end(),[](pair<int,pair<int,int>> &a, pair<int,pair<int,int>> &b){
        if(a.first==b.first)return a.second.first>b.second.first;
        else return a.first<b.first;
    });

    vector<int>minAfter(n),maxBefore(n);

    int a=INT_MAX,b=INT_MIN;
    for(int i=0;i<n;i++){
        maxBefore[i]=b;
        b=max(v[i].second.first,b);
    }

    for(int i=n-1;i>=0;i--){
        minAfter[i]=a;
        a=min(v[i].second.first,a);
    }

    vector<pair<int,int>>ans(n);
    for(int i=0;i<n;i++){
        pair<int,int>p={0,0};
        if(minAfter[i]<=v[i].second.first){
            p.first=1;
        }
        if(maxBefore[i]>=v[i].second.first){
            p.second=1;
        }

        ans[v[i].second.second]=p;
    }

    print(ans);

}