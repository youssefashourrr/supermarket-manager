#include <iostream>
using namespace std;


class product
{
private:
  string name;
  float price;
  string code;

public:
  product();
  product(string);
  product(string,float,string);

  string getName();
  float getPrice();
  string getCode();

  void setName(string);
  void setPrice(float);
  void setCode(string);

  product& getProduct();
  friend ostream& operator<<(ostream& os, const product&);

  bool operator<(const product& other) const;
  bool operator>(const product& other) const;
  bool operator<=(const product& other) const;
  bool operator>=(const product& other) const;
  bool operator==(const product& other) const;
  bool operator!=(const product& other) const;
};