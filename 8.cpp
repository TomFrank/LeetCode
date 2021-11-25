#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
class Solution {
	public:
		int myAtoi(string str) {
			int l = str.size();
			int sign = 1;
			long ret = 0;
			int i = str.find_first_not_of(' ');
			if (str[i] == '-') {
				sign = -1;
				++i;
			} else if (str[i] == '+')++i;
			for (; i<l; ++i) {
				if (isdigit(str[i])) {
					ret = ret * 10 + str[i] - '0';
					if (ret > INT_MAX)return sign > 0 ? INT_MAX : INT_MIN;
				} else break;
			}
			return ret * sign;
		}
};
string readString() {
	string s;
	getline(cin, s);
	return s.substr(1, s.size() - 2);
}
int main(int argc, char *argv[]) {
	auto s = readString();
	cout << Solution().myAtoi(s);
}