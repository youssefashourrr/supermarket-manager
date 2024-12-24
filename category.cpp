#include <bits/stdc++.h>
#include "category.h"
using namespace std;

Category::Category()
{
    products.clear();
    name = "";
    NumofProducts = 0;
}

Category::Category(string n,int ele = 0)
{
  name = n;
  NumofProducts = ele;
  products.clear();
}

void Category::setName(string cname)
{
    name = cname;
}
void Category::addProduct(string item,float price)
{
    string cat = name.substr(0,2);
    for(char& c : cat) c = toupper(c);
    cat+="-" + to_string(NumofProducts);
    product p(item,price,cat);
    products.insert(p);
}

void Category::removeProduct(string item)
{
  product p(item,0,0,"");
  bool found = products.search(p);
  if(found) products.remove(p);

}

AvlTree<product> Category::getProducts()
{
  return products;
}

Category::~Category()
{
  products.clear();
}
