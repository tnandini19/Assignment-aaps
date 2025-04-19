/*The equilibrium index of an array is an index where the sum of elements to the left is equal to the sum of elements to the right. It's useful in array problems for tasks like partitioning the array into two balanced parts, optimizing load distribution, and solving problems that require finding a point of balance. The concept is often applied in optimization and partitioning problems to divide data with equal sums efficiently.*/

//example -> 

#include<iostream>
#include<vector>
using namespace std;

int findEquilibriumIndex(const vector<int>& arr) {
    int totalSum = 0, leftSum = 0;
    for (int num : arr) totalSum += num;
    
    for (int i = 0; i < arr.size(); i++) {
        totalSum -= arr[i];
        if (leftSum == totalSum) return i;
        leftSum += arr[i];
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 3, 5, 2, 2};
    int eqIndex = findEquilibriumIndex(arr);
    if (eqIndex != -1)
        cout << "Equilibrium index is " << eqIndex << endl;
    else
        cout << "No equilibrium index found" << endl;
    return 0;
}
//Time complexity is O(n) and space complexity is O(1)