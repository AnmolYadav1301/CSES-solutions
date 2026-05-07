// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<unordered_map>
// #include<set>

// using namespace std;

// int main(){

//     int n,x;cin>>n>>x;
//     vector<int>arr;

//     for(int i=0;i<n;i++){
//         int val;cin>>val;
//         arr.push_back(val);
//     }

//     unordered_map<int,pair<int,int>>mp;

//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             mp[arr[i]+arr[j]]={i,j};
//         }
//     }

//     set<int>s;

//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             int newSum=arr[i]+arr[j];
//             if(mp.find(x-newSum)!=mp.end()){
//                 s.insert(i);
//                 s.insert(j);
//                 s.insert(mp[x-newSum].first);
//                 s.insert(mp[x-newSum].second);
//                 if(s.size()<4){
//                     while(!s.empty())s.erase(s.begin());
//                 }
                
//             }
//             if(s.size()==4)break;
//         }
//         if(s.size()==4)break;
//     }

//     if(s.size()<4){
//         cout<<"IMPOSSIBLE"<<endl;
//     }
//     else{
//         auto it=s.begin();
//         while(it!=s.end()){
//             cout<<*it + 1<<" ";
//             it++;
//         }
//         cout<<endl;
//     }


//     return 0;

// }

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {

    int n, x;
    cin >> n >> x;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, pair<int,int>> mp;

    for(int i = 0; i < n; i++) {

        // check future pairs
        for(int j = i + 1; j < n; j++) {

            int need = x - arr[i] - arr[j];

            if(mp.find(need) != mp.end()) {

                auto [a, b] = mp[need];

                // indices automatically distinct
                if(a != i && a != j &&
                   b != i && b != j) {

                    cout << a+1 << " "
                         << b+1 << " "
                         << i+1 << " "
                         << j+1 << endl;

                    return 0;
                }
            }
        }

        // store past pairs
        for(int j = 0; j < i; j++) {
            mp[arr[i] + arr[j]] = {j, i};
        }
    }

    cout << "IMPOSSIBLE\n";
}