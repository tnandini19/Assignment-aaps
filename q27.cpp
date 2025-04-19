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

Node* getIntersectionNode(Node* headA, Node* headB) {
    Node* a = headA;
    Node* b = headB;
    while(a != b) {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }
    return a;
}

int main() {
    Node* common = new Node(8);
    common->next = new Node(10);

    Node* headA = new Node(3);
    headA->next = new Node(6);
    headA->next->next = new Node(9);
    headA->next->next->next = common;

    Node* headB = new Node(4);
    headB->next = new Node(7);
    headB->next->next = common;

    Node* result = getIntersectionNode(headA, headB);
    if(result) cout<<result->data<<endl;
    else cout<<"No Intersection"<<endl;
    return 0;
}
//time complexity: O(m+n) where m and n are the lengths of the two linked lists
//space complexity: O(1) as we are not using any extra space