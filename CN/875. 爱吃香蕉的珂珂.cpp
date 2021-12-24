#include "./lttools.cpp"

class Solution {
public:
	int check(const vector<int>& piles, int v) {
		int h = 0;
		for (int p: piles) {
			int d = p / v;
			int m = p % v; 
			h += d;
			if (m > 0)
				++h;
		}
		return h;
	}
	
	int minEatingSpeed(const vector<int>& piles, int H) {
		int max_k = 0;
		for (int p: piles) {
			max_k = max(max_k, p);
		}
		
		int l = 1;
		int r = max_k;
		while (l <= r) {
			int m = (l + r) / 2;
			int h = check(piles, m);
			if (h <= H) {
				r = m-1;
			} else if (h > H) {
				l = m+1;
			}
		}
		return l;
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(&Solution::minEatingSpeed);
	t.test("[3,6,7,11]"_arr, 8).equals(4);
	t.test("[30,11,23,4,20]"_arr, 5).equals(30);
	t.test("[30,11,23,4,20]"_arr, 6).equals(23);
	t.test("[312884470]"_arr, 312884469).equals(2);
	t.test("[1000000000,1000000000]"_arr, 3).equals(1000000000);
	t.test("[1,1,1,999999999]"_arr, 10).equals(142857143);
}