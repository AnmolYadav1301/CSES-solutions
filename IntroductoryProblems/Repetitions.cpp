#include<iostream>
#include<string>
#include<algorithm>
#include<climits>

using namespace std;

int main(){

    string s;
    cin>>s;

    int len=INT_MIN;char c='0';
    int max_len=INT_MIN;
    for(auto & ch:s){
        if(ch!=c){
            max_len=max(max_len,len);
            len=1;
            c=ch;
        }
        else if(ch==c){
            len++;
        }
    }
    max_len=max(max_len,len);

    cout<<max_len<<'\n';

    return 0;
}