#include <iostream>

using namespace std;

int main() {
	long T,N,D,C,M;
	cin >> T;
	for (int t=1; t<=T; ++t) {
		string s;
		cin >> N >> D >> C >> M;
		cin >> s;
		bool res = true;
		bool cp = true;
		for (char c: s) {
			if (c == 'C') {
				C--;
				if (C < 0) {
					cp = false;
				}
			} else if (c == 'D') {
				if (cp == false) {
					res = false;
					break;
				}
				D--;
				if (D < 0) {
					res = false;
					break;
				}
				C += M;
			}
		}
		if (res) {
			cout << "Case #" << t << ": YES" << "\n";
		} else {
			cout << "Case #" << t << ": NO" << "\n";
		}
	}
}