#include "../lttools.cpp"

class Solution {
public:
	bool isNStraightHand(vector<int>& hand, int groupSize) {
		int n = hand.size();
		if (n % groupSize != 0)
			return false;
		sort(hand.begin(), hand.end());
		unordered_map<int,int> m;
		for (int a: hand) {
			++m[a];
		}
		for (int i=0; i<n;) {
			int c = m[hand[i]];
			for (int x=hand[i]; x<hand[i]+groupSize; ++x) {
				m[x] -= c;
				if (m[x] < 0) 
					return false;
			}
			while (i<n && m[hand[i]] == 0) 
				++i;
		}
		return true;
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(&Solution::isNStraightHand);
	t.test("[1,2,3,6,2,3,4,7,8]"_arr, 3).equals(true);
	t.test("[1,2,3,4,5]"_arr, 4).equals(false);
	t.test("[8,10,12]"_arr, 3).equals(false);
}