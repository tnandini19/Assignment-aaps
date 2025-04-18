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
    int pre=0;
    for(int i=0;i<n-1;i++){
        pre+=a[i];
        if(pre*2==sum){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
//time complexity O(n) and space complexity O(1)