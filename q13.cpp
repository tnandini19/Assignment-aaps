#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=nullptr;
    }
};

Node* mergeSortedLists(Node* l1,Node* l2){
    Node dummy(0);
    Node* tail=&dummy;
    while(l1&&l2){
        if(l1->data<l2->data){
            tail->next=l1;
            l1=l1->next;
        }else{
            tail->next=l2;
            l2=l2->next;
        }
        tail=tail->next;
    }
    tail->next=(l1)?l1:l2;
    return dummy.next;
}

void printList(Node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){
    Node* a=new Node(1);
    a->next=new Node(3);
    a->next->next=new Node(5);
    Node* b=new Node(2);
    b->next=new Node(4);
    b->next->next=new Node(6);
    Node* merged=mergeSortedLists(a,b);
    printList(merged);
    return 0;
}

//time complexity: O(n+m) where n and m are the lengths of the two lists
//space complexity: O(1) since we are not using any extra space for the merged list