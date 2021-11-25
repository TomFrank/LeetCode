#include "./lttools.cpp"

class Solution {
public:
	bool checkOverlap(int radius, int x0, int y0, int x1, int y1, int x2, int y2) {
		int nx1=x1-x0, ny1=y1-y0, nx2=x2-x0, ny2=y2-y0;
		int xm=0,ym=0;
		if (nx2<=0) xm=nx2;
		else if(nx1>=0) xm=nx1;
		if (ny2<=0) ym=ny2;
		else if(ny1>=0) ym=ny1;
		return xm*xm+ym*ym<=radius*radius;
	}
};

int main(int argc, char *argv[]) {
	cout << Solution().checkOverlap(1, 0, 0, 1, -1, 3, 1) << endl;
	cout << Solution().checkOverlap(1, 0, 0, -1, 0, 0, 1) << endl;
	cout << Solution().checkOverlap(1, 1, 1, -3, -3, 3, 3) << endl;
	cout << Solution().checkOverlap(1, 1, 1, 1, -3, 2, -1) << endl;
}