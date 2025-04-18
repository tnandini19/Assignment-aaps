//A prefix sum array is a powerful technique used in algorithm design to efficiently compute the sum of elements in a subarray.
//It allows us to preprocess an array in such a way that we can answer sum queries in constant time. The idea is to create a new array, called the prefix sum array, where each element at index i contains the sum of the elements from the original array from index 0 to i.
//example code -> 
#include <bits/stdc++.h>
using namespace std;
int main(){

    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int prefix[n];
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }
}
    