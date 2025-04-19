#include<iostream>
using namespace std;

class TwoStacks {
    int *arr;
    int size;
    int top1, top2;
public:
    TwoStacks(int n) {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = n;
    }

    void push1(int x) {
        if(top1 < top2 - 1) arr[++top1] = x;
    }

    void push2(int x) {
        if(top1 < top2 - 1) arr[--top2] = x;
    }

    int pop1() {
        if(top1 >= 0) return arr[top1--];
        return -1;
    }

    int pop2() {
        if(top2 < size) return arr[top2++];
        return -1;
    }
};

int main() {
    TwoStacks ts(10);
    ts.push1(5);
    ts.push1(10);
    ts.push2(15);
    ts.push2(20);
    cout<<ts.pop1()<<endl;
    cout<<ts.pop2()<<endl;
    return 0;
}
//time complexity of push and pop operations is O(1) in the worst case.
//space complexity is O(n) where n is the size of the array.