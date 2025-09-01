#include<iostream>
#include<vector>
#include<algorithm>

using ll=long long int;
using namespace std;

int main(){

    int n;cin>>n;

    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    ll min_moves=0;
    int prev_max=arr[0];
    for(int i=1;i<n;i++){
        if(prev_max>arr[i]){
            min_moves+=prev_max-arr[i];
        }
        else prev_max=arr[i];
    }

    cout<<min_moves<<'\n';

}