#include<iostream>
#include<algorithm>
using namespace std;

void nextPermutation(int arr[],int n){
    int i=n-2;
    while(i>=0&&arr[i]>=arr[i+1]) i--;
    if(i>=0){
        int j=n-1;
        while(arr[j]<=arr[i]) j--;
        swap(arr[i],arr[j]);
    }
    reverse(arr+i+1,arr+n);
    for(int k=0;k<n;k++) cout<<arr[k]<<" ";
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    nextPermutation(arr,n);
    return 0;
}
//time complexity: O(n)
//space complexity: O(1)