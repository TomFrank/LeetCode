#include "../lttools.cpp"

class Solution {
public:
	using App = pair<int, int>;
	int eatenApples(vector<int>& apples, vector<int>& days) {
		priority_queue<App, vector<App>, greater<>> q;
		int n = apples.size();
		int res = 0;
		for (int i=0; i<n; ++i) {
			if (apples[i] > 0)
				q.emplace(days[i]+i, apples[i]);
			while (!q.empty() && q.top().first <= i) {
				q.pop();
			}
			if (!q.empty()) {
				auto t = q.top();
				q.pop();
				t.second--;
				if (t.second > 0) {
					q.push(t);
				}
				++res;
			}
		}
		
		int d = n;
		while (!q.empty()) {
			while (!q.empty() && q.top().first <= d) {
				q.pop();
			}
			
			if (q.empty())
				break;
			
			auto t = q.top();
			q.pop();
			if (t.second > 0) {
				int p = min(t.second, t.first-d);
				res += p;
				d += p;
			}
		}
		return res;
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(&Solution::eatenApples);
	t.test("[1,2,3,5,2]"_arr, "[3,2,1,4,2]"_arr).equals(7);
	t.test("[3,0,0,0,0,2]"_arr, "[3,0,0,0,0,2]"_arr).equals(5);
	t.test("[2,1,1,4,5]"_arr, "[10,10,6,4,2]"_arr).equals(8);
}