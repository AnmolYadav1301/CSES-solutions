#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int n;cin>>n;
    vector<pair<int,int>>sch;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        sch.push_back({b,a});
    }

    sort(sch.begin(),sch.end());

    int count=0;
    int prev=-1;
    for(int i=0;i<n;i++){
        if(sch[i].second>=prev){
            count++;
            prev=sch[i].first;
        }
    }
    cout<<count<<'\n';

    return 0;


}