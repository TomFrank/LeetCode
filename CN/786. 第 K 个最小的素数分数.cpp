#include "./lttools.cpp"

class Solution {
public:
	vector<int> kthSmallestPrimeFraction(const vector<int>& arr, int k) {
		using AB = pair<int,int>;
		vector<AB> vv;
		for (int i=0; i<arr.size(); ++i) {
			for (int j=i+1; j<arr.size(); ++j) {
				vv.emplace_back(arr[i], arr[j]);
			}
		}
		sort(vv.begin(), vv.end(), [](const auto& a, const auto& b){
			return a.first * b.second < a.second * b.first;
		});
		vector<int> res(2);
		res[0] = vv[k-1].first;
		res[1] = vv[k-1].second;
		return res;
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(&Solution::kthSmallestPrimeFraction);
	t.test("[1,2,3,5]"_arr, 3).equals("[2,5]"_arr);
	t.test("[1,7]"_arr, 1).equals("[1,7]"_arr);
}
