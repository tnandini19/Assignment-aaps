#include<iostream>
#include<vector>
using namespace std;

void permuteHelper(vector<int>& nums, int start, vector<vector<int>>& result) {
    if(start == nums.size()) {
        result.push_back(nums);
        return;
    }
    for(int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);
        permuteHelper(nums, start + 1, result);
        swap(nums[start], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    permuteHelper(nums, 0, result);
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    
    vector<vector<int>> res = permute(nums);
    for(auto& perm : res) {
        cout << "[ ";
        for(int num : perm) cout << num << " ";
        cout << "]" << endl;
    }
    return 0;
}
//time complexity: O(n*n!)
//space complexity: O(n*n!)