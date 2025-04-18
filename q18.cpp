#include<iostream>
#include<vector>
using namespace std;

class TrieNode {
public:
    TrieNode* children[2];
    TrieNode() {
        children[0] = children[1] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->children[bit]) node->children[bit] = new TrieNode();
            node = node->children[bit];
        }
    }

    int findMaxXor(int num) {
        TrieNode* node = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int oppositeBit = 1 - bit;
            if (node->children[oppositeBit]) {
                maxXor |= (1 << i);
                node = node->children[oppositeBit];
            } else {
                node = node->children[bit];
            }
        }
        return maxXor;
    }
};

int findMaximumXOR(vector<int>& nums) {
    Trie trie;
    int maxXor = 0;
    for (int num : nums) {
        trie.insert(num);
    }
    for (int num : nums) {
        maxXor = max(maxXor, trie.findMaxXor(num));
    }
    return maxXor;
}

int main() {
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    cout << "Maximum XOR: " << findMaximumXOR(nums) << endl;
    return 0;
}
//time complexity: O(N * 32) where N is the number of elements in the array
//space complexity: O(N * 32) where N is the number of elements in the array