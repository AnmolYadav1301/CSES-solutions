#include<iostream>

using namespace std;

class Node{
    private:
        int val;
        Node* next;
    public:
        Node(int x):val(x),next(nullptr){}

        void PrintVal(){
            cout<<this->val<<" ";
        }

        Node* getNext(){
            return this->next;
        }

};

int main(){

    int n;cin>>n;
    Node* dummy= new Node(0);
    Node* temp=dummy;
    for(int i=0;i<n;i++){
        int val;cin>>val;
        temp->getNext()= new Node(val);
        temp=temp->getNext();
    }
    Node* head=dummy->getNext();
    // dummy->getNext()=nullptr;
    delete dummy;
    // printReverse(head);
}