#include<iostream>
#include<vector>
using namespace std;

void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
    result.push_back(current); // Add the current subset to result
    for (int i = start; i < nums.size(); i++) {
        current.push_back(nums[i]); // Include nums[i]
        backtrack(nums, i + 1, current, result); // Recurse
        current.pop_back(); // Exclude nums[i]
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    backtrack(nums, 0, current, result);
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    
    vector<vector<int>> res = subsets(nums);
    for (auto& subset : res) {
        cout << "[ ";
        for (int num : subset) cout << num << " ";
        cout << "]" << endl;
    }
    return 0;
}
//time complexity: O(2^n) for generating all subsets
//space complexity: O(n) for the recursion stack and current subset