#include "../lttools.cpp"

class Solution {
public:
	int lastRemaining(int n) {
		int d = 1; // d = 2d, n = n/2
		int a0 = 1; // a0 = a0+d if c%2==0 else a0
		bool l = true;
		while (n > 1) {
			if (l || n % 2 != 0) {
				a0 = a0 + d;
			}
			n /= 2;
			d *= 2;
			l = !l;
		}
		return a0;
	}
};


int main(int argc, char *argv[]) {
	auto t = LT::Tester(&Solution::lastRemaining);
	t.test(9).equals(6);
	t.test(11).equals(8);
	t.test(35).equals(24);
	t.test(34).equals(24);
	t.test(22).equals(8);
	t.test(100).equals(54);
}