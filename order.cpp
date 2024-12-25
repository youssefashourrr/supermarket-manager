#include "order.h"


Order::Order(string id, DoubleLL<Product> checkoutItems) {
    this->id = id;
    //user declaration (ashour)
    this->checkoutItems = checkoutItems;
}

DoubleLL<Product> Order::getItems() const {
    return this->checkoutItems;
}