#include "../lttools.cpp"

class Solution {
public:
	unordered_map<size_t, int> m;
	
	inline
	size_t h(int v, int x) {
		size_t k = hash<int>{}(x) + 0x9e3779b9;
		k ^= hash<int>{}(v) + 0x9e3779b9 + (k<<6) + (k>>2);
		return k;
	}
	
	int target;
	int dfs(int v, int x) {
		size_t k = h(v, x);
		if (m.count(k))
			return m[k];
		if (x == target) {
			m[k] = 0;
			return 0;
		}
		int res;
		if (x > target) {
			if (v > 0) {
				res = 1 + dfs(-1, x);
			} else {
				if (x + v < target) {
					res = 1 + min(dfs(2 * v, x + v), dfs(1, x));
				} else {
					res = 1 + dfs(2 * v, x + v);
				}
			}
		} else {
			if (v > 0) {
				if (x + v > target) {
					res = 1 + min(dfs(2 * v, x + v), dfs(-1, x));
				} else {
					res = 1 + dfs(2 * v, x + v);
				}
			} else {
				res = 1 + dfs(1, x);
			}
		}
		m[k] = res;
		return res;
	}
	
	int bfs() {
		// v,x,p
		using State = tuple<int,int,int>;
		queue<State> q;
		unordered_set<size_t> vis;
		const int max_range = max(10, target*2);
		q.emplace(1,0,0);
		while (!q.empty()) {
			auto [v,x,p] = q.front();
			q.pop();
			if (x == target)
				return p;
			
			if (auto k = h(v,x); x + v >= 0 && x + v < max_range && v * 2 < max_range && vis.count(k) == 0) {
				vis.insert(k);
				q.emplace(v * 2, x + v, p + 1);
			}
				
			if (v > 0) {
				q.emplace(-1, x, p + 1);
			} else {
				q.emplace(1, x, p + 1);
			}
		}
		return -1;
	}
	
	int racecar(int t) {
		target = t;
		return bfs();
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(&Solution::racecar);
	t.test(1).equals(1);
	t.test(2).equals(4);
	t.test(3).equals(2);
	t.test(4).equals(5);
	t.test(5).equals(7);
	t.test(6).equals(5);
	t.test(7).equals(3);
	t.test(8).equals(6);
	t.test(9).equals(8);
	t.test(10).equals(7);
	t.test(11).equals(10);
	t.test(12).equals(7);
	t.test(13).equals(9);
	t.test(14).equals(6);
	t.test(15).equals(4);
	t.test(100).equals(19);
	t.test(1000).equals(23);
}
