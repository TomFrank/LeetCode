#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;

int bfs(const vector<vector<int>>& grid) {
	int ans=0;
	int n=grid.size();
	int m=grid[0].size();
	struct cell {
		int x,y,v;
	};
	queue<cell> q;
	vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
	q.push({0,0,grid[0][0]});
	while (not q.empty()) {
		cell t = q.front();
		q.pop();
		int x=t.x;
		int y=t.y;
		int v=t.v;
		vis[x][y]=1;
		if (x==n-1 and y==m-1) {
			ans = max(ans, v);
			vis[x][y]=0;
		}
		if (x+1<n and not vis[x+1][y]) {
			q.push({x+1,y,v+grid[x+1][y]});
		}
		if (y+1<m and not vis[x][y+1]) {
			q.push({x,y+1,v+grid[x][y+1]});
		}
	}
	return ans;
}

vector<vector<int>> g;
int n,m;
vector<vector<int>> mem;
int dfs(int i, int j) {
	if (i==0 and j==0)
		return g[0][0];
	
	if (i<0 or j<0)
		return -1;
	
	if (mem[i][j]>0)
		return mem[i][j];
	
	int v = max(dfs(i-1, j), dfs(i, j-1)) + g[i][j];
	mem[i][j]=v;
	return v;
}

int maxValue(const vector<vector<int>>& grid) {
	n=grid.size();
	m=grid[0].size();
	g=grid;
	mem=vector<vector<int>>(n, vector<int>(m, 0));
	return dfs(n-1,m-1);
}

int main(int argc, char *argv[]) {
	cout << maxValue({{1,3,1},{1,5,1},{4,2,1}}) << endl;
}