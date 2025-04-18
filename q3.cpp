#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> a(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    int left=0;
    for(int i=0;i<n;i++){
        if(left==sum-left-a[i]){
            cout<<i<<endl;
            return 0;
        }
        left+=a[i];
    }
    cout<<-1<<endl;
    return 0;
}
//time complexity: O(n)
//space complexity: O(n)