#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;
int main(){
    int n;cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    multiset<int>ms;
    int max_size=0;
    for(int i=0;i<n;i++){
       
        auto it=ms.upper_bound(arr[i]);
        if(it!=ms.begin()){
            it--;
            if(*it==arr[i]-1)ms.erase(it);//the numbers that u choose in each round has to be like X,X+1
                                        // X,X+k for k>1 not acceptable in a single round
        }
        ms.insert(arr[i]);
        max_size=max(max_size,(int)ms.size());
    }
    cout<<max_size<<endl;


    return 0;
}