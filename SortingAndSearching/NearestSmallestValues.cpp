#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

int main(){

    int n;cin>>n;
    vector<int>arr(n);

    for(int i=0;i<n;i++)cin>>arr[i];

    stack<int>st;

    vector<int>ans;
    for(int i=0;i<n;i++){

        while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
        if(st.empty()){
            ans.push_back(-1);
        }
        else{
            ans.push_back(st.top());
        }

        st.push(i);
    }

    for(int & val:ans)cout<<val+1<<" ";

    cout<<endl;
}