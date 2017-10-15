#include <iostream>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root==nullptr)return 0;
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};
int main(int argc, char *argv[]) {
	TreeNode* root = new TreeNode(-1);
	root->left = new TreeNode(0);
	root->right = new TreeNode(0);
	root->left->left = new TreeNode(0);
	cout << Solution().maxDepth(root);
}