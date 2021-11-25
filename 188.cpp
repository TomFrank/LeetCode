#include "./lttools.cpp"

class Solution {
public:
	
	static
	int dfs(int d, bool b, int ki, const int n, const int k, const vector<int>& prices, vector<vector<vector<int>>>& mem) {
		if (d >= n) return 0;
		if (ki > k || (b && ki == k)) return 0;
				
		if (mem[d][b][ki] > 0) return mem[d][b][ki];
		
		int res = dfs(d+1, b, ki, n, k, prices, mem);
		if (!b) {
			res = max(res, -prices[d] + dfs(d+1, true, ki, n, k, prices, mem));
		} else {
			res = max(res, prices[d] + dfs(d+1, false, ki+1, n, k, prices, mem));
		}
		
		mem[d][b][ki] = res;
		
		return res;
	}
	
	static
	int maxProfit(int k, const vector<int>& prices) {
		vector<vector<vector<int>>> mem(prices.size(), vector(2, vector(k+1, -1)));
		int res = dfs(0, false, 0, prices.size(), k, prices, mem);
		return res;
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(Solution::maxProfit);
	t.test(2, LT::array_from("[2,4,1]")).equals(2);
	t.test(2, LT::array_from("[3,2,6,5,0,3]")).equals(7);
	t.test(40, LT::array_from("[1,6,3,7,1,8,3,7,2,7,2,10,5,3,3,6,2,7,4,2,1,5,6,8,10,4,1,4,12,5,3,1,3,5,6,4,2]")).equals(66);
	t.test(2, LT::array_from("[3,3,5,0,0,3,1,4]")).equals(6);
}