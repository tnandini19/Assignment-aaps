#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* removeNthFromEnd(Node* head, int n) {
    Node* fast = head;
    Node* slow = head;
    for(int i=0;i<n;i++) fast = fast->next;
    if(!fast) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    while(fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    Node* temp = slow->next;
    slow->next = temp->next;
    delete temp;
    return head;
}

void printList(Node* head) {
    while(head) {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main() {
    int n;
    Node* head = new Node(1);
    Node* temp = head;
    for(int i=2;i<=5;i++) {
        temp->next = new Node(i);
        temp = temp->next;
    }
    cin>>n;
    head = removeNthFromEnd(head,n);
    printList(head);
    return 0;
}

//time complexity: O(L) where L is the length of the linked list
//space complexity: O(1) as we are using only constant space