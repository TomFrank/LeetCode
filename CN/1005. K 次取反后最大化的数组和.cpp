#include "./lttools.cpp"


class Solution {
public:
	/*
	[-8,3,-5,-3,-5,-2]
	6
	
	-8,-5,-5,-3,-2,3
	x 8,5,5,3,2,-3 = 20
	8,5,5,3,-2,3 = 22
	
	[5,6,9,-3,3]
	2
	-3,3,5,6,9
	
	*/
	int largestSumAfterKNegations(const vector<int>& nums, int k) {
		priority_queue q {greater{}, nums};
		while (k-- > 0) {
			int a = q.top();
			q.pop();
			q.push(-a);
		}
		auto v = (vector<int>&)q;
		return reduce(v.begin(), v.end());
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(&Solution::largestSumAfterKNegations);
	t.test("[-8,3,-5,-3,-5,-2]"_arr, 6).equals(22);
	t.test("[-2,9,9,8,4]"_arr, 5).equals(32);
	t.test("[4,2,3]"_arr, 1).equals(5);
	t.test("[3,-1,0,2]"_arr, 3).equals(6);
	t.test("[2,-3,-1,5,-4]"_arr, 2).equals(13);
}