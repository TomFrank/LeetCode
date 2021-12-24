#include "./lttools.cpp"

class Solution {
public:
	
	vector<int> psum;
	int n;
	unordered_map<int, int> mem;
	
	int help(int i) {
		if (mem.count(i) > 0)
			return mem[i];
		
		if (i >= n-1) {
			mem[i] = psum[i];
			return psum[i];
		}
		
		int res = max(help(i+1), psum[i] - help(i+1));
		mem[i] = res;
		
		return res;
	}
	
	int stoneGameVIII(const vector<int>& stones) {
		n = stones.size();
		psum.resize(n);
		psum[0] = stones[0];
		for (int i=1; i<n; ++i) {
			psum[i] = psum[i-1] + stones[i];
		}
		return help(1);
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(&Solution::stoneGameVIII);
	t.test("[-1,2,-3,4,-5]"_arr).equals(5);
	t.test("[7,-6,5,10,5,-2,-6]"_arr).equals(13);
	t.test("[-10,-12]"_arr).equals(-22);
	t.test("[-53,-56,90,-74,-50,29,37,64,-31,-54,74,-80,-18,-69,-44,73,99,-47,-35,71,-55,-27,34,1,-66,-63,3,-34,33,91,-25,-40,-33,68,-34,-32,69,44,-54]"_arr).equals(54);
}