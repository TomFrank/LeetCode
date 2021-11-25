#include "../lttools.cpp"

#include <algorithm>
int solution(vector<int> &A, int K) {
	// write your code in C++14 (g++ 6.2.0)
	int n = A.size();
	const int maxN = 1e9+10;
	vector<int> leftMin(n+2, maxN);
	vector<int> leftMax(n+2, 0);
	vector<int> rightMin(n+2, maxN);
	vector<int> rightMax(n+2, 0);
	
	for (int i=1,j=n-2; i<n; ++i,--j) {
		leftMin[i] = min(leftMin[i-1], A[i-1]);
		leftMax[i] = max(leftMax[i-1], A[i-1]);
		rightMin[j] = min(rightMin[j+1], A[j+1]);
		rightMax[j] = max(rightMax[j+1], A[j+1]);
	}
	
	int res = maxN;
	for (int i=K-1, j=0; i<n; ++i,++j) {
		int maxItem = max(leftMax[j], rightMax[i]);
		int minItem = min(leftMin[j], rightMin[i]);
		res = min(res, maxItem-minItem);
	}
	return res;
}

int main(int argc, char *argv[]) {
	auto t = LT::Tester(solution);
	auto a = "[5,3,6,1,3]"_arr;
	t.test(a, 2).equals(2);
	a = "[8,8,4,3]"_arr;
	t.test(a, 2).equals(0);
	a = "[3,5,1,3,9,8]"_arr;
	t.test(a, 4).equals(1);
}