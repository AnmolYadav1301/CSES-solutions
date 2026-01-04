// #include<iostream>
// #include<vector>

// using namespace std;

// struct Node{
//     int val;
//     Node* next=nullptr;    
// };

// Node* createNode(int val){
//     Node* newNode= new Node;
//     newNode->val=val;
//     return newNode;
// }

// int main(){
//     int n,k;cin>>n>>k;

//     if(k==0){
//         for(int i=1;i<=n;i++)cout<<i<<" ";
//     }
//     else{
//         Node* dummy=new Node;
//         dummy->val=0;
//         Node* temp=dummy;
//         for(int i=1;i<=n;i++){
//             temp->next=createNode(i);
//             temp=temp->next;
//         }
//         temp->next=dummy->next;
//         temp=temp->next;
//         dummy->next=nullptr;
//         delete(dummy);
//         int len=n;
//         while(temp->next!=temp){
//             int steps=(k-1)%len;
//             while(steps--){
//                 temp=temp->next;
//             }
//             cout<<temp->next->val<<" ";
//             len--;
//             Node* NodeToDelete=temp->next;
//             temp->next=temp->next->next;
//             NodeToDelete->next=nullptr;
//             delete(NodeToDelete);
//             temp=temp->next;
//         }

//         cout<<temp->val<<endl;

//         delete(temp);

//     }
    
//     return 0;
// }
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;



int main(){
    
    int n,k;cin>>n>>k;
    ordered_set os;
    for(int i=1;i<=n;i++)os.insert(i);
    int idx=0;
    while(n){
        idx=(idx+k)%n;
        auto it=os.find_by_order(idx);
        cout<<*it<<" ";
        os.erase(it);
        n--;
    }

    return 0;
}
