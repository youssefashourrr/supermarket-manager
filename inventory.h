#define ALERT_THRESHOLD 3

#include <iostream>
#include <map>
#include <category.h>
using namespace std;


class Inventory {
    private:
        map<product, int> stock;
        map<string, bool> alert;

    public:
        Inventory();
        map<product, int> getStock() const;

        void addProduct(product);
        void removeProduct(product);
        void incrementQuantity(product, int);
        void decrementQuantity(product, int);
};