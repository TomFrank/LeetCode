#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int firstUniqChar(string s) {
		int a[26]{};
		int ret = -1;
		for (char c:s)++a[c-'a'];
		for (int i=0; i<s.size(); ++i)
			if (a[s[i]-'a'] == 1) {
				ret = i;
				break;
			}
		return ret;
	}
};
string readString() {
	string s;
	cin >> s;
	return s.substr(1, s.size() - 2);
}
int main(int argc, char *argv[]) {
	auto s = readString();
	cout << Solution().firstUniqChar(s);
}