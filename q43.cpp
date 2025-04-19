#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

vector<int> topKFrequent(const vector<int>& nums, int k) {
    unordered_map<int, int> freqMap;
    for (int num : nums) {
        freqMap[num]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    for (auto& entry : freqMap) {
        minHeap.push({entry.second, entry.first});
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }

    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    
    for (int i = 0; i < n; i++) cin >> nums[i];
    
    vector<int> result = topKFrequent(nums, k);
    cout << "Top " << k << " frequent elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
//time complexity: O(n log k) where n is the number of elements in the array and k is the number of top frequent elements to find. This is because we are using a min-heap of size k to keep track of the top k elements, and for each element in the array, we may need to perform a log k operation to insert it into the heap.
//space complexity: O(n) for the frequency map, where n is the number of unique elements in the array. In the worst case, all elements are unique, and we need to store them in the map.