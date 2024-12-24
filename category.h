#include <bits/stdc++.h>
#include "product.h"
#include "avltree.h"
using namespace std;

class Category
{
private:
    AvlTree<product> products;
    string name;
    int NumofProducts;

public:
  Category();
  Category(string,int);
  void setName(string);
  void addProduct(string,float,int);
  AvlTree<product> getProducts();
  void removeProduct(string);
  ~Category();
};






