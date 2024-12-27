#include "../ds-templates/avltree.h"
#include "product.h"


class Category
{
private:
    AvlTree<Product> products;
    string name;
    int numOfProducts = 0;

public:
	Category(string);
	Category(string, int, AvlTree<Product>);
  	void setName(string);
	AvlTree<Product> getProducts() const;
	string getName() const;
	int getProductCount() const;
	void addProduct(string, float);
	void removeProduct(string);
	bool operator<(const Category&) const;
	~Category();
};