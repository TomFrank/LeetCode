#include <vector>
#include <iostream>
using namespace std;
class Solution {
	public:
		int islandPerimeter(vector<vector<int>>& grid) {
			int m = grid.size();
			int n = grid[0].size();
			int ret = 0;
			for (int i = 0; i<m; ++i)
			for (int j = 0; j<n; ++j) {
				if (grid[i][j]==1) {
					if (i==0)++ret;
					if (j==0)++ret;
					if (i+1==m)++ret;
					if (j+1==n)++ret;
					if (i>0&&grid[i-1][j]==0)++ret;
					if (j>0&&grid[i][j-1]==0)++ret;
					if (i+1<m&&grid[i+1][j]==0)++ret;
					if (j+1<n&&grid[i][j+1]==0)++ret;
				}
			}
			return ret;
		}
	};

vector<vector<int>> readVec2() {
	vector<int> vec;
	vector<vector<int>> ret;
	char c;
	getchar();
	while (scanf("%c%c", &c, &c)==2) {
		if (c == ','||c == ']') {
			ret.push_back(vec);
			vec.clear();
		}else vec.push_back(c-'0');
	}
	return ret;
}
int main(int argc, char *argv[]) {
	vector<vector<int>> grid = readVec2();
	cout << Solution().islandPerimeter(grid) << endl;
}