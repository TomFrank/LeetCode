#include <iostream>

class Solution {
public:
	int hammingDistance(int x, int y) {
		int z = x^y;
		int n = 0;
		while (z > 0) {
			if (z&1)
				++n;
			z >>= 1;
		}
		return n;
	}
};

int main(int argc, char *argv[]) {
	int x=0, y=1;
	printf("%d", x^y);
//	std::scanf("x = %d, y = %d", &x, &y);
//	std::cout << Solution().hammingDistance(x, y) << std::endl;
}