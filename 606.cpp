#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

string helper(TreeNode* t) {
	if (t == nullptr)return "";
	return to_string(t->val) + "(" + helper(t->left) + helper(t->right) + ")";
}

int main(int argc, char *argv[]) {
	
}