/*

Algorithm (Two-Pointer Technique)

Initialize two pointers: left = 0, right = n - 1.
While left < right:
Calculate sum = arr[left] + arr[right]
If sum == target: found the pair.
If sum < target: move left pointer forward.
If sum > target: move right pointer backward.
If no pair is found, report it.

*/
#include<iostream>
using namespace std;

void findPair(int arr[],int n,int target){
    int left=0,right=n-1;
    while(left<right){
        int sum=arr[left]+arr[right];
        if(sum==target){
            cout<<arr[left]<<" "<<arr[right]<<endl;
            return;
        }else if(sum<target) left++;
        else right--;
    }
    cout<<"No pair found"<<endl;
}

int main(){
    int n,target;
    cin>>n>>target;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    findPair(arr,n,target);
    return 0;
}
//time complexity: O(n)
//space complexity: O(1)