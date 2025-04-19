#include<iostream>
using namespace std;

bool isPalindrome(int x) {
    if(x<0 || (x%10==0 && x!=0)) return false;
    int rev = 0;
    while(x > rev) {
        rev = rev * 10 + x % 10;
        x = x / 10;
    }
    return x == rev || x == rev / 10;
}

int main() {
    int n;
    cin >> n;
    if(isPalindrome(n)) cout << "Palindrome" << endl;
    else cout << "Not Palindrome" << endl;
    return 0;
}
//time complexity: O(log10(n)), space complexity: O(1)
// The function checks if a number is a palindrome by reversing the number and comparing it with the original.