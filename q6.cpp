#include<iostream>
#include<unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s){
    unordered_map<char,int>m;
    int maxLen=0,start=0;
    for(int end=0;end<s.length();end++){
        if(m.find(s[end])!=m.end()&&m[s[end]]>=start){
            start=m[s[end]]+1;
        }
        m[s[end]]=end;
        maxLen=max(maxLen,end-start+1);
    }
    return maxLen;
}

int main(){
    string s;
    cin>>s;
    cout<<lengthOfLongestSubstring(s);
    return 0;
}
//time complexity: O(n)
//space complexity: O(min(n,m)) where n is the length of the string and m is the size of the character set