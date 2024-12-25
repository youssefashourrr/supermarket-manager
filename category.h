#include "avltree.h"
#include "product.h"

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
  void addProduct(string,float);
  AvlTree<product> getProducts();
  void removeProduct(string);
  ~Category();
};