#include "../lttools.cpp"

int mypartition(vector<int>& arr, int s, int e) {
	if (s >= e) return s;
	int x = arr[s];
	int idx = s+1;
	for (int i=idx; i<e; ++i) {
		if (arr[i] <= x) {
			swap(arr[idx], arr[i]);
			++idx;
		}
	}
	swap(arr[idx-1], arr[s]);
	return idx-1;
}

void select_method(vector<int>& arr, int l, int r, int k) {
	if (l >= r) return;
	int p = mypartition(arr, l, r);
	//cout << p << arr << l << "," << r << "," << k << endl;
	int num = p - l + 1;
	if (num == k) {
		return;
	} else if (k < num) {
		select_method(arr, l, p, k);
	} else {
		select_method(arr, p+1, r, k-num);
	}
}



vector<int> heap_solution(const vector<int>& arr, int k) {
	if (k == 0)
		return {};
	
	priority_queue<int> q;
	
	for (int a: arr) {
		if (q.size() < k) {
			q.push(a);
		} else if (q.top() > a) {
			q.push(a);
			q.pop();
		}
	}
	
	vector<int> res;
	while (!q.empty()) {
		res.push_back(q.top());
		q.pop();
	}
	
	return res;
}


vector<int> getLeastNumbers(const vector<int>& arr, int k) {
	auto a = arr;
	select_method(a, 0, arr.size(), k);
	a.erase(a.begin()+k, a.end());
	return a;
}


int main(int argc, char *argv[]) {
	auto t = LT::Tester(getLeastNumbers);
	cout << t.test({0,0,1,2,4,2,2,3,1,4}, 8).lastResult();
}