#include "headers/order.h"


Order::Order(string id, DoubleLL<Product>* checkoutItems)
{
    this->id = id;
    //user declaration (ashour)
    this->checkoutItems = checkoutItems;
}

string Order::getId()
{
  return this->id;
}

DoubleLL<Product>* Order::getItems()
{
    return checkoutItems;
}