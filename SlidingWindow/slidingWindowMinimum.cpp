#include<iostream>
#include<vector>
#include<deque>

int main(){

    int n,k;std::cin>>n>>k;

    int x,a,b,c;std::cin>>x>>a>>b>>c;
    std::vector<long long int>arr(n);
    arr[0]=x;
    for(int i=1;i<n;i++){
        
        arr[i]=(a*arr[i-1]+b)%c;

    }

    long long int xor_val=0;
    std::deque<int>dq;
    for(int i=0;i<n;i++){
        if(i<k-1){
            while(!dq.empty() && arr[dq.back()]>=arr[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            continue;
        }
        while(!dq.empty() && arr[dq.back()]>=arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        while(i-dq.front()+1>k){
            dq.pop_front();
        }

        if(!dq.empty())xor_val^=arr[dq.front()];
    }

    std::cout<<xor_val<<'\n';

    return 0;
}