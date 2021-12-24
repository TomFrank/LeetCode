#include "../lttools.cpp"

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Codec {
public:
	int nullnum = -131313;
	int stopnum = -242424;
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		if (root == nullptr)
			return "[]";
		vector<int> v;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			TreeNode* t = q.front();
			q.pop();
			if (t != nullptr) {
				v.push_back(t->val);
				q.push(t->left);
				q.push(t->right);
			} else {
				v.push_back(nullnum);
			}  
		}
		while (v.back() == nullnum) {
			v.pop_back();
		}
		string res = "[";
		for (int a: v) {
			if (a != nullnum) {
				res += to_string(a);
			} else {
				res += "null";
			}
			res += ",";
		}
		res.back() = ']';
		// cout << res << " ";
		return res;
	}
	
	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		assert(data.size() >= 2 && data.front() == '[' && data.back() == ']');
		// cout << fmt::format("data={}", data) << endl;
		if (data[1] == ']')
			return nullptr;
		
		auto nextnum = [&,i=1ul]() mutable {
			while (i < data.size()) {
				try {
					size_t j;
					int v = stoi(data.substr(i), &j);
					// cout << fmt::format("v={}; ", v);
					i += j+1;
					return v;
				} catch (invalid_argument const& e) {
					i += 5;
					return nullnum;
				}
			}
			return stopnum;
		};
		
		TreeNode* root = new TreeNode(nextnum());
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			TreeNode* t = q.front();
			q.pop();
			int lv = nextnum();
			int rv = nextnum();
			if (lv == stopnum)
				break;
			if (lv != nullnum) {
				t->left = new TreeNode(lv);
				q.push(t->left);
			}
			if (rv == stopnum)
				break;
			if (rv != nullnum) {
				t->right = new TreeNode(rv);
				q.push(t->right);
			}
		}
		
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main(int argc, char *argv[]) {
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(5);
	
	Codec codec;
	cout << codec.serialize(codec.deserialize(codec.serialize(root)));
	cout << codec.serialize(codec.deserialize("[1,-1,2,-2]"));
}