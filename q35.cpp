#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for(int num : nums) freq[num]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    for(auto it : freq) {
        minHeap.push({it.second, it.first});
        if(minHeap.size() > k) minHeap.pop();
    }

    vector<int> result;
    while(!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    vector<int> res = topKFrequent(nums, k);
    for(int x : res) cout << x << " ";
    cout << endl;
    return 0;
}
//time complexity: O(nlogk) where n is the number of elements in the array and k is the number of top frequent elements to find.
//space complexity: O(n) for the frequency map and O(k) for the min heap.