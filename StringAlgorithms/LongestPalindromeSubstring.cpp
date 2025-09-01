#include<iostream>
#include<vector>
#include<string>

using namespace std;

void print(string & ans){
    cout<<ans;
    cout<<'\n';
}

int main(){

    string s;
    cin>>s;

    string str="^#";
    for(char &ch:s){
        str+=ch;
        str+="#";
    }
    str+="?";

    int n=s.length();
    int maxLen=0,centre=0;
    vector<int>palin(2*n+3);
    int r=1,l=0;
    for(int i=1;i<(int)str.length()-1;i++){

        palin[i]=min(r-i,palin[l+r-i]);

        while(str[i-palin[i]]==str[i+palin[i]]){
            palin[i]++;
        }

        if(i+palin[i]>r){
            r=palin[i]+i,l=i-palin[i];
        }

        if(palin[i]>maxLen){
            maxLen=palin[i];
            centre=i;
        }
    }

    int start=(centre-maxLen)/2;
    string ans=s.substr(start,maxLen-1);
    print(ans);


}