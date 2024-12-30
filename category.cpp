#include "headers/category.h"


Category::Category(string name)
{
	this->name = name;
	products = new AvlTree<Product>;
	this->numOfProducts = 0;
}

Category::Category(string name, int numberOfProducts, AvlTree<Product>* products)
{
  this->name = name;
  this->numOfProducts = numberOfProducts;
  this->products = products;
}

void Category::setName(string name)
{
    this->name = name;
}

AvlTree<Product>* Category::getProducts()
{
  return products;
}

string Category::getName() const
{
    return name;
}

int Category::getProductCount() const{
	return numOfProducts;
}

string Category::addProduct(string item, float price)
{
    numOfProducts++;
    string cat = name.substr(0,3);
    for(char& c : cat) c = toupper(c);
    cat += "-" + to_string(numOfProducts);
    Product p(item, price, cat);
    products->insert(p);
    return cat;
}

void Category::removeProduct(string item)
{
	Product temp(item, 0.0, "");
	bool found = products->search(temp);
	if (found) {
		products->remove(temp);
		numOfProducts--;
	}
}

bool Category::operator<(const Category& other) const 
{
	return name < other.name;
}

Category::~Category()
{
  products->clear();
}