#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void nextPermutation(vector<int>& nums) {
    int k = -1;
    for (int i = nums.size() - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            k = i;
            break;
        }
    }
    if (k == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }
    int l = -1;
    for (int i = nums.size() - 1; i > k; i--) {
        if (nums[i] > nums[k]) {
            l = i;
            break;
        }
    }
    swap(nums[k], nums[l]);
    reverse(nums.begin() + k + 1, nums.end());
}
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    nextPermutation(nums);
    for (int i = 0; i < n; i++) cout << nums[i] << " ";
    cout << endl;
    return 0;
}
//time complexity: O(n)
//space complexity: O(1)