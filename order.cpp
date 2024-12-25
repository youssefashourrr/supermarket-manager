#include <order.h>


Order::Order(string id, Double_LL<product> checkoutItems) {
    this->id = id;
    //user declaration
    this->checkoutItems = checkoutItems;
}

Double_LL<product> Order::getItems() const {
    return this->checkoutItems;
}