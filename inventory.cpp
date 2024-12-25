#include <inventory.h>


Inventory::Inventory() {
    // if file not empty -> read from file
    // else -> empty map
}

map<product, int> Inventory::getStock() const {
    return this->stock;
}

void Inventory::addProduct(product item) {
    if (stock.count(item) == 1) {
        stock[item]++;
    }
    else {
        // add to respective category tree from store
        stock[item] = 1;
    }

    if (stock[item] < ALERT_THRESHOLD) {
        alert[item.getName()] = true;
    }
    else {
        alert[item.getName()] = false;
    }
}

void Inventory::removeProduct(product item) {
    // remove from respective category tree
    stock.erase(item);
}

void Inventory::incrementQuantity(product item, int count) {
    stock[item] += count;
    if (stock[item] < ALERT_THRESHOLD) {
        alert[item.getName()] = true;
    }
    else {
        alert[item.getName()] = false;
    }
}

void Inventory::decrementQuantity(product item, int count) {
    if (stock[item] - count < 0) {
        cout << "not enough products" << endl;
        exit(-1);
    }
    stock[item] -= count;

    if (stock[item] < ALERT_THRESHOLD) {
        alert[item.getName()] = true;
    }
    else {
        alert[item.getName()] = false;
    }
}