#include<iostream>
#include<vector>
#include<set>

using namespace std;

void print(vector<int>&arr){
    for(auto &v:arr)cout<<v<<endl;
}

int main(){

    int tickets,customers;cin>>tickets>>customers;
    multiset<int>price;
    for(int i=0;i<tickets;i++){
        int h;cin>>h;
        price.insert(h);
    }

    vector<int>audience(customers);
    for(int i=0;i<customers;i++){
        cin>>audience[i];
    }
    
    vector<int>sold(customers,-1);
    for(int i=0;i<customers;i++){

        if(price.empty())break;
        auto it=price.upper_bound(audience[i]);
        if(it!=price.begin())it--;
        if(audience[i]>=*it){
            sold[i]=*it;
            price.erase(it);
        }
    }

    print(sold);

    
}