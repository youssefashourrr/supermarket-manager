#include "inventory.h"


Inventory::Inventory() {
    // if file not empty ->
        // find product with same name in categories
        // add ordered pair with found product : quantity
    // else -> empty map
}

map<Product, int> Inventory::getStock() const {
    return this->stock;
}

void Inventory::addProduct(Product item) {
    if (stock.count(item) == 1) {
        stock[item]++;
        // increment product value in file
    }
    else {
        // add to respective category tree from store (ashour)
        stock[item] = 1;
        // add new product key in file
    }

    if (stock[item] < ALERT_THRESHOLD) {
        alert[item.getName()] = true;
    }
    else {
        alert[item.getName()] = false;
    }
}

void Inventory::removeProduct(Product item) {
    // remove from respective category tree (ashour)
    stock.erase(item);
    // remove product key from file
}

void Inventory::incrementQuantity(Product item, int count) {
    stock[item] += count;
    // increment product value by count in file
    if (stock[item] < ALERT_THRESHOLD) {
        alert[item.getName()] = true;
    }
    else {
        alert[item.getName()] = false;
    }
}

void Inventory::decrementQuantity(Product item, int count) {
    if (stock[item] - count < 0) {
        cout << "not enough products" << endl;
        exit(-1);
    }
    stock[item] -= count;
    // decrement product value by count in file

    if (stock[item] < ALERT_THRESHOLD) {
        alert[item.getName()] = true;
    }
    else {
        alert[item.getName()] = false;
    }
}