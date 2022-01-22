//Marcos Herrero


#include <memory>   // shared_ptr, make_shared
#include <stdexcept>
#include <stack>
#include <vector>
#include <queue>
#include <iostream>

template <class T>
class bintree {
protected:
	/*
	 Nodo que almacena internamente el elemento (de tipo T),
	 y punteros al hijo izquierdo y derecho, que pueden ser
	 nullptr si el hijo es vac�o (no existe).
	 */
	struct TreeNode;
	using Link = std::shared_ptr<TreeNode>;
	struct TreeNode {
		TreeNode(Link const& l, T const& e, Link const& r) : elem(e), left(l), right(r) {};
		T elem;
		Link left, right;
	};

	// puntero a la ra�z del �rbol
	Link raiz;

	// constructora privada
	bintree(Link const& r) : raiz(r) {}

public:
	// �rbol vac�o
	bintree() : raiz(nullptr) {}

	// �rbol hoja
	bintree(T const& e) :
		raiz(std::make_shared<TreeNode>(nullptr, e, nullptr)) {}

	// �rbol con dos hijos
	bintree(bintree<T> const& l, T const& e, bintree<T> const& r) :
		raiz(std::make_shared<TreeNode>(l.raiz, e, r.raiz)) {}

	// constructora por copia, operador de asignaci�n y destructora por defecto

	// consultar si el �rbol est� vac�o
	bool empty() const {
		return raiz == nullptr;
	}

	// consultar la ra�z
	T const& root() const {
		if (empty()) throw std::domain_error("El arbol vacio no tiene raiz.");
		else return raiz->elem;
	}

	// consultar el hijo izquierdo
	bintree<T> left() const {
		if (empty()) throw std::domain_error("El arbol vacio no tiene hijo izquierdo.");
		else return bintree<T>(raiz->left);
	}

	// consultar el hijo derecho
	bintree<T> right() const {
		if (empty()) throw std::domain_error("El arbol vacio no tiene hijo derecho.");
		else return bintree(raiz->right);
	}


	// recorridos

	std::vector<T> preorder() const {
		std::vector<T> pre;
		preorder(raiz, pre);
		return pre;
	}

	std::vector<T> inorder() const {
		std::vector<T> in;
		inorder(raiz, in);
		return in;
	}

	std::vector<T> postorder() const {
		std::vector<T> post;
		postorder(raiz, post);
		return post;
	}

	std::vector<T> levelorder() const {
		std::vector<T> levels;
		if (!empty()) {
			std::queue<Link> pendientes;
			pendientes.push(raiz);
			while (!pendientes.empty()) {
				Link sig = pendientes.front();
				pendientes.pop();
				levels.push_back(sig->elem);
				if (sig->left != nullptr)
					pendientes.push(sig->left);
				if (sig->right != nullptr)
					pendientes.push(sig->right);
			}
		}
		return levels;
	}

protected:
	static void preorder(Link a, std::vector<T> & pre) {
		if (a != nullptr) {
			pre.push_back(a->elem);
			preorder(a->left, pre);
			preorder(a->right, pre);
		}
	}

	static void inorder(Link a, std::vector<T> & in) {
		if (a != nullptr) {
			inorder(a->left, in);
			in.push_back(a->elem);
			inorder(a->right, in);
		}
	}

	static void postorder(Link a, std::vector<T> & post) {
		if (a != nullptr) {
			postorder(a->left, post);
			postorder(a->right, post);
			post.push_back(a->elem);
		}
	}

public:
	// iterador que recorre el �rbol en inorden
	class const_iterator {
	public:
		T const& operator*() const {
			if (ptr == nullptr) throw std::out_of_range("fuera del arbol");
			return ptr->elem;
		}

		T const* operator->() const {
			return &operator*();
		}

		bool operator==(const_iterator const& other) const {
			return ptr == other.ptr;
		}
		bool operator!=(const_iterator const& other) const {
			return !(*this == other);
		}

		const_iterator & operator++() {  // ++ prefijo
			next();
			return *this;
		}

	private:
		friend class bintree;
		Link ptr;
		std::stack<Link> ancestros;

		// constructores privados
		// construye el iterador al primero
		const_iterator(Link raiz) { ptr = first(raiz); }

		// construye el iterador al �ltimo
		const_iterator() : ptr(nullptr) {}

		Link first(Link act) {
			if (act == nullptr) {
				return nullptr;
			}
			else {
				while (act->left != nullptr) {
					ancestros.push(act);
					act = act->left;
				}
				return act;
			}
		}

		void next() {
			if (ptr == nullptr) {
				throw std::range_error("El iterador no puede avanzar");
			}
			else if (ptr->right != nullptr) { // primero del hijo derecho
				ptr = first(ptr->right);
			}
			else if (ancestros.empty()) { // hemos llegado al final
				ptr = nullptr;
			}
			else { // podemos retroceder
				ptr = ancestros.top();
				ancestros.pop();
			}
		}

	};

	const_iterator begin() const {
		return const_iterator(raiz);
	}
	const_iterator end() const {
		return const_iterator();
	}

};

// lee un �rbol binario de la entrada est�ndar
template <typename t>
inline bintree<t> leerarbol(t vacio) {
	t raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un �rbol vac�o
		return {};
	}
	else { // leer recursivamente los hijos
		auto iz = leerarbol(vacio);
		auto dr = leerarbol(vacio);
		return { iz, raiz, dr };
	}
}

bintree<int> operator+(bintree<int> const & tree1, bintree<int> const & tree2) {
	if (tree1.empty() && tree2.empty())return {};
	else if (tree1.empty()) {
		int root = tree2.root();
		bintree<int> left = tree2.left();
		bintree<int> right = tree2.right();
		return { left, root, right };
	}
	else if (tree2.empty()) {
		int root = tree1.root();
		bintree<int> left = tree1.left();
		bintree<int> right = tree1.right();
		return { left, root, right };
	}

	else {
		int root = tree1.root() + tree2.root();
		bintree<int> left = tree1.left() + tree2.left();
		bintree<int> right = tree1.right() + tree2.right();
		return{ left, root, right };
	}
}

std::ostream & operator<<(std::ostream & flujo, bintree<int> const & tree) {
	if (tree.empty())std::cout << -1;
	else flujo << tree.root() <<' '<< tree.left() <<' '<<tree.right();
	return flujo;
}

bool resuelveCaso() {
	bintree<int> tree1 = leerarbol(-1);
	bintree<int> tree2 = leerarbol(-1);

	if (tree1.empty() && tree2.empty())return false;

	std::cout << tree1+tree2 << '\n';

	return true;
}
int main() {
	while (resuelveCaso());
}