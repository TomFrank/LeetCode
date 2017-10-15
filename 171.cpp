#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution {
public:
	int titleToNumber(string s) {
		return accumulate(s.begin(), s.end(), 0, [](int n, char c){return n * 26 + (c - 'A' + 1);});
	}
};
string readString() {
	string s;
	cin >> s;
	return s.substr(1, s.size() - 2);
}
int main(int argc, char *argv[]) {
	auto s = readString();
	cout << Solution().titleToNumber(s);
}