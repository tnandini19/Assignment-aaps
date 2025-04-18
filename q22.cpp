#include<iostream>
using namespace std;
bool isPowerOfTwo(int n) {
    return n>0 && (n&(n-1))==0;
}
int main() {
    int n=16;
    if (isPowerOfTwo(n)) {
        cout<<n<<" is a power of two."<< endl;
    } else {
        cout<<n<<" is not a power of two."<<endl;
    }
    return 0;
}
//time complexity: O(1)
//space complexity: O(1)
