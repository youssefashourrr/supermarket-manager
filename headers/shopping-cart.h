#include "../ds-templates/double-ll.h"
#include "product.h"

class ShoppingCart
{
private:
    DoubleLL<Product>* cartItems;
    float price;

public:
    ShoppingCart();
    void setPrice(float);
    void addItem(const Product&, int);
    void removeItem(const Product&);
    void updateQuantity(const Product&, bool);
    DoubleLL<Product>* getItems() const;
    float getPrice() const;
};
