#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,k;cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int sum=0;
    for(int i=0;i<k;i++)sum+=a[i];
    int maxSum=sum;
    for(int i=k;i<n;i++){
        sum+=a[i]-a[i-k];
        maxSum=max(maxSum,sum);
    }
    cout<<maxSum<<endl;
    return 0;
}
//time complexity: O(n)
//space complexity: O(1)