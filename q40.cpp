#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int findMaxFrequencyElement(const vector<int>& nums) {
    unordered_map<int, int> freqMap;
    int maxFreq = 0;
    int maxElem = nums[0];
    
    for(int num : nums) {
        freqMap[num]++;
        if(freqMap[num] > maxFreq) {
            maxFreq = freqMap[num];
            maxElem = num;
        }
    }
    return maxElem;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    
    for(int i = 0; i < n; i++) cin >> nums[i];
    
    int result = findMaxFrequencyElement(nums);
    cout << "Element with maximum frequency: " << result << endl;
    
    return 0;
}
//time complexity: O(n)
//space complexity: O(n)