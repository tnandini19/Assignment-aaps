#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

double findMedianSortedArrays(int arr1[], int n, int arr2[], int m) {
    if (n > m) return findMedianSortedArrays(arr2, m, arr1, n);
    int low = 0, high = n;
    while (low <= high) {
        int partition1 = (low + high) / 2;
        int partition2 = (n + m + 1) / 2 - partition1;
        
        int maxLeft1 = (partition1 == 0) ? INT_MIN : arr1[partition1 - 1];
        int minRight1 = (partition1 == n) ? INT_MAX : arr1[partition1];
        
        int maxLeft2 = (partition2 == 0) ? INT_MIN : arr2[partition2 - 1];
        int minRight2 = (partition2 == m) ? INT_MAX : arr2[partition2];
        
        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            return (n + m) % 2 == 0 ? (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0 : max(maxLeft1, maxLeft2);
        } else if (maxLeft1 > minRight2) high = partition1 - 1;
        else low = partition1 + 1;
    }
    return -1;
}

int main() {
    int arr1[] = {1, 3}, arr2[] = {2};
    cout << "Median: " << findMedianSortedArrays(arr1, 2, arr2, 1) << endl;
    return 0;
}
//time complexity: O(log(min(n, m))) where n and m are the sizes of the two arrays
//space complexity: O(1)