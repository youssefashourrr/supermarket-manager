#include "../ds-templates/avltree.h"
#include "product.h"


class Category
{
private:
    AvlTree<Product>* products;
    string name;
    int numOfProducts = 0;

public:
	Category(string);
	Category(string, int, AvlTree<Product>*);
  	void setName(string);

	AvlTree<Product>* getProducts();
	string getName() const;
	int getProductCount() const;
	
	string addProduct(string, float);
	void removeProduct(string);

	bool operator<(const Category&) const;
	~Category();
};