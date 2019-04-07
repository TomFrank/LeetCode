#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPalindrome(int x) {
	int xx = x;
	int rx = 0;
	while (x > 0) {
		rx = rx * 10 + x % 10;
		x /= 10;
	}
	if (rx == xx)return true;
	else return false;
}

int main(int argc, char *argv[]) {
//	cout << INT_MIN << "\n"
//		 << INT_MAX << "\n";
	cout << boolalpha
//	     << isPalindrome(1) << "\n"
//		 << isPalindrome(121) << "\n"
		 << isPalindrome(12321) << "\n"
		 << isPalindrome(2147483647) << "\n"
		 << isPalindrome(-2147483648) << "\n";
}
