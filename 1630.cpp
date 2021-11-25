#include "./lttools.cpp"

class Solution {
public:
	static
	vector<bool> checkArithmeticSubarrays(const vector<int>& nums, const vector<int>& l, const vector<int>& r) {
		vector<bool> res;
		for (int i=0; i<l.size(); ++i) {
			const auto [mn, mx] = minmax_element(nums.begin()+l[i], nums.begin()+r[i]+1);
			if ((*mx - *mn) % (r[i] - l[i]) != 0) {
				res.push_back(false);
				continue;
			}
			const auto d = (*mx - *mn) / (r[i] - l[i]);
			
			if (d == 0) {
				res.push_back(true);
				continue;
			}
			
			unordered_set<int> st;
			
			int j;
			for (j=l[i]; j<=r[i]; ++j) {
				if ((nums[j]-*mn) % d == 0)
					st.insert((nums[j]-*mn)/d);
				else {
					res.push_back(false);
					break;
				}
			}
			
			if (j<=r[i]) continue;
			
			for (j=0; j<=r[i]-l[i]; ++j)
				if (st.count(j) == 0) {
					res.push_back(false);
					break;
				}
			
			if (j>r[i]-l[i]) res.push_back(true);
		}
		return res;
	}
};

int main(int argc, char *argv[]) {
	auto input = {
		array {
			LT::array_from("[4,6,5,9,3,7]"),
			LT::array_from("[0,0,2]"),
			LT::array_from("[2,3,5]")},
		array {
			LT::array_from("[-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10]"),
			LT::array_from("[0,1,6,4,8,7]"),
			LT::array_from("[4,4,9,7,9,10]")},
		array {
			LT::array_from("[-3,-6,-8,-4,-2,-8,-6,0,0,0,0]"),
			LT::array_from("[5,4,3,2,4,7,6,1,7]"),
			LT::array_from("[6,5,6,3,7,10,7,4,10]")
		}
	};
	LT::batch_test(input, Solution::checkArithmeticSubarrays);
}