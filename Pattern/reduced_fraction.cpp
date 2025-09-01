#include<iostream>
using namespace std;

int max(int a,int b){
    if(a>=b)return a;
    return b;
}

int min(int a,int b){
    return a<=b ? a:b;
}

int gcd(int a,int b){
    
    if(b==0)return a;

    int first_value=max(a-b,b);
    int other_value=min(a-b,b);
    return gcd(first_value,other_value);
}

int main(){
    int a,b;cin>>a>>b;

    int g=gcd(max(a,b),min(a,b));
    a/=g,b/=g;  
    cout<<a<<" "<<b;
    
}