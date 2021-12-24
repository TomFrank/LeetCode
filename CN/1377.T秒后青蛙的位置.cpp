#include "../lttools.cpp"

class Solution {
public:
	double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
		vector<vector<int>> children(n+1), graph(n+1, vector<int>(n+1));
		vector<int> father(n+1);
		
		for (const auto& e: edges) {
			graph[e[0]][e[1]] = 1;
			graph[e[1]][e[0]] = 1;
		}
		
		{
			queue<int> q;
			for (int i=2; i<=n; ++i) {
				if (graph[1][i]) {
					q.push(i);
					children[1].push_back(i);
					father[i] = 1;
					graph[i][1] = 0;
				}
			}
			
			while (!q.empty()) {
				vector<int> l;
				while (!q.empty()) {
					l.push_back(q.front());
					q.pop();
				}
				for (int c: l) {
					for (int i=2; i<=n; ++i) {
						if (graph[c][i]) {
							q.push(i);
							children[c].push_back(i);
							father[i] = c;
							graph[i][c] = 0;
						}
					}
				}
			}
		}
		
		int root = 1;
		
		int ft = target;
		int l = 1;
		while (ft != root) {
			ft = father[ft];
			++l;
		}
		
		if (l > t+1 || (l<t+1 && children[target].size() > 0)) {
			return 0;
		}
		
		queue<int> q;
		unordered_map<int, float> p;
		p[root] = 1;
		q.push(root);
		while (!q.empty()) {
			int r = q.front();
			q.pop();
			int n_c = children[r].size();
			for (int c: children[r]) {
				q.push(c);
				p[c] = p[r] * 1.0 / n_c;
			}
		}
		return p[target];
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(&Solution::frogPosition);
	t.test(7, "[[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]]"_arr2d, 2, 4).equals(0.1666666666666666);
	t.test(7, "[[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]]"_arr2d, 1, 7).equals(0.3333333333333333);
	t.test(7, "[[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]]"_arr2d, 20, 6).equals(0.166666666666666);
	t.test(8, "[[2,1],[3,2],[4,1],[5,1],[6,4],[7,1],[8,7]]"_arr2d, 7, 7).equals(0);
	t.test(5, "[[1,5],[1,4],[5,3],[3,2]]"_arr2d, 3, 2).equals(0.5);
}