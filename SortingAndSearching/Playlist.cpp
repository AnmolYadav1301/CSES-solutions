//                       Playlists
// Time limit: 1.00 s
// Memory limit: 512 MB

// You are given a playlist of a radio station since its establishment. The playlist has a total of n songs.
// What is the longest sequence of successive songs where each song is unique?
// Input
// The first input line contains an integer n: the number of songs.
// The next line has n integers k_1,k_2,\ldots,k_n: the id number of each song.
// Output
// Print the length of the longest sequence of unique songs.

// Constraints

// 1<=n<=10^5
// 1 <=k<=10^9

// Example
// Input:
// 8
// 1 2 1 3 2 7 4 2

// Output:
// 5

//solution:

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int main(){
    int n;cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    // unordered_map<int,int>seen;
    unordered_set<int>seen;
    seen.reserve(n);
    int i=0,j=0;
    int max_len=0;
    while(j<n){
        
        while(seen.count(arr[j]))seen.erase(arr[i++]);
        seen.insert(arr[j]);
        max_len=max(max_len,j-i+1);
        j++;
    }

    cout<<max_len<<endl;

    return 0;
}