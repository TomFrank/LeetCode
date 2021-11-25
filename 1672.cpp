#include "./lttools.cpp"

class Solution {
public:
	static int maximumWealth(const vector<vector<int>>& accounts) {
		int res = 0;
		for (auto& a: accounts)
			res = max(res, accumulate(a.cbegin(), a.cend(), 0));
		return res;
	}
};

int main(int argc, char *argv[]) {
	auto input = { 
		LT::array2d_from("[[1,2,3],[3,2,1]]"),
		LT::array2d_from("[[1,5],[7,3],[3,5]]")
	};
	LT::batch_test(input, Solution::maximumWealth);
}