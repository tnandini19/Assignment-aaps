#include<iostream>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs){
    if(strs.empty()) return "";
    string prefix = strs[0];
    for(int i=1;i<strs.size();i++){
        while(strs[i].find(prefix)!=0){
            prefix = prefix.substr(0, prefix.length()-1);
            if(prefix=="") return "";
        }
    }
    return prefix;
}

int main(){
    int n;
    cin>>n;
    vector<string> strs(n);
    for(int i=0;i<n;i++) cin>>strs[i];
    cout<<longestCommonPrefix(strs);
    return 0;
}
//time complexity: O(n*m) where n is the number of strings and m is the length of the longest string
//space complexity: O(1) as we are using only a constant amount of extra space