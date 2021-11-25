#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int reverse(int x) {
	long ret = 0;
	while (x != 0) {
		ret = ret * 10 + x % 10;
		x /= 10;
		if (ret > INT_MAX || ret < INT_MIN)
			return 0;
	}
	return ret;
}

int main(int argc, char *argv[]) {
	cout << reverse(0) << "\n"
		 << reverse(120) << "\n"
		 << reverse(-123) << "\n"
		 << reverse(123) << "\n"
		 << reverse(1534236469) << "\n"
		 << reverse(-2147483648) << "\n"
		 << reverse(1463847412) << "\n";
//	cout << INT_MAX/10;
}