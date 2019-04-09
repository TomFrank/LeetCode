#include <iostream>
#include <sstream>
#include <string>
#include <array>
#include <vector>
#include <iterator>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // void dfs(int m, int n, int x, int y, int& ans) {
    //     if(x == m -1 && y == n -1) {
    //         ++ans;
    //         return;
    //     }
    //     if(x + 1 < m)dfs(m, n, x + 1, y, ans);
    //     if(y + 1 < n)dfs(m, n, x, y + 1, ans);
    // }
    // int uniquePaths(int m, int n) {
    //     int ans = 0;
    //     //vector<vector<bool>> v(m, vector<bool>(n, false));
    //     dfs(m, n, 0, 0, ans);
    //     return ans;
    // }

    // int uniquePaths(int m, int n) {
    //     if(m == 1 || n == 1)return 1;
    //     return uniquePaths(m-1, n)+uniquePaths(m, n-1);
    // }

    int uniquePaths(int m, int n) {
        int a[101][101]{};
        for(int i=1;i<=100;++i) {
            a[i][1]=1;
            a[1][i]=1;
        }

        for(int i=2;i<=m;++i) {
            for(int j=2;j<=n;++j) {
                a[i][j] = a[i-1][j] + a[i][j-1];
            }
        }
        return a[m][n];
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        int ret = Solution().uniquePaths(m, n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}