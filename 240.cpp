#include "./lttools.cpp"

class Solution {
public:
	static
	bool help(const vector<vector<int>>& m, int x, int y, int t) {
		if(x<0 || y>=m.size()) return false; 
		if(m[y][x] == t) return true;
		if(m[y][x] > t) {
			return help(m, x-1, y, t);
		} else {
			return help(m, x, y+1, t);
		}
	}
	
	static
	bool findNumberIn2DArray(const vector<vector<int>>& matrix, int target) {
		if(matrix.empty()) return false;
		return help(matrix, matrix[0].size()-1, 0, target);
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(Solution::findNumberIn2DArray);
	t.test("[]"_arr2d, 0).equals(true);
	t.test("[[0,1,1]]"_arr2d, 0).equals(true);
	t.test("[[1,1]]"_arr2d, 0).equals(false);
	t.test("[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18, 21,23,26,30]]"_arr2d, 5).equals(true);
	t.test("[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18, 21,23,26,30]]"_arr2d, 20).equals(false);
}
