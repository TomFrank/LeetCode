#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
	public:
		bool isAnagram(string s, string t) {
			int a[26]{}, b[26]{};
			for (char c:s)++a[c-'a'];
			for (char c:t)++b[c-'a'];
			for (int i=0; i<26; ++i)
				if (a[i] != b[i])return false;
			return true;
		}
	};
string readString() {
	string s;
	cin >> s;
	return s.substr(1, s.size() - 2);
}
int main(int argc, char *argv[]) {
	auto s = readString();
	auto t = readString();
	cout << Solution().isAnagram(s, t);
}