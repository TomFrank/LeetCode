#include "./lttools.cpp"

/*
   -2 -1 0  1  2
-2  4 2  0 -2 -4
-1  2 1  0 -1 -2
0   0 0  0  0  0
1  -2 -1 0  1  2
2  -4 -2 0  2  4

   -2  -1  0  1  2
-3  6   3  0 -3 -6
-1  2   1  0 -1 -2
2  -4  -2  0  2  4
4  -8  -4  0  4  8
5  -10 -5  0  5 10


*/


class Solution {
public:
	using LL = long long;
	
	LL count(const vector<int>& nums1, const vector<int>& nums2, LL x) {
		LL ret = 0;
		for (int i=0; i<nums1.size(); ++i) {
			if (nums1[i] < 0) {
				LL l = 0;
				LL r = nums2.size()-1;
				while (l <= r) {
					LL m = l + (r - l) / 2;
					if ((LL)nums1[i] * nums2[m] > x) {
						l = m + 1;
					} else {
						r = m - 1;
					}
				}
				ret += (nums2.size() - l);
			} else if (nums1[i] > 0) {
				LL l = 0;
				LL r = nums2.size()-1;
				while (l <= r) {
					LL m = l + (r - l) / 2;
					if ((LL)nums1[i] * nums2[m] <= x) {
						l = m + 1;
					} else {
						r = m - 1;
					}
				}
				ret += l;
			} else {
				if (x >= 0) {
					ret += nums2.size();
				}
			}
		}
		return ret;
	}
	
	
	long long kthSmallestProduct(const vector<int>& nums1, const vector<int>& nums2, long long k) {
		auto [l,r] = minmax({
			(LL)nums1.front() * nums2.front(), 
			(LL)nums1.front() * nums2.back(), 
			(LL)nums1.back() * nums2.front(), 
			(LL)nums1.back() * nums2.back()});
		
		while (l <= r) {
			LL m = l + (r - l) / 2;
			LL c = count(nums1, nums2, m);
			if (c < k) {
				l = m + 1;
			} else {
				r = m - 1;
			}
		}
		return l;
	}
};

int main(int argc, char *argv[]) {
	auto t= LT::Tester(&Solution::kthSmallestProduct);
	t.test("[2,5]"_arr, "[3,4]"_arr, 2).equals(8);
	t.test("[-4,-2,0,3]"_arr, "[2,4]"_arr, 6).equals(0);
	t.test("[-3,-1,2,4,5]"_arr, "[-2,-1,0,1,2]"_arr, 3).equals(-6);
	t.test("[-2,-1,0,1,2]"_arr, "[-3,-1,2,4,5]"_arr, 3).equals(-6);
	t.test("[-100000,100000]"_arr, "[-100000,100000]"_arr, 1).equals(-10000000000);
}
