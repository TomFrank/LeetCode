#include "../lttools.cpp"

#include <unordered_set>
int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	int n = A.size();
	const int maxN = 1e9+10;
	int idx1;
	int min1= maxN;
	for (int i=0; i<n; ++i) {
		if (A[i] < min1) {
			min1 = A[i];
			idx1 = i;
		}
	}
	
	int res = min1;
	
	unordered_set<int> min1Idx;
	for (int i=0; i<n; ++i) {
		if (A[i] == min1) {
			min1Idx.insert(i);
		}
	}
	
	int min2 = maxN;
	for (int i=0; i<n; ++i) {
		if (min1Idx.count(i) || min1Idx.count(i-1) || min1Idx.count(i+1))
			continue;
		if (A[i] < min2) {
			min2 = A[i];
		}
	}
	
	return res + min2;
}

int main(int argc, char *argv[]) {
	auto t = LT::Tester(solution);
	auto a = "[5,2,4,6,3,7]"_arr;
	t.test(a).equals(5);
	a = "[5,2,4,6,3,7]"_arr;
	t.test(a).equals(5);
}