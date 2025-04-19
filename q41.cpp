#include<iostream>
#include<vector>
using namespace std;

int maxSubArraySum(const vector<int>& nums) {
    int maxSoFar = nums[0];
    int maxEndingHere = nums[0];
    
    for(int i=1;i<nums.size();i++){
        maxEndingHere = max(nums[i], maxEndingHere + nums[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    int result = maxSubArraySum(nums);
    cout << "Maximum subarray sum: " << result << endl;
    return 0;
}
//time complexity: O(n)
//space complexity: O(1)