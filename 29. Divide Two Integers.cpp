#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		if(dividend == INT_MIN && divisor == -1)
			return INT_MAX;
		
//		if(dividend )
		
		if(dividend == INT_MIN)
//		cout << INT_MIN << endl;
		int ret = 0;
		int sign = (dividend > 0) ^ (divisor > 0);
//		dividend = abs(dividend);
//		divisor = abs(divisor);
		while(dividend >= divisor) {
			int i = 1;
			int dr = divisor;
			while((dr<<1) <= dividend) {
				dr <<= 1;
				i  <<= 1;
			}
			dividend -= dr;
			ret += i;
		}
		return sign == 0 ? ret : -ret;
	}
	
	int div_neg(int dividend, int divisor) {
		
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