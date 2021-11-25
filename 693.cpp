#include "./lttools.cpp"

class Solution {
public:
	static
	bool hasAlternatingBits(uint n) {
		//return __builtin_popcount((n^(n>>1)) + 1)  == 1;
		return (((n^(n>>1))+1) & (n^(n>>1))) == 0;
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(Solution::hasAlternatingBits);
	t.test(5).equals(true);
	t.test(7).equals(false);
	t.test(11).equals(false);
	t.test(10).equals(true);
	t.test(3).equals(false);
	t.test(1431655765).equals(true);
}