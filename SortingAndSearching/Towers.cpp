#include<iostream>
#include<set>
#include<vector>

using namespace std;

int main(){

    int n;cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    multiset<int>ms;
    for(int num:arr){
        auto it=ms.upper_bound(num);
        if(it!=ms.end())ms.erase(it);
        ms.insert(num);
    }

    cout<<ms.size()<<endl;
}

// T.C O(nlogn)