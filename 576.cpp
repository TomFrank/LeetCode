#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
	const int mod = 1e9 + 7;
	vector<vector<vector<int>>> mem;
	int N,m,n;
	
	int dfs(int x, int y, int l) {
		if (l > N) return 0;
		
		if (x < 0 || x == m || y < 0 || y == n) return 1;
		
		// pruning
		int left = N - l;
		if (x + left < m && x - left >= 0 && y + left < n && y - left >= 0) return 0;
		
		// cache
		if (mem[x][y][l] >= 0)
			return mem[x][y][l];
		
		int res = (dfs(x+1, y, l+1) + dfs(x-1, y, l+1)) % mod + (dfs(x, y+1, l+1) + dfs(x, y - 1, l+1)) % mod;
		res %= mod;
		mem[x][y][l] = res;
		return res;
	}
	
	int findPaths(int m, int n, int N, int i, int j) {
		this->m = m;
		this->n = n;
		this->N = N;
		mem = vector(m, vector(n, vector(N, -1)));
		return dfs(i, j, 0);
	}
};

int main(int argc, char *argv[]) {
	cout << Solution().findPaths(2, 2, 2, 0, 0) << endl;
	cout << Solution().findPaths(1, 3, 3, 0, 1) << endl;
	cout << Solution().findPaths(20, 20, 20, 0, 0) << endl;
	cout << Solution().findPaths(50, 50, 50, 0, 0) << endl;
	cout << Solution().findPaths(50, 50, 50, 0, 0) << endl;
}