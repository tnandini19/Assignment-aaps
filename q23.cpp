#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class TrieNode {
public:
    TrieNode *left, *right;
    TrieNode() : left(NULL), right(NULL) {}
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode *node = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (bit == 0) {
                if (!node->left) node->left = new TrieNode();
                node = node->left;
            } else {
                if (!node->right) node->right = new TrieNode();
                node = node->right;
            }
        }
    }

    int getMaxXor(int num) {
        TrieNode *node = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (bit == 0) {
                if (node->right) {
                    maxXor |= (1 << i);
                    node = node->right;
                } else {
                    node = node->left;
                }
            } else {
                if (node->left) {
                    maxXor |= (1 << i);
                    node = node->left;
                } else {
                    node = node->right;
                }
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
        maxXor = max(maxXor, trie.getMaxXor(num));
    }
    return maxXor;
}

int main() {
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    cout << "Maximum XOR of two numbers in the array: " << findMaximumXOR(nums) << endl;
    return 0;
}

//time complexity: O(N * 32) = O(N), where N is the number of elements in the array
//space complexity: O(N * 32) = O(N), where N is the number of elements in the array