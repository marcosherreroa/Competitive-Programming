//Marcos Herrero

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <stdexcept>
#include <memory>
#include <sstream>

template <class T>
class bintree {
protected:
	/*
	 Nodo que almacena internamente el elemento (de tipo T),
	 y punteros al hijo izquierdo y derecho, que pueden ser
	 nullptr si el hijo es vacío (no existe).
	 */
	struct TreeNode;
	using Link = std::shared_ptr<TreeNode>;
	struct TreeNode {
		TreeNode(Link const& l, T const& e, Link const& r) : elem(e), left(l), right(r) {};
		T elem;
		Link left, right;
	};

	// puntero a la raíz del árbol
	Link raiz;

	// constructora privada
	bintree(Link const& r) : raiz(r) {}

public:
	// árbol vacío
	bintree() : raiz(nullptr) {}

	// árbol hoja
	bintree(T const& e) :
		raiz(std::make_shared<TreeNode>(nullptr, e, nullptr)) {}

	// árbol con dos hijos
	bintree(bintree<T> const& l, T const& e, bintree<T> const& r) :
		raiz(std::make_shared<TreeNode>(l.raiz, e, r.raiz)) {}

	// constructora por copia, operador de asignación y destructora por defecto

	// consultar si el árbol está vacío
	bool empty() const {
		return raiz == nullptr;
	}

	// consultar la raíz
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
	// iterador que recorre el árbol en inorden
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

		// construye el iterador al último
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

// lee un árbol binario de la entrada estándar
template <typename T>
inline bintree<T> leerArbol(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un árbol vacío
		return {};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol(vacio);
		auto dr = leerArbol(vacio);
		return { iz, raiz, dr };
	}
}


struct treecont {
	bintree<int> tree;
    int cont;
};

treecont reconstruir(int k, std::vector<int>  const & preorden, std::vector<int> const & inorden, int ini, int fin) {
	if (ini >= fin) return{ {}, 0 };
	int raiz = preorden[k];

	int ind ; bool encontrado = false;
	for (int i = ini; !encontrado && i < fin; ++i) {
		if (inorden[i] == preorden[k]) {
			encontrado = true;
			ind = i;
		}
	}

	if (!encontrado) return { {}, 0 };
	else {
		++k;
		treecont left = reconstruir(k, preorden, inorden, ini, ind);
		k += left.cont;
		treecont right = reconstruir(k, preorden, inorden, ind + 1, fin);

		return{ {left.tree, raiz, right.tree}, 1+left.cont+right.cont };
	}
}

bool resuelveCaso() {
	int aux;
	std::cin >> aux;
	if (aux == -1)return false;

	std::vector<int> preorden;
	std::vector<int> inorden;

	while (aux != -1) {
		preorden.push_back(aux);
		std::cin >> aux;
	}

	std::cin >> aux;
	while (aux != -1) {
		inorden.push_back(aux);
		std::cin >> aux;
	}

	treecont sol = reconstruir(0 ,preorden, inorden,0, preorden.size());
	std::vector<int> v = sol.tree.postorder();

	std::cout << v[0] ;
	for (int i = 1; i < sol.cont; ++i) std::cout <<' '<< v[i];
	std::cout << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
}