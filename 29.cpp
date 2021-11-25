#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		if(dividend == INT_MIN) {
			if(divisor == -1) return INT_MAX; // only case that may overflow
			else if(divisor == INT_MIN) return 1;
		}
		if(divisor == INT_MIN) return 0; // whatever the divident is, the answer is 0
		if(divisor == 1)return dividend;
		
		int ret = 0;
		int sign = (dividend > 0) ^ (divisor > 0);
		
		// exclude all cases that divisor is INT_MIN, so abs() will not overflow
		divisor = abs(divisor);
		if(dividend == INT_MIN) {
			dividend += divisor;
			ret++;
		}

		// abs() will not overflow
		dividend = abs(dividend);
		while (dividend >= divisor) {
			int i = 1, dr = divisor;
			while (dividend - dr >= dr) {
				dr <<= 1;
				i <<= 1;
			}
			dividend -= dr;
			ret += i;
		}

		return sign == 0 ? ret : -ret;
	}
	
};

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		int dividend = stringToInteger(line);
		getline(cin, line);
		int divisor = stringToInteger(line);
		
		int ret = Solution().divide(dividend, divisor);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}