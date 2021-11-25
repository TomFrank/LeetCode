#include "./lttools.cpp"

class Solution {
public:
	
	static constexpr int md = 1e9 + 7;
	
	static
	bool isPrime(int n) {
		if (n == 2) return true;
		if (~n&1) return false;
		int sqt = sqrt(n);
		for (int i=3; i<=sqt; i+=2)
			if (n % i == 0) return false;
		return true;
	}
	
	static
	int numPrimeArrangements(int n) {
		int p = 0;
		for (int i=2; i<=n; ++i)
			if (isPrime(i)) ++p;
		
		int64_t res = 1;
		for (int i=2; i<=p; ++i)
			res = (res * i) % md;
		for (int i=2; i<=(n-p); ++i)
			res = (res * i) % md;
		return res;
	}
};

int main(int argc, char *argv[]) {
	auto inputs = {
		5,100
	};
	LT::batch_test(inputs, Solution::numPrimeArrangements);
}