#include "headers/shopping-cart.h"


ShoppingCart::ShoppingCart() {} // (ashour)

void ShoppingCart::addItem(const Product &item, int quantity) {
    if (cartItems->search(item)) {
        updateQuantity(item, true);
        return;
    }
    cartItems->AddtoTail(item);
}

void ShoppingCart::removeItem(const Product &item) {
    if (cartItems->search(item) == false) return;
    updateQuantity(item,false);
}

void ShoppingCart::updateQuantity(const Product& item, bool flag) {
    //if (cartItems->search(item) == false) return;
    if (flag) cartItems->incrementQuantity(item);
    else cartItems->decrementQuantity(item);
}

DoubleLL<Product>* ShoppingCart::getCart()
{
    return cartItems;
}

Order ShoppingCart::convertToOrder()
{

}
