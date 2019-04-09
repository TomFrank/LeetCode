#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    pair<char,int> max_cont_ch(string& s, int i) {
        int cnt = 1;
        char c = s[i];
        for(;i+1<s.size();) {
            if(s[i+1] == s[i]) {
                cnt++;
                i++;
            } else break;
        }
        return {c,cnt};
    }
    string countAndSay(int n) {
        string s{"1"};
        for(int i=1;i<n;++i) {
            string ns;
            for(int j=0;j<s.size();) {
                auto [ch, m] = max_cont_ch(s, j);
                //cout << "from=" << j << " ch=" << ch << " m=" << m << " ";
                ns.append(to_string(m)+ch);
                //cout << s << endl;
                j += m;
            }
            s = ns;
            //cout << "------------" << endl;
        }
        return s;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        string ret = Solution().countAndSay(n);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}