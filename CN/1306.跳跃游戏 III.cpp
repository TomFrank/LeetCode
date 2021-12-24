#include "../lttools.cpp"

class Solution {
public:
	unordered_map<int,bool> v;
	bool dfs(const vector<int>& arr, int i) {
		if (arr[i] == 0) {
			return true;
		}
		
		if (v[i])
			return false;
		v[i] = true;
		
		if (i+arr[i] < arr.size()) {
			if (dfs(arr, i+arr[i]))
				return true;
		}
		
		if (i-arr[i] >= 0) {
			if (dfs(arr, i-arr[i]))
				return true;
		}
	
		return false;
	}
	
	bool canReach(vector<int>& arr, int start) {
		return dfs(arr, start);
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(&Solution::canReach);
	t.test("[4,2,3,0,3,1,2]"_arr, 5).equals(true);
	t.test("[4,2,3,0,3,1,2]"_arr, 0).equals(true);
	t.test("[3,0,2,1,2]"_arr, 2).equals(false);
}