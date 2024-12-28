#include "json.hpp"
#include "headers/product.h"

using namespace std;
using json = nlohmann::json;


Product::Product()
{
    this->name = "";
    this->price = 0;
    this->code = "";
}

Product::Product(string name)
{
    this->name = name;
    this->price = 0;
    this->code = "";
}

Product::Product(string name, float price, string code)
{
    this->name = name;
    this->price = price;
    this->code = code;
}

Product::Product(const json& productJson) {
	    this->name = productJson["name"];      // Extract name
        this->price = productJson["price"];    // Extract price
		this->code = productJson["code"];		// Extract code
}

json Product::toJson() {
    json productJson;
    productJson["name"] = this->name;
    productJson["price"] = this->price;
	productJson["code"]= this->code;
    return productJson;
}

string Product::getName() const
{
    return this->name;
}

float Product::getPrice() const
{
	return this->price;
}

string Product::getCode() const
{
	return this->code;
}

void Product::setName(string name)
{
	this->name = name;
}

void Product::setPrice(float price)
{
	this->price = price;
}

void Product::setCode(string code)
{
	this->code = code;
}

Product& Product::getProduct()
{
	return *this;
}

bool Product::operator<(const Product& other) const
{
  	return this->name < other.name;
}

bool Product::operator>(const Product& other) const
{
  	return this->name > other.name;
}

bool Product::operator<=(const Product& other) const
{
  	return this->name <= other.name;
}

bool Product::operator>=(const Product& other) const
{
    return this->name >= other.name;
}

bool Product::operator==(const Product& other) const
{
  	return this->name == other.name;
}

bool Product::operator!=(const Product& other) const
{
  	return !(this->name == other.name);
}

ostream& operator<<(ostream& os, const Product& item)
{
	os <<"Product: "<< item.name << endl 
       << "ID: " << item.code << endl
       << "Price: " << item.price << endl;
	return os;
}
