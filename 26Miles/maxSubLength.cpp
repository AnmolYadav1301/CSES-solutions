#include<iostream>
#include<vector>
#include<stack>
using namespace std;

const int mod=1e9 + 7;

void prevGreater(vector<int>&pge,int n,vector<int>&arr){

    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[i]>=arr[st.top()]){
            st.pop();
        }
        if(st.empty()){
            pge[i]=-1;
        }
        else pge[i]=st.top();

        st.push(i);
    }
}

void nextGreater(vector<int>&nge,int n,vector<int>&arr){

    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[i]>=arr[st.top()]){
            st.pop();
        }
        if(st.empty()){
            nge[i]=n;
        }
        else nge[i]=st.top();

        st.push(i);
    }
}

int main(){
    int n;cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int>pge(n);
    vector<int>nge(n);
    prevGreater(pge,n,arr);
    nextGreater(nge,n,arr);

    int count=0;
    for(int i=0;i<n;i++){
        int k=(nge[i]-pge[i]-1);
        int val=k*(k+1)/2;
        count=(count+(val*arr[i]))%mod;
    }

    cout<<count<<endl;

    return 0;
}
