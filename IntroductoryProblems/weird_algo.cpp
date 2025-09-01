#include<iostream>
using namespace std;
typedef unsigned long long llu;
int main(){
    llu i;cin>>i;
    while(i>1){
        cout<<i<<" ";
        if((i&1)==0){
            i=i/2;
        }
        else{
            i*=3;
            i+=1;
        }
    }
    cout<<(i);
}