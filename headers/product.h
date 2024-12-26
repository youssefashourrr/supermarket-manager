#include <iostream>
using namespace std;


class Product
{
private:
  string name;
  float price;
  string code;

public:
  Product();
  Product(string);
  Product(string,float,string);
  Product(const json& productJson);
  json toJson();

  string getName();
  float getPrice();
  string getCode();

  void setName(string);
  void setPrice(float);
  void setCode(string);

  Product& getProduct();
  friend ostream& operator<<(ostream& os, const Product&);

  bool operator<(const Product& other) const;
  bool operator>(const Product& other) const;
  bool operator<=(const Product& other) const;
  bool operator>=(const Product& other) const;
  bool operator==(const Product& other) const;
  bool operator!=(const Product& other) const;
};