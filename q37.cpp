#include<iostream>
#include<vector>
using namespace std;

void backtrack(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
    if(target == 0) {
        result.push_back(current);  // Found a valid combination
        return;
    }
    
    for(int i = start; i < candidates.size(); i++) {
        if(candidates[i] > target) continue;  // No need to continue if current number exceeds the target
        
        current.push_back(candidates[i]);  // Include the number
        backtrack(candidates, target - candidates[i], i, current, result);  // Recurse with updated target
        current.pop_back();  // Backtrack by removing the last added number
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current;
    backtrack(candidates, target, 0, current, result);
    return result;
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> candidates(n);
    for(int i = 0; i < n; i++) cin >> candidates[i];
    
    vector<vector<int>> res = combinationSum(candidates, target);
    for (auto& comb : res) {
        cout << "[ ";
        for (int num : comb) cout << num << " ";
        cout << "]" << endl;
    }
    return 0;
}
//time complexity: O(2^n) in the worst case, where n is the number of candidates. This is because each candidate can either be included or excluded from the combination, leading to 2^n possible combinations.
//space complexity: O(n) for the recursion stack and the current combination being built. In the worst case, the depth of the recursion can go up to n, where n is the number of candidates.