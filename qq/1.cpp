#include "../lttools.cpp"

using namespace std;

int dfs(vector<vector<int>>& g, int i, int j, int n, int m) {
	if (i == 0 && j == 0) {
		return g[0][0];
	}
	if (i == 0) {
		return dfs(g, 0, j-1, n, m);
	}
	if (j == 0) {
		return dfs(g, i-1, j, n, m);
	}
	return max(g[i][j] * dfs(g, i-1, j, n, m), g[i][j] * dfs(g, i, j-1, n, m));
}

int main(int argc, char *argv[]) {
	int n, m;
	scanf("%d %d\n", &n, &m);
	vector<vector<int>> g(n, vector<int>(m, 0));
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			scanf("%d ", &g[i][j]);
		}
	}
	
	int res = dfs(g, n-1, m-1, n, m);
	printf("%d", res);
	
}
//	int dp[20][20]{};
//	dp[0][0] = g[0][0];
//	for (int i=1; i<n; ++i) {
//		dp[i][0] = g[i][0] * dp[i-1][0];
//	}
//	for (int j=1; j<n; ++j) {
//		dp[0][j] = g[0][j] * dp[0][j-1];;
//	}
//	for (int i=1; i<n; ++i) {
//		for (int j=1; j<m; ++j) {
//			dp[i][j] = max(dp[i-1][j] * g[i][j], dp[i][j-1] * g[i][j]);
//		}
//	}
//	
//	int res = dp[n-1][m-1];
//	printf("%d\n", res);
//	
//	for (int i=0; i<n; ++i) {
//		for (int j=0; j<m; ++j) {
//			printf("%d ", dp[i][j]);
//		}
//		printf("\n");
//	}
