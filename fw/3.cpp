#include "../lttools.cpp"

int solution_(const vector<vector<int>>& _orders) {
	
	vector<vector<int>> orders = _orders;
	
	for_each(orders.begin(), orders.end(), [](auto& o){
		sort(o.begin(), o.end()-1, greater<>());
	});
	
	sort(orders.begin(), orders.end(), [](auto a, auto b){
		return a[0] > b[0];
	});
	
	int n = orders.size();
	vector<int> f(n, 0);
	for (int i=0; i<n; ++i) {
		for (int j=0; j<i; ++j) {
			if ((orders[i][1] <= orders[j][1] && orders[i][2] <= orders[j][2]) || 
				(orders[i][1] <= orders[j][2] && orders[i][2] <= orders[j][1]) || 
				(orders[i][1] <= orders[j][2] && orders[i][1] <= orders[j][2]) || 
				(orders[i][2] <= orders[j][1] && orders[i][2] <= orders[j][1]) || 
				(orders[i][2] <= orders[j][1] && orders[i][1] <= orders[j][2]) || 
				orders[i][2] <= orders[j][2] && orders[i][1] <= orders[j][1]) {
				f[i] = max(f[j] + orders[i][3] * orders[i][0], f[i]);
			} else {
				f[i] = max(f[i], f[j]);
			}
		}
	}
	
	// cout << orders;
	
	return *max_element(f.begin(), f.end());
}

int main(int argc, char *argv[]) {
	auto t = LT::Tester(solution_);
	cout << t.test("[[10,9,4,1],[15,7,10,2],[8,5,3,3]]"_arr2d).lastResult() <<endl;// .equals(64);
	cout << t.test("[[6,4,8,30],[15,6,3,10]]"_arr2d).lastResult() <<endl;//.equals(240);
}