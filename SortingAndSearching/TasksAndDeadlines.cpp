#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(){

    int n;cin>>n;
    vector<int>durations;
    long long sum=0;
    for(int i=0;i<n;i++){
        int duration,d;
        cin>>duration>>d;
        sum+=1LL*d;
        durations.push_back(duration);
    }

    sort(durations.begin(),durations.end());

    long long f=0,prev=0;
    for(int &val:durations){
        prev+=1LL*val;
        f+=prev;
    }

    cout<<sum-f<<endl;

    return 0;
}