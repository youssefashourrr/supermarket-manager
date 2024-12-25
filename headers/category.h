#include "avltree.h"
#include "product.h"


class Category
{
private:
    AvlTree<Product> products;
    string name;
    int numOfProducts;

public:
	Category(string, int, AvlTree<Product>);
  	void setName(string);
	AvlTree<Product> getProducts() const;
	string getName() const;
	void addProduct(string, float);
	void removeProduct(string);
	~Category();
};