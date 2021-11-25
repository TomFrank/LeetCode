#include "./lttools.cpp"

class Solution {
public:
	vector<int> findSmallestSetOfVertices(const int n, const vector<vector<int>>& edges) {
		vector<bool> v(n, false);
		for_each(edges.cbegin(), edges.cend(), [&](auto e){
			v[e[1]] = true;
		});
		vector<int> res;
		for (int i=0; i<n; ++i)
			if (!v[i]) res.push_back(i);
		return res;
	}
};

int main(int argc, char *argv[]) {
	auto s = LT::array2d_from("[[0,1],[0,2],[2,5],[3,4],[4,2]]");
	cout << Solution().findSmallestSetOfVertices(6, s) << endl;
}