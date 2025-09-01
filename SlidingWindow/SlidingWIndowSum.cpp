#include<iostream>
#include<vector>

int main(){
    int n,k;std::cin>>n>>k;

    long long int x,a,b,c;std::cin>>x>>a>>b>>c;
    std::vector<long long int>arr(n);
    arr[0]=x;
    for(int i=1;i<n;i++){
        
        arr[i]=(a*arr[i-1]+b)%c;

    }
    long long int xor_val=0,sum=0;
    int l=0;
    for(int i=0;i<n;i++){
        if(i<k){
            sum+=arr[i];
            continue;
        }
        xor_val^=sum;
        sum-=arr[l++];
        sum+=arr[i];
        
    }
    xor_val^=sum;

    std::cout<<xor_val<<'\n';

    return 0;
}