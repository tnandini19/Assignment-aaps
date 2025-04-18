#include<iostream>
using namespace std;

int countNumbersWithUniqueDigits(int n) {
    if (n == 0) return 1;
    if (n == 1) return 10;

    int result = 10, current = 9, multiplier = 9;
    for (int i = 2; i <= n; i++) {
        current *= multiplier--;
        result += current;
    }
    return result;
}

int main() {
    int n = 3;
    cout << "Count of numbers with unique digits: " << countNumbersWithUniqueDigits(n) << endl;
    return 0;
}
//time complexity: O(n), space complexity: O(1)