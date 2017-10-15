#include <iostream>
using namespace std;
class Solution {
	public:
		bool canWinNim(int n) {
			bool ret = false;
			if (n%4!=0)ret=true;
			return ret;
		}
	};

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	cout << Solution().canWinNim(n) <<endl;
}