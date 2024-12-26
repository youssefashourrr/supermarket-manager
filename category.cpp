#include "category.h"


Category::Category(string name, int numberOfProducts, AvlTree<Product> products)
{
  this->name = name;
  this->numOfProducts = numberOfProducts;
  this->products = products;
}

void Category::setName(string cname)
{
    name = cname;
}

string Category::getName() const
{
    return name;
}

int Category::getProductCount() const{
	return numOfProducts;
}

void Category::addProduct(string item, float price)
{
    numOfProducts ++;
    string cat = name.substr(0,2);
    for(char& c : cat) c = toupper(c);
    cat += "-" + to_string(numOfProducts);
    Product p(item, price, cat);
    products.insert(p);
}

void Category::removeProduct(string item)
{
  Product p(item, 0.0, "");
  bool found = products.search(p);
  if (found) products.remove(p);
}

AvlTree<Product> Category::getProducts() const
{
  return products;
}

Category::~Category()
{
  products.clear();
}