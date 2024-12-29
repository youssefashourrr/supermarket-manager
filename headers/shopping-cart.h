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
    void addItem(const Product&);
    void removeItem(const Product&);
    void updateQuantity(const Product&, bool);
    ShoppingCart* getObject();
    DoubleLL<Product>* getItems() const;
    float getPrice() const;
};
