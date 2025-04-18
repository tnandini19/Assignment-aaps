#include<iostream>
using namespace std;

int countBits(int n) {
    int count = 0;
    for (int i = 0; i <= n; i++) {
        count += __builtin_popcount(i);  // Built-in function to count 1s in binary representation
    }
    return count;
}

int main() {
    int n = 5;
    cout << "Total number of 1s in binary representations from 0 to " << n << ": " << countBits(n) << endl;
    return 0;
}
//time complexity: O(n log n) because for each number from 0 to n, we are counting the bits which takes log n time in the worst case.
//space complexity: O(1) because we are using only a constant amount of space for the count variable.