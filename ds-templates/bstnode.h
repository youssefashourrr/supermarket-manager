#include <cstddef>


template<class T>
struct BSTNode
{
    T data;
    BSTNode<T>* left;
    BSTNode<T>* right;
    int height;

    BSTNode(T val, BSTNode<T>* l = NULL, BSTNode<T>* r = NULL)
    {
        data = val;
        left = l;
        right = r;
        height = 1;
    }
};
