#include "../lttools.cpp"

class Solution {
public:
	bool checkPerfectNumber(const int num) {
		if (num <= 1) return false;
		int sum = 1;
		for (int i=2; i<=sqrt(num); ++i) {
			if (num % i == 0) {
				sum += i + num / i;
			}
		}
		return num == sum;
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(&Solution::checkPerfectNumber);
	t.show_error_only = true;
	t.test(6).equals(true);
	t.test(28).equals(true);
	t.test(496).equals(true);
	t.test(8128).equals(true);
	t.test(33550336).equals(true);
	
	unordered_set<int> const s {6,28,496,8128,33550336};
	
	#pragma omp parallel for
	for (int i=1; i<=1e8; ++i) {
		t.test(i).equals(s.count(i) > 0 ? true : false);
	}
}