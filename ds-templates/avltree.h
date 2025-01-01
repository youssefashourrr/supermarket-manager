#include <iostream>
#include <vector>
#include <stdexcept>
#include "bstnode.h"
using namespace std;


template <class T>
class AvlTree {
private:
    BSTNode<T>* root;

    int height(BSTNode<T>* r)
    {
        return r ? r->height : 0;
    }

    BSTNode<T>* RotateRight(BSTNode<T>* r) {
        if (r == nullptr || r->left == nullptr) return r; // Guard
        BSTNode<T>* newRoot = r->left;
        r->left = newRoot->right;
        newRoot->right = r;
           // 5
        ////3
        //
        r->height = 1 + max(height(r->left), height(r->right));
        newRoot->height = 1 + max(height(newRoot->left), height(newRoot->right));

        return newRoot;
    }

    BSTNode<T>* RotateLeft(BSTNode<T>* r) {
        if (r == nullptr || r->right == nullptr) return r; // Guard
        BSTNode<T>* newRoot = r->right;
        r->right = newRoot->left;
        newRoot->left = r;

        r->height = 1 + max(height(r->left), height(r->right));
        newRoot->height = 1 + max(height(newRoot->left), height(newRoot->right));

        return newRoot;
    }

    BSTNode<T>* BalanceAVL(BSTNode<T>* r)
    {
        if (r == nullptr) return nullptr;
        int balance = height(r->left) - height(r->right);

        if (balance > 1) {
            if (height(r->left->left) >= height(r->left->right))
                return RotateRight(r);
            else {
                r->left = RotateLeft(r->left);
                return RotateRight(r);
            }
        }
        if (balance < -1) {
            if (height(r->right->right) >= height(r->right->left))
                return RotateLeft(r);
            else {
                r->right = RotateRight(r->right);
                return RotateLeft(r);
            }
        }

        return r;
    }

    BSTNode<T>* insert(T val, BSTNode<T>* r) {
        if (r == nullptr) {
            r = new BSTNode<T>(val);
            return r;
        }
        if (val < r->data)
            r->left = insert(val, r->left);
        else if (val > r->data)
            r->right = insert(val, r->right);

        r->height = 1 + max(height(r->left), height(r->right));

        return BalanceAVL(r);
    }

    BSTNode<T>* remove(BSTNode<T>* r, T val) {
        if (r == nullptr) return nullptr;

        if (val < r->data) {
            r->left = remove(r->left, val);
        } else if (val > r->data) {
            r->right = remove(r->right, val);
        } else {
            if (r->left == nullptr) {
                BSTNode<T>* temp = r->right;
                delete r;
                return temp;
            } else if (r->right == nullptr) {
                BSTNode<T>* temp = r->left;
                delete r;
                return temp;
            } else {
                T maxVal = getMax(r->left);
                r->data = maxVal;
                r->left = remove(r->left, maxVal);
            }
        }

        if (r == nullptr) return nullptr;

        r->height = 1 + max(height(r->left), height(r->right));
        return BalanceAVL(r);
    }

    BSTNode<T>* search(BSTNode<T>* r, T val) {
        if (r == nullptr || r->data == val)
            return r;
        if (val < r->data)
            return search(r->left, val);
        else
            return search(r->right, val);
    }

    T getMin(BSTNode<T>* r) {
        if (r == nullptr) throw runtime_error("Tree is empty");
        while (r->left != nullptr)
            r = r->left;
        return r->data;
    }

    T getMax(BSTNode<T>* r) {
        if (r == nullptr) throw runtime_error("Tree is empty");
        while (r->right != nullptr)
            r = r->right;
        return r->data;
    }

    void preorder(BSTNode<T>* r) {
        if (r == nullptr) return;
        cout << r->data << " ";
        preorder(r->left);
        preorder(r->right);
    }

    void inorder(ostream& os, BSTNode<T>* r) const {
        if (r == nullptr) return;
        inorder(os, r->left);
        os << r->data << endl;
        inorder(os, r->right);
    }

    void inorder(vector<T>& v, BSTNode<T>* r) const {
        if (r == nullptr) return;
        inorder(v, r->left);
        v.push_back(r->data);
        inorder(v, r->right);
    }

    void clear(BSTNode<T>*& r) {
        if (r == nullptr) return;
        clear(r->left);
        clear(r->right);
        r = nullptr;
        delete r;
    }

public:
    AvlTree() : root(nullptr) {}

    void insert(T val) {
        root = insert(val, root);
    }

    void remove(T val) {
        root = remove(root, val);
    }

    bool search(T val) {
        return search(root, val) != nullptr;
    }

    T getMin() {
        return getMin(root);
    }

    T getMax() {
        return getMax(root);
    }

    bool isEmpty() {
        return root == nullptr;
    }

    void clear() {
        clear(root);
    }

    void preorderPrint() {
        preorder(root);
        cout << endl;
    }

    friend ostream& operator<<(ostream& os, const AvlTree<T>& tree) {
        tree.inorder(os, tree.root);
        return os;
    }

    int height() {
        return height(root);
    }

    vector<T> AvlTreeAsVector() const {
        vector<T> v;
        inorder(v, root);
        return v;
    }
    
    ~AvlTree() {
        clear();
    }
};
