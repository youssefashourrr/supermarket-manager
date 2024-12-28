#include "headers/order.h"


Order::Order(string buyer, ShoppingCart* checkout) {
    this->buyer = buyer;
    this->checkout = checkout;
}

string Order::getBuyer() const {
    return this->buyer;
}

ShoppingCart* Order::getCart() const {
    return this->checkout;
}