/*Algorithm
Input the size of array n and the array elements.
Construct the prefix sum array:
prefix[0] = arr[0]
For i from 1 to n-1: prefix[i] = prefix[i-1] + arr[i]
For each query [L, R], calculate:
If L == 0: return prefix[R]
Else: return prefix[R] - prefix[L-1]*/

#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n),pre(n);
    for(int i=0;i<n;i++)cin>>a[i];
    pre[0]=a[0];
    for(int i=1;i<n;i++)pre[i]=pre[i-1]+a[i];
    int q;cin>>q;
    while(q--){
        int l,r;cin>>l>>r;
        cout<<(l==0?pre[r]:pre[r]-pre[l-1])<<endl;
    }
    return 0;
}

/*Time and Space Complexity
Time Complexity
Building prefix sum: O(n)
Answering each query: O(1)
For q queries: O(q)
Total Time: O(n + q)

Space Complexity
Input array: O(n)
Prefix sum array: O(n)
Total Space: O(n)*/