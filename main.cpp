#include "headers/orders.h"
#include <iostream>
#include <queue>
using namespace std;


int main()
{
    DoubleLL<Product> Talab;
    Product p("Milk",20,"BE-1");
    Talab.AddtoTail(p);
    Talab.AddtoTail(Product("Apple Juice",15,"BE-2"));
    Talab.AddtoTail(Product("Water",5,"BE-3"));


    Order* x = new Order("Geo",&Talab);
    Node<Product>* Talab1 = x->getItems()->getHead();

    Orders History;
    History.addOrder(x);
    return 0;
}