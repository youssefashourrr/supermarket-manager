#include <iostream>
#include <stack>
#include "product.h"
#include "double-ll.h"
using namespace std;
class shoppingcart {
private:
    DoubleLL<Product> cartItems;
public:
    shoppingcart();
    void addItem(const Product& item, int quantity = 1);
    void removeItem(const Product& item);
    void updateQuantity(const Product& item, bool flag);
    DoubleLL<Product> getCart();
};
