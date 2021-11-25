#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>
#include <list>
using namespace std;

class Trie {
	struct Node {
		char c;
		bool isWord;
		Node* children[26];
		Node(char cc): c(cc), isWord(false) {
			fill(begin(children), end(children), nullptr);
		}
	};
	
	Node root = Node('#');
	
	void _insert(const string& s, Node* node) {
		if (s.empty())return;
		int t = s[0]-'a';
		if (node->children[t] == nullptr)
			node->children[t] = new Node(s[0]);
		if (s.size() == 1)
			node->children[t]->isWord = true;
		else
			_insert(s.substr(1), node->children[t]);
	}
	
	vector<Node*> trees(Node* node) {
		vector<Node*> res;
		for (Node* n: node->children)
			if (n != nullptr)
			res.push_back(n);
		return res;
	}
	
	void dfs(Node* node, string w, vector<string>& words, bool inter=true) {
		if (node == nullptr)return;
		for (Node* child: node->children) {
			if (child == nullptr)continue;
			string t = w + child->c;
			if ((inter && child->isWord) ||
				(!inter) && child->isWord && trees(child).empty())
				words.push_back(t);
			dfs(child, t, words, inter);
		}
	}
	
	public:
	void insert(const string& s) {
		_insert(s, &root);
	}
	
	vector<string> words() {
		vector<string> res;
		dfs(&root, "", res);
		return res;
	}
	
	vector<string> paths() {
		vector<string> res;
		dfs(&root, "", res, false);
		return res;
	}
};

int minimumLengthEncoding(const vector<string>& words) {
	Trie trie;
	for(auto& w: words) {
		auto t = w;
		reverse(t.begin(), t.end());
		trie.insert(t);
	}
	auto all_paths = trie.paths();
	//copy(all_paths.begin(), all_paths.end(), ostream_iterator<string>(cout, ","));
	int res = accumulate(all_paths.begin(), all_paths.end(), 0, [](int r,string w){
		return r + w.size() + 1;
	});
	return res;
}

int main(int argc, char *argv[]) {
	cout << minimumLengthEncoding({"time", "ime", "me", "sime", "jme"}) << endl;
	cout << minimumLengthEncoding({"time", "me", "bell"}) << endl;
	cout << minimumLengthEncoding({"t"}) << endl;
}
