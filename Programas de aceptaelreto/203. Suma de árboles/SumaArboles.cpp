//Marcos Herrero
#include <iostream>
#include <memory>

struct treeNode {
	std::shared_ptr<treeNode> left;
	int value;
	std::shared_ptr<treeNode> right;

	treeNode(std::shared_ptr<treeNode> l, int v, std::shared_ptr<treeNode> r) :left(l), value(v), right(r) {};
};

struct tree {
private:
	std::shared_ptr<treeNode> root;

public:

	tree() : root(nullptr) {};

	tree(std::shared_ptr<treeNode> r) : root(r) {};

	tree(tree l, int value, tree r) {
		root = std::make_shared<treeNode>(l.root,value,r.root);
	};

	bool empty() const{
		return root == nullptr;
	}

	tree left()const {
		return { root->left };
	}

	int getRoot()const {
		return root->value;
	}

	tree right() const {
		return { root->right };
	}
};

tree readTree(int empty) {
	int root;
	std::cin >> root;

	if (root == empty) return {};

	tree left = readTree(empty);
	tree right = readTree(empty);

	return {left, root,right };
}

const tree operator+(tree const & t1, tree const & t2) {
	if (t1.empty() && t2.empty()) return {};
	else if (t1.empty())return t2;
	else if (t2.empty())return t1;
	else {
		tree l = t1.left() + t2.left();
		tree r = t1.right() + t2.right();

		return { l,t1.getRoot() + t2.getRoot(),r };
	}
}

std::ostream & operator<<(std::ostream & stream, tree const & t) {
	if (t.empty())stream << -1;
	else stream << t.getRoot() << ' ' << t.left() <<' '<< t.right();
	return stream;
}

bool resuelveCaso() {
	tree t1 = readTree(-1);
	tree t2 = readTree(-1);

	if (t1.empty() && t2.empty())return false;

	std::cout << t1 + t2 << '\n';

	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (resuelveCaso());
}