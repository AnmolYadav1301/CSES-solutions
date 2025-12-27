#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int main(){
    int n;cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    unordered_set<int>s;
    s.reserve(n);
    int i=0,j=0;
    long long cnt=0;
    while(j<n){
        while(s.count(arr[j]))s.erase(arr[i++]);
        s.insert(arr[j]);
        cnt+=1LL*(j-i+1);
        j++;
    }

    cout<<cnt<<endl;

    return 0;
}