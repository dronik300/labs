#include <iostream>
#include <string>

using namespace std;

class Exception
{
private:
	int error;

public:
	Exception()
	{
		error = 0;
	}
	Exception(int error)
	{
		this->error = error;
	}
	void er()
	{
		if (error == 0) {
			cout << "exception!" << endl;
		}
		if (error == 1)
		{
			cout << "Cant insert Dublicate!" << endl;
		}
		if (error == 2)
		{
			cout << "No such value!" << endl;
		}
		if (error == 3)
		{
			cout << "pointer is empty" << endl;
		}
	}
};

template <class T>
class Iterator;
template <class T>
class BinaryTree;

template <class T>
class Node {
private:
	T data;
	Node* left;
	Node* right;
	Node* parent;

	friend Iterator<T>;
	friend BinaryTree<T>;
};

template <class T>
class Iterator {
public:
	Iterator() {
		nodePointer = nullptr;
	}
	Iterator(Node<T>* nodePointer) {
		this->nodePointer = nodePointer;
	}
	~Iterator() {
		nodePointer = nullptr;
	}
	bool operator== (Iterator other) {
		if (nodePointer == other.nodePointer) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator!= (Iterator other) {
		return !operator==(other);
	}
	T GetValue() {
		if (nodePointer == nullptr) {
			throw 3;
		}
		return nodePointer->data;
	}
	void Next() {
		if (nodePointer->right != nullptr) {
			nodePointer = nodePointer->right;
			while (nodePointer->left != nullptr) {
				nodePointer = nodePointer->left;
			}
		}
		else {
			if (nodePointer->parent == nullptr) {
				return;
			}
			if (nodePointer->parent->left && nodePointer->parent->left == nodePointer) {
				nodePointer = nodePointer->parent;
				return;
			}
			if (nodePointer->parent->right && nodePointer->parent->right == nodePointer) {
				while (nodePointer->data > nodePointer->parent->data) {
					nodePointer = nodePointer->parent;
					if (nodePointer->parent == nullptr) {
						throw 3;
					}
				}
				nodePointer = nodePointer->parent;
				return;
			}
		}
	}

private:
	Node<T>* nodePointer;
};

template <class T>
class BinaryTree {
public:
	BinaryTree() {
		root = nullptr;
		size = 0;
	}

	Iterator<T> Begin() {
		Node<T>* temp = root;
		while (temp->left) {
			temp = temp->left;
		}
		return temp;
	}

	Iterator<T> End() {
		Node<T>* temp = root;
		while (temp->right) {
			temp = temp->right;
		}
		return temp;
	}

	Node<T>* find(T value) {
		Node<T>* temp = root;
		while (temp) {
			if (temp->data > value) 
				temp = root->left;
			else if (temp->data < value) 
				temp = temp->right;
			else {
				return temp;
			}
		}
		throw 2;
	}

	void ad(T data) {
		Node<T>* temp = nullptr;
		if (!root) {
			root = insert(data, nullptr);
			size++;
		}
		else {
			Node<T>* iterator = root;
			while (iterator) {
				if (data > iterator->data) {
					if (iterator->right) {
						iterator = iterator->right;
						continue;
					}
					else {
						iterator->right = insert(data, iterator);
						size++;
						return;
					}
				}
				else if (data < iterator->data) {
					if (iterator->left) {
						iterator = iterator->left;
						continue;
					}
					else {
						iterator->left = insert(data, iterator);
						size++;
						return;
					}
				}
				else {
					throw 1;
				}
			}
		}
	}

	void del(T value) { 
		Node<T>* target = find(value);
		obliterate(target);
	}

private:
	Node<T>* root;
	int size;

	Node<T>* Max(Node<T>* root) {
		while (root->right) {
			root = root->right;
		}
		return root;
	}

	void obliterate(Node<T>* target) {
		if (target->left && target->right) {
			Node<T>* localMax = Max(target->left);
			target->data = localMax->data;
			obliterate(localMax);
			return;
		}
		else if (target->left) {
			if (target == target->parent->left) {
				target->parent->left = target->left;
				target->left->parent = target->parent;
			}
			else {
				target->parent->right = target->left;
				target->left->parent = target->parent;
			}
		}
		else if (target->right) {
			if (target == target->parent->right) {
				target->parent->right = target->right;
				target->right->parent = target->parent;
			}
			else {
				target->parent->left = target->right;
				target->right->parent = target->parent;
			}
		}
		else {
			if (target == target->parent->left) {
				target->parent->left = nullptr;
			}
			else {
				target->parent->right = nullptr;
			}
		}
		delete target;
		size--;
	}

	Node<T>* insert(T l_data, Node<T>* parent) {
		Node<T>* temp = new Node<T>;
		temp->data = l_data;
		temp->left = temp->right = nullptr;
		temp->parent = parent;
		return temp;
	}
};

int main() {
	int a;
	BinaryTree<int> tree;
	tree.ad(15);
	tree.ad(16);
	tree.ad(17);
	tree.ad(2);
	tree.ad(8);
	tree.ad(1);
	Iterator<int> it = tree.Begin();
	tree.del(8);
	cout << "find " << tree.find(2) << endl;
	while (1) {
		if (it == tree.End()) {
			cout << it.GetValue() << "; ";
			break;
		}
		cout << it.GetValue() << "; ";
		try {
			it.Next();
		}
		catch (int exIndex) {
			Exception ex(exIndex);
			ex.er();
		}
	}
	return 0;
}
