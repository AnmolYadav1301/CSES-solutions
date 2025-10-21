// // You are given an array that contains each number between 1 \dots n exactly once. Your task is to collect the numbers from 1 to n in increasing order.
// // On each round, you go through the array from left to right and collect as many numbers as possible.
// // Given m operations that swap two numbers in the array, your task is to report the number of rounds after each operation.
// // Input
// // The first line has two integers n and m: the array size and the number of operations.
// // The next line has n integers x_1,x_2,\dots,x_n: the numbers in the array.
// // Finally, there are m lines that describe the operations. Each line has two integers a and b: the numbers at positions a and b are swapped.
// // Output
// // Print m integers: the number of rounds after each swap.
// // Constraints

// // 1 \le n, m \le 2 \cdot 10^5
// // 1 \le a,b \le n

// // Example
// // Input:
// // 5 3
// // 4 2 1 5 3
// // 2 3
// // 1 5
// // 2 3

// // Output:
// // 2
// // 3
// // 4


#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>

using namespace std;

int cnt=1;

void findRounds(vector<int>&arr,int a,int b,vector<int>&pos){

    if(a==b)return;
    set<pair<int,int>>s;
    int n=arr.size();
    int x=arr[a],y=arr[b];
    s.insert({x-1,x});
    s.insert({x,x+1});
    s.insert({y-1,y});
    s.insert({y,y+1});
    for(auto p:s){
        if(p.first>=0 && p.second<n){
            if(pos[p.first]>pos[p.second])cnt--;
        }
    }
    //don't do this it may cnt-- for repeated pairs instead use set
    // if(x>0 && pos[x-1]>pos[x])cnt--;
    // if(x+1<n && pos[x]>pos[x+1])cnt--;
    // if(y>0 && pos[y-1]>pos[y])cnt--;
    // if(y+1<n && pos[y]>pos[y+1])cnt--;

    pos[x]=b;
    pos[y]=a;
    swap(arr[a],arr[b]);

    for(auto p:s){
        if(p.first>=0 && p.second<n){
            if(pos[p.first]>pos[p.second])cnt++;
        }
    }
    
    // if(x>0 && pos[x-1]>pos[x])cnt++;
    // if(x+1<n && pos[x]>pos[x+1])cnt++;
    // if(y>0 && pos[y-1]>pos[y])cnt++;
    // if(y+1<n && pos[y]>pos[y+1])cnt++;

    
}



int main(){

    int n,m;cin>>n>>m;
    vector<int>arr(n);
    vector<vector<int>>query(m);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        arr[i]--;
    }
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        a--,b--;
        query[i].push_back(a);
        query[i].push_back(b);
    }
    //to calculate the initial rounds
    vector<int>pos(n);
    for(int i=0;i<(int)arr.size();i++){
        pos[arr[i]]=i;
    }
    for(int i=1;i<n;i++){
        if(pos[i-1]>pos[i])cnt++;
    }
    
    //to calculate for the next m queries
    for(int i=0;i<m;i++){

        findRounds(arr,query[i][0],query[i][1],pos);
        cout<<cnt<<endl;
        // cout<<"hi"<<endl;

    }

    return 0;
    
}

