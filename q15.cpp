#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct Element {
    int value, row, col;
    Element(int v, int r, int c) : value(v), row(r), col(c) {}
    bool operator>(const Element& other) const {
        return value > other.value;
    }
};
int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    priority_queue<Element, vector<Element>, greater<Element>> minHeap;

    for (int i = 0; i < n; i++) {
        minHeap.push(Element(matrix[i][0], i, 0));
    }
    for (int i = 1; i < k; i++) {
        Element e = minHeap.top();
        minHeap.pop();
        if (e.col + 1 < n) {
            minHeap.push(Element(matrix[e.row][e.col + 1], e.row, e.col + 1));
        }
    }

    return minHeap.top().value;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };
    int k = 8;
    cout << "The " << k << "-th smallest element is: " << kthSmallest(matrix, k) << endl;
    return 0;
}
//time complexity: O(k log n), where n is the number of rows in the matrix
//space complexity: O(n), where n is the number of rows in the matrix