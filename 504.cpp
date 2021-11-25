#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	string convertToBase7(int num) {
		string ret;
		bool s = true;
		if (num < 0) {
			num = -num;
			s = false;
		}
		if (num == 0)ret+='0';
		while (num != 0) {
			ret += num % 7 + '0';
			num /= 7;
		}
		if (!s)ret+='-';
		reverse(ret.begin(), ret.end());
		return ret;
	}
};

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	cout << Solution().convertToBase7(n);
}