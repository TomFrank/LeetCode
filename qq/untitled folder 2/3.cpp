#include <iostream>
#include <vector>

using namespace std;

//void func() {
//	long t;
//	cin >> t;
//	
//	if (t < 4) {
//		cout << 0 << "\n";
//	}
//	
//	long n=1, m=1;
//	long i=0, j=1;
//	
//	long cnt=4;
//	
//	long s=1;
//	
//	while (cnt <= t) {
//		//cout << "s=" << s << "\n";
//		
//		for (long ii=0;ii<n;++ii) {
//			if (ii==0) {
//				if (cnt + 3 <= t) {
//					cnt += 3;
//					s++;
//				} else {
//					cout << s << "\n";
//					return;
//				}
//				
//			} else {
//				if (cnt + 2 <= t) {
//					cnt += 2;
//					s++;
//				} else {
//					cout << s << "\n";
//					return;
//				}
//			}
//		}
//		++m;
//		
//		for (long jj=0;jj<m;++jj) {
//			if (jj==0) {
//				if (cnt + 3 <= t) {
//					cnt += 3;
//					s++;
//				} else {
//					cout << s << "\n";
//					return;
//				}
//			} else {
//				if (cnt + 2 <= t) {
//					cnt += 2;
//					s++;
//				} else {
//					cout << s << "\n";
//					return;
//				}
//			}
//		}
//		++n;
//	}
//}

void func() {
	long t;
	cin >> t;
	
	if (t < 4) {
		cout << 0 << "\n";
	}
	
	int x=1;
	while (x*(x+1) < t/2) {
		x++;
	}
	
	cout << x*x << "\n";
}

int main(int argc, char *argv[]) {
	
	int T;
	cin >> T;
	
	for (int i=0; i<T; ++i) {
		func();
	}
	
}