#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int getListLength(ListNode* head) {
    int length = 0;
    while (head) {
        length++;
        head = head->next;
    }
    return length;
}

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    int lenA = getListLength(headA);
    int lenB = getListLength(headB);
    
    while (lenA > lenB) {
        headA = headA->next;
        lenA--;
    }
    
    while (lenB > lenA) {
        headB = headB->next;
        lenB--;
    }
    
    while (headA && headB) {
        if (headA == headB) return headA;
        headA = headA->next;
        headB = headB->next;
    }
    
    return nullptr;
}

int main() {
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = new ListNode(8);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);
    
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(0);
    headB->next->next = new ListNode(1);
    headB->next->next->next = headA->next->next; // Intersection at node 8
    
    ListNode* intersection = getIntersectionNode(headA, headB);
    if (intersection) cout << "Intersection at node with value: " << intersection->val << endl;
    else cout << "No intersection" << endl;
    return 0;
}
//time complexity: O(m+n) where m and n are the lengths of the two linked lists
//space complexity: O(1) as we are using only a constant amount of space