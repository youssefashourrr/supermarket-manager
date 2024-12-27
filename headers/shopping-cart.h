#include "../ds-templates/double-ll.h"
#include "product.h"


class ShoppingCart {
private:
    DoubleLL<Product> cartItems;

public:
    ShoppingCart();
    void addItem(const Product&, int);
    void removeItem(const Product&);
    void updateQuantity(const Product&, bool);
    DoubleLL<Product> getCart();
};
