#include <bits/stdc++.h>
#include "product.h"
using namespace std;

product::product()
{
  this->name = "";
  this->price = 0.0;
  this->quantity = 0;
  this->code = "";
}

product::product(string name)
{
    this->name = name;
    this->price = 0.0;
    this->quantity = 0;
    this->code = "";
}
product::product(string name, float price, int quantity, string code)
{
  this->name = name;
  this->price = price;
  this->quantity = quantity;
  this->code = code;
}

string product::getName()
{
    return name;
}

float product::getPrice()
{
	return price;
}

int product::getQuantity()
{
	return quantity;
}

string product::getCode()
{
	return code;
}

void product::setName(string name)
{
	this->name = name;
}

void product::setPrice(float price)
{
	this->price = price;
}

void product::setCode(string code)
{
	this->code = code;
}

void product::addQuantity(int quantity)
{
  this->quantity += quantity;
}

product& product::getProduct()
{
	  return *this;
}

bool product::operator<(const product& other) const
{
  return this->name < other.name;
}

bool product::operator>(const product& other) const
{
  return this->name > other.name;
}

bool product::operator<=(const product& other) const
{
  return this->name <= other.name;
}

bool product::operator>=(const product& other) const
{
  return this->name >= other.name;
}

bool product::operator==(const product& other) const
{
  return this->name == other.name;
}

bool product::operator!=(const product& other) const
{
  return !(this->name == other.name);
}

ostream& operator<<(ostream& os, const product& item)
{
   os<<"Product: "<< item.name<<" "<<item.code<<endl;
   return os;
}
