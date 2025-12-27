// There is a street of length x whose positions are numbered 0,1,\ldots,x. Initially there are no traffic lights, but n sets of traffic lights are added to the street one after another.
// Your task is to calculate the length of the longest passage without traffic lights after each addition.
// Input
// The first input line contains two integers x and n: the length of the street and the number of sets of traffic lights.
// Then, the next line contains n integers p_1,p_2,\ldots,p_n: the position of each set of traffic lights. Each position is distinct.
// Output
// Print the length of the longest passage without traffic lights after each addition.

#include<iostream>
#include<set>
#include<vector>

using namespace std;

int main(){
    int x,n;cin>>x>>n;
    set<int>s;
    multiset<pair<int,pair<int,int>>>ms;
    vector<int>ans;
    ms.insert({x,{0,x}});
    s.insert(0);s.insert(x);
    for(int i=0;i<n;i++){
        int p;cin>>p;
        auto it=s.upper_bound(p);
        int right=*it;it--;
        int left=*it;
        ms.erase({right-left,{left,right}});
        ms.insert({right-p,{p,right}});
        ms.insert({p-left,{left,p}});
        s.insert(p);
        ans.push_back((*(ms.rbegin())).first);
    }
    for(int &val:ans)cout<<val<<" ";

    return 0;
}