#include "../lttools.cpp"

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
public:
	int widthOfBinaryTree(TreeNode* root) {
		if (root == nullptr) return 0;
		queue<pair<TreeNode*, int>> q;
		q.emplace(root, 1);
		int res = 0;
		while (!q.empty()) {
			int s = q.size();
			res = max(res, q.back().second - q.front().second);
			
			// miao! miao! miao!
			int offset = q.front().second + 1;
			
			for (int i=0; i<s; ++i) {
				auto [t,n] = q.front();
				q.pop();
				n -= offset;
				if (t->left != nullptr)
					q.emplace(t->left, n*2);
				if (t->right != nullptr)
					q.emplace(t->right, n*2 + 1);
			}
		}
		return res + 1;
	}
};

int main(int argc, char *argv[]) {
	
}