#include "./lttools.cpp"

class Solution {
public:
	
	bool check_valid(const vector<string>& board) {
		int num_o = 0;
		int num_x = 0;
		for (int i=0; i<3; ++i) {
			for (int j=0; j<3; ++j) {
				if (board[i][j] == 'X') {
					++num_x;
				} else if (board[i][j] == 'O') {
					++num_o;
				}
			}
		}
		
		if (!(num_x == num_o || num_x == num_o + 1)) {
			return false;
		}
		
		int row_x = 0;
		int row_o = 0;
		int col_x = 0;
		int col_o = 0;
		int dig_x = 0;
		int dig_o = 0;
		for (int i=0; i<3; ++i) {
			if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
				if (board[i][0] =='X') {
					++row_x;
				} else if (board[i][0] =='O') {
					++row_o;
				}
			}
			if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
				if (board[0][i] == 'X') {
					++col_x;
				} else if (board[0][i] == 'O') {
					++col_o;
				}
			}
		}
		
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
			if (board[0][0] == 'X') {
				++dig_x;
			} else if (board[0][0] == 'O') {
				++dig_o;
			}
		}
		if (board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
			if (board[2][0] == 'X') {
				++dig_x;
			} else if (board[2][0] == 'O') {
				++dig_o;
			}
		}
		
		if (row_o + row_x > 1 || col_o + col_x > 1 || (dig_o > 0 && dig_x > 0)) {
			return false;
		}
		
		if (num_x == num_o && (row_x > 0 || col_x > 0 || dig_x > 0)) {
			return false;
		}
		
		if (num_x == num_o + 1 && (row_o > 0 || col_o > 0 || dig_o > 0)) {
			return false;
		}
		
		return true;
	}
	
	bool validTicTacToe(const vector<string>& board) {
		
		return check_valid(board);
	}
};

int main(int argc, char *argv[]) {
	auto t = LT::Tester(&Solution::validTicTacToe);
	t.test({"O  ","   ","   "}).equals(false);
	t.test({"XOX"," X ","   "}).equals(false);
	t.test({"XXX","   ","OOO"}).equals(false);
	t.test({"XOX","O O","XOX"}).equals(true);
	t.test({"XXX","OOX","OOX"}).equals(true);
	/*
	XXX
	OOX
	OOX
	*/
	t.test({"XOX","OXO","XOX"}).equals(true);
	/*
	XOX
	OXO
	XOX
	*/
	t.test({"XXX","XOO","OO "}).equals(false);
	/*
	XXX
	XOO
	OO_
	*/
	t.test({"OXX","XOX","OXO"}).equals(false);
	/*
	"OXX"
	"XOX"
	"OXO"
	*/
}