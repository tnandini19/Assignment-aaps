#include<iostream>
#include<deque>
#include<vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> result;
    for(int i = 0; i < nums.size(); i++) {
        if(!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        while(!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();
        dq.push_back(i);
        if(i >= k - 1)
            result.push_back(nums[dq.front()]);
    }
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    vector<int> res = maxSlidingWindow(nums, k);
    for(int x : res) cout << x << " ";
    cout << endl;
    return 0;
}
//time complexity: O(n)
//space complexity: O(k)