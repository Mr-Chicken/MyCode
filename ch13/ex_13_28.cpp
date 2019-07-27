#include <iostream>
using std::string;

// (a)
class TreeNode {
public:
	TreeNode(const string &s = string(), int c = 0): value(s), count(new int(1)), left(new TreeNode), right(new TreeNode) {}
	TreeNode(const TreeNode &tn): value(tn.value), count(tn.count), left(tn.left), right(tn.right) {++*count;}
	~TreeNode() {
		if (--*count == 0) {
			delete left;
			delete right;
			delete count;
		}
	}
	TreeNode& operator=(const TreeNode &tn) {
		++*tn.count;
		if (--*count == 0) {
			delete count;
			delete left;
			delete right;
		}
		value = tn.value;
		count = tn.count;
		left = tn.left;
		right = tn.right;
		return *this;
	} 
private:
	string 		value;
	int 		*count;
	TreeNode	*left;
	TreeNode	*right;
};
// (b)
class BinStrTree {
public:
	BinStrTree(): root(new TreeNode) {};
	BinStrTree(const BinStrTree &b) :root(b.root) {}
	~BinStrTree() {
		delete root;
	}
	BinStrTree& operator=(const BinStrTree &b) {
		auto tn = new TreeNode(*b.root);
		delete root;
		root = tn;
		return *this;
	}
private:
	TreeNode *root;
};