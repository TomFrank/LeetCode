#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
	public:
		bool canConstruct(string ransomNote, string magazine) {
			int ran[26]{}, mag[26]{};
			for (char c:ransomNote)++ran[c-'a'];
			for (char c:magazine)++mag[c-'a'];
			for (int i=0; i<26; ++i)
				if (ran[i] > mag[i])
					return false;
			return true;
		}
};
string readString() {
	string s;
	cin >> s;
	return s.substr(1, s.size() - 2);
}
int main() {
    auto ran = readString();
	auto mag = readString();
	cout << Solution().canConstruct(ran, mag);
}