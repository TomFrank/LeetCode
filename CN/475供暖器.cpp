#include "../lttools.cpp"

class Solution {
public:
	bool check(const vector<int>& houses, const vector<int>& heaters, int r) {
		if (r < 0) return false;
		int i = 0;
		for (int h: heaters) {
			while (i < houses.size() && houses[i] < h && h - r <= houses[i]) 
				++i;
			if (i < houses.size() && houses[i] == h)
				++i;
			while (i < houses.size() && houses[i] > h && h + r >= houses[i]) 
				++i;
		}
		return i >= houses.size();
	}
	
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());
		int l = 0;
		int r = max({abs(houses.front()-heaters.front()), abs(houses.front()-heaters.back()), abs(houses.back()-heaters.front()), abs(houses.back()-heaters.back())});
		while (l <= r) {
			int m = l + (r - l) / 2;
			bool c = check(houses, heaters, m);
			if (c) {
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		return l;
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(&Solution::findRadius);
	t.test("[1]"_arr, "[1,2,3,4]"_arr).equals(0);
	t.test("[1,5]"_arr, "[10]"_arr).equals(9);
	t.test("[1,2,3]"_arr, "[2]"_arr).equals(1);
	t.test("[1,2,3,4]"_arr, "[1,4]"_arr).equals(1);
	t.test("[1,5]"_arr, "[2]"_arr).equals(3);
	t.test("[282475249,622650073,984943658,144108930,470211272,101027544,457850878,458777923]"_arr, "[823564440,115438165,784484492,74243042,114807987,137522503,441282327,16531729,823378840,143542612]"_arr).equals(161834419);
}