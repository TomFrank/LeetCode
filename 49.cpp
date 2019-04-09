#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <iterator>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // string encode(const string& s) {
    //     array<int, 26> a{};
    //     for_each(s.begin(), s.end(), [&](char c){a[c-'a']++;});
    //     string en;
    //     for_each(a.begin(), a.end(), [&,n=0](int i)mutable{if(i!=0)en+=char(n+'a')+to_string(i);n++;});
    //     return en;
    // }
    // vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //     map<string, vector<string>> m;

    //     for(auto& s:strs)
    //         m[encode(s)].push_back(s);
        
    //     vector<vector<string>> ret;
    //     for(auto& [_,v]:m) {
    //         ret.push_back(move(v));
    //     }
       
    //     return ret;
    // }
    void str_sort(string& s) {
        int a[26]{};
        for(char c:s)++a[c-'a'];
        for(int i=0,q=0;i<26;++i)
            for(int j=0;j<a[i];++j)s[q++]=char('a'+i);
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(auto& s: strs) {
            auto t = s;
            str_sort(t);
            //cout << s << " " << t << endl;
            //sort(t.begin(), t.end());
            m[t].push_back(s);
        }
        vector<vector<string>> ret;
        for(auto& [_,v]:m) {
            ret.push_back(v);
        }
        return ret;
    }
};

int main() {
    vector<string> s{"eat", "tea", "tan", "ate", "nat", "bat"};
    auto ans = Solution().groupAnagrams(s);
    for(auto v:ans) {
        for(auto s:v)cout << s << ",";
        cout << endl;
    }
}