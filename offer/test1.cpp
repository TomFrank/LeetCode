#include "../lttools.cpp"

int solution(vector<int> &D, vector<int> &C, int P) {
	// write your code in C++14 (g++ 6.2.0)
	int n = D.size();
	// input is illegel, returns -1
	if (C.size() != n) return -1;
	
	vector<pair<int,int>> objs;
	
	for (int i=0; i<n; ++i) {
		objs.push_back(make_pair(D[i], C[i]));
	}
	
	sort(objs.begin(), objs.end(), [](const auto& a, const auto& b){
		if (a.first < b.first) return true;
		else if (a.first > b.first) return false;
		else return a.second <= b.second;
	});
	
	int res = 0;
	for (const auto& obj: objs) {
		if (P - obj.second >= 0) {
			P -= obj.second;
			++res;
		} else break;
	}
	return res;
}

int main(int argc, char *argv[]) {
	auto t = LT::Tester(solution);
	auto d = "[5,5,5,5]"_arr;
	auto c = "[8,3,3,4]"_arr;
	t.test(d, c, 6).equals(2);
	d = "[5,11,1,3]"_arr;
	c = "[6,1,3,2]"_arr;
	t.test(d, c, 7).equals(2);
	d = "[10,15,1]"_arr;
	c = "[10,1,2]"_arr;
	t.test(d, c, 3).equals(1);
	d = "[11,18,1]"_arr;
	c = "[9,18,8]"_arr;
	t.test(d, c, 7).equals(0);
	d = "[1,4,2,5]"_arr;
	c = "[4,9,2,3]"_arr;
	t.test(d, c, 19).equals(4);
	d = "[1,2,3,4]"_arr;
	c = "[10,1,1,1]"_arr;
	t.test(d, c, 10).equals(1);
	d = "[4,3,2,1]"_arr;
	c = "[1,2,3,4]"_arr;
	t.test(d, c, 19).equals(4);
}