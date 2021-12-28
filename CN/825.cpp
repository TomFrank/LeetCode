#include "../lttools.cpp"

class Solution {
public:
	bool nosend(int x, int y) {
		return x * 0.5 + 7 >= y || x < y || (x < 100 && y > 100);
	}
	
	int numFriendRequests(vector<int>& ages) {
		sort(ages.rbegin(), ages.rend());
		int n = ages.size();
		int count = 0;
		// cout << ages << endl;
		int last = 0;
		for (int i=0; i<n; ++i) {
			if (i > 0 && ages[i] == ages[i-1]) {
				count += last;
				continue;
			}
			int l = i+1;
			int r = n-1;
			while (l <= r) {
				int m = l + (r - l) / 2;
				if (ages[m] * 2 <= ages[i] + 14) {
					r = m - 1;
				} else {
					l = m + 1;
				}
			}
			if (l != i) {
				count += l - i - 1;
				last = l - i - 1;
			}
		}
		return count;
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(&Solution::numFriendRequests);
	t.test("[73,106,39,6,26,15,30,100,71,35,46,112,6,60,110]"_arr).equals(29);
	t.test("[16,16]"_arr).equals(2);
	t.test("[16,17,18]"_arr).equals(2);
	t.test("[20,30,100,110,120]"_arr).equals(3);
	t.test("[8,85,24,85,69]"_arr).equals(4);
}