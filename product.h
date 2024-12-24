#include <bits/stdc++.h>
using namespace std;

class product
{
private:
  string name;
  float price;
  int quantity;
  string code;

public:
  product();
  product(string);
  product(string,float, int ,string);

  string getName();
  float getPrice();
  string getCode();
  int getQuantity();

  void setName(string);
  void setPrice(float);
  void addQuantity(int);

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




