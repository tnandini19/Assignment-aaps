#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int candidate = -1, count = 0;
    for(int num : nums) {
        if(count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }
    count = 0;
    for(int num : nums) {
        if(num == candidate) {
            count++;
        }
    }
    if(count > nums.size() / 2) {
        return candidate;
    }
    return -1;
}
int main() {
    vector<int> nums = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    cout << "Majority Element: " << majorityElement(nums) << endl;
    return 0;
}

//time complexity: O(n)
//space complexity: O(1)
