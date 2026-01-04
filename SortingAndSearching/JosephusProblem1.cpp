#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int val;
    Node* next=nullptr;    
};
Node* createNode(int val){
    Node* newNode= new Node;
    newNode->val=val;
    return newNode;
}

int main(){
    int n;cin>>n;
    Node* dummy=new Node;

    dummy->val=0;
    Node* temp=dummy;
    for(int i=1;i<=n;i++){
        temp->next=createNode(i);
        temp=temp->next;
    }
    temp->next=dummy->next;
    temp=temp->next;
    dummy->next=nullptr;
    delete(dummy);
    while(temp->next!=temp){
        cout<<temp->next->val<<" ";
        Node* NodeToDelete=temp->next;
        temp->next=temp->next->next;
        NodeToDelete->next=nullptr;
        delete(NodeToDelete);
        temp=temp->next;
    }

    cout<<temp->val<<endl;

    delete(temp);

    return 0;
}