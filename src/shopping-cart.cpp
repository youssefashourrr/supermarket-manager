#include "../include/shopping-cart.h"


ShoppingCart::ShoppingCart() {
    cartItems = new DoubleLL<Product>();
    this->price = 0;
}

void ShoppingCart::setPrice(float price) {
    this->price = price;
}

void ShoppingCart::addItem(const Product& item)
{
    this->price += item.getPrice();
    if (cartItems->search(item)) {
        updateQuantity(item, true);
        return;
    }
    cartItems->AddtoTail(item);
}

void ShoppingCart::removeItem(const Product& item) {
    this->price -= item.getPrice();
    if (cartItems->search(item) == false) return;
    updateQuantity(item, false);
}

void ShoppingCart::updateQuantity(const Product& item, bool flag) {
    if (cartItems->search(item) == false) return;
    if (flag) cartItems->incrementQuantity(item);
    else cartItems->decrementQuantity(item);
}

ShoppingCart* ShoppingCart::getObject() {
    return this;
}

DoubleLL<Product> *ShoppingCart::getItems() const
{
    return this->cartItems;
}

float ShoppingCart::getPrice() const {
    return this->price;
}