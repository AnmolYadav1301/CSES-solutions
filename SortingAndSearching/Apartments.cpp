#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int main(){

    int n,m,k;cin>>n>>m>>k;
    //applicant, apartment, variation
    vector<int>desired_size;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        desired_size.push_back(a);
    }
    sort(desired_size.begin(),desired_size.end());
    // vector<int>apartment_size;
    multiset<long int>ms;
    for(int i=0;i<m;i++){
        long long b;cin>>b;
        // apartment_size.push_back(b);
        ms.insert((long int)(b+k));
    }

    int count=0;
    for(int applicant:desired_size){
        if(ms.empty())break;
        auto it=ms.lower_bound(applicant);
        if(it==ms.end()){
            break;//if no lower bound for this upcoming are even higher
        }
        if(*it<=applicant+2LL*k){
            count++;
            ms.erase(it);
        }        
    }

    cout<<count<<endl;

}
