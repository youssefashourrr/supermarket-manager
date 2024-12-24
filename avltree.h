#include "bstnode.h"


template<class T>
class AvlTree
{
private:
    BSTNode<T>* root;

    BSTNode<T>* BalanceAVL(BSTNode<T>* r, T val)
    {
        if (r == nullptr) return nullptr;
        int balance = height(r->left) - height(r->right);
        if (balance > 1 && (height(r->left->left) >= height(r->left->right)))
        {
            return RotateRight(r);
        }
        if (balance > 1 && (height(r->left->left) < height(r->left->right)))
        {
            r->left = RotateLeft(r->left);
            return RotateRight(r);
        }
        if (balance < -1 && height(r->right->right) >= height(r->right->left))
        {
            return RotateLeft(r);
        }
        if (balance < -1 && height(r->right->right) < height(r->left->left))
        {
            r->right = RotateRight(r->right);
            return RotateLeft(r);
        }

        return r;
    }

    BSTNode<T>* RotateRight(BSTNode<T>* r)
    {
        BSTNode<T>* y = r->left->right;
        r->left->right = r;
        r = r->left;
        r->right->left = y;

        r->right->height = 1 + max(height(r->right->right), height(r->right->left));
        r->height = 1 + max(height(r->left), height(r->right));

        return r;
    }

    BSTNode<T>* RotateLeft(BSTNode<T>* r)
    {
        BSTNode<T>* t = r->right->left;
        r->right->left = r;
        r = r->right;
        r->left->right = t;

        r->left->height = 1 + max(height(r->left->right) , height(r->left-> left));
        r->height = 1 + max(height(r->left), height(r->right));
        return r;
    }

    BSTNode<T>* insert(T val,BSTNode<T>* r)
    {
        if(!r) r = new BSTNode<T>(val);
        else
        {
            if (r->data <= val) r->right = insert(val,r->right);
            else if (r->data > val) r->left = insert(val,r->left);
        }

        r->height = 1 + max(height(r->left),height(r->right));

        return BalanceAVL(r,val);
    }

    BSTNode<T>* remove(BSTNode<T>* r, T val)
    {
        if (r == NULL) return NULL;

        if (val < r->data)
        {
            r->left = remove(r->left, val);
        }
        else if (val > r->data)
        {
            r->right = remove(r->right, val);
        }
        else
        {
            if (r->left == NULL)
            {
                BSTNode<T>* temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL)
            {
                BSTNode<T>* temp = r->left;
                delete r;
                return temp;
            }
            else
            {
                T maxVal = getMax(r->left);
                r->data = maxVal;
                r->left = remove(r->left, maxVal);


            }
        }

        if (r == NULL) return NULL;

        r->height = 1 + max(height(r->left), height(r->right));

        return BalanceAVL(r, val);
    }

    BSTNode<T>* search(BSTNode<T>* r, T val)
    {
        if(r->data == val || r == nullptr) return r;
        else if(val < r->data) return search(r->left, val);
        else return search(r->right, val);
    }

    T getMin(BSTNode<T>* r)
    {
        if(isEmpty()) throw runtime_error("Tree is empty\n");
        else if(r->left == NULL) return r->data;
        else return getMin(r->left);
    }

    T getMax(BSTNode<T>* r)
    {
        if(isEmpty()) throw runtime_error("Tree is empty\n");
        else if(r->right == NULL) return r->data;
        else return getMax(r->right);
    }

    void clear(BSTNode<T>*& r)
    {
        if (r == nullptr) return;
        clear(r->right);
        clear(r->left);
        r = nullptr;
        delete r;
    }


    int height(BSTNode<T>* r)
    {
        return r ? r->height : 0;
    }
    void preorder(BSTNode<T>* r)
    {
        if(r==nullptr) return;
        cout<< r->data;
        preorder(r->left);
        preorder(r->right);

    }

    void inorder(ostream& os, BSTNode<T>* r) const
    {
        if (r == nullptr) return;
        if (r->left) inorder(os, r->left);
        os << r->data;
        if (r-> right) inorder(os, r->right);
    }

public:
    AvlTree()
    {
        root = NULL;
    }

    AvlTree(T val)
    {
        root = new BSTNode<T>(val);
    }

    void insert(T val)
    {
        root = insert(val,root);
    }

    void remove(T val)
    {
        if (isEmpty()) return;
        root = remove(root, val);
    }

    bool search(const T& val)
    {
        return search(root, val) != nullptr;
    }

    T getMin()
    {
        return getMin(root);
    }

    T getMax()
    {
        return getMax(root);
    }

    bool isEmpty()
    {
        return root == NULL;
    }

    void clear()
    {
        clear(root);
    }

    void preorderPrint()
    {
        preorder(root);
        cout << endl;
    }

    friend ostream& operator<<(ostream& os, const AvlTree<T>& tree) {
        tree.inorder(os, tree.root);
        cout << endl;  
        return os;
    }

    int height( )
    {
        return height(root);
    }

    ~AvlTree()
    {
        clear();
    }
};