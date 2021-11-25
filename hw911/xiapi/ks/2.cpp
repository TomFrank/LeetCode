#include <iostream>
#include <vector>

using namespace std;

struct rect {
	int x0,y0,x1,y1;
};

int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	vector<rect> arr;
	for (int t=1; t<=T; ++t) {
		int K,x0,y0,x1,y1;
//		int maxx = -1e9;
		for (int k=0; k<K; ++k) {
			cin >> x0 >> y0 >> x1 >> y1;
//			maxx = max(maxx, x1);
			arr.push_back({x0,y0,x1,y1});
		}
		
		sort(arr.begin(), arr.end(), [](auto& a, auto& b){
			if (a.x0 < b.x0) return true;
			else if (a.x0 > b.x0) return false;
			else return a.x1 < b.x1;
		});
		
		int e = 0;
		int l = 0;
		int res = 1e9;
		int count = 0;
		int cx = arr[0].x0;
		for (auto& r: arr) {
			e++;
			if (r.x0 > cx) {
				
			}
		}
	}
}