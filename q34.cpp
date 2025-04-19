#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    mp[0] = 1;
    int sum = 0, count = 0;
    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if(mp.find(sum - k) != mp.end())
            count += mp[sum - k];
        mp[sum]++;
    }
    return count;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    cout << subarraySum(nums, k) << endl;
    return 0;
}

//time complexity: O(n)
//space complexity: O(n)