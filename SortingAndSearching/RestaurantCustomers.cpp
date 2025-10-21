#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main(){

    int n;cin>>n;
    vector<pair<int,int>>customer;
    for(int i=0;i<n;i++){
        int arrival,depart;cin>>arrival>>depart;
        customer.push_back({arrival,depart});
    }
    sort(customer.begin(),customer.end());

    int max_customer=0;
    priority_queue<int,vector<int>,greater<int>>pq;
    for(auto p:customer){
        int s=p.first,e=p.second;
        while(!pq.empty() && pq.top()<s){
            pq.pop();
        }
        pq.push(e);
        max_customer=max(max_customer,(int)pq.size());
    }

    cout<<max_customer<<endl;


    return 0;

}
