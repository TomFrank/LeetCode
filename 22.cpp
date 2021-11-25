#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> ret;
    void gen(int n, int l, int r, string s) {
        if(l == n && r == n){ret.push_back(s);return;}
        if(l<n)gen(n, l+1, r, s+'(');
        if(r<l)gen(n, l, r+1, s+')');
    }
    vector<string> generateParenthesis(int n) {
        gen(n, 0, 0, "");
        return ret;
    }
};

int main() {
    int n;
    while(cin >> n) {
        auto ans = Solution().generateParenthesis(n);
        sort(ans.begin(), ans.end());
        copy(ans.begin(), ans.end(), ostream_iterator<string>(cout, "\n"));
    }
}
