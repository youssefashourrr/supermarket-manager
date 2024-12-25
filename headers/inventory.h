#define ALERT_THRESHOLD 3

#include <iostream>
#include <map>
#include <category.h>
using namespace std;


class Inventory {
    private:
        map<Product, int> stock;
        map<string, bool> alert;

    public:
        Inventory();
        map<Product, int> getStock() const;

        void addProduct(Product);
        void removeProduct(Product);
        void incrementQuantity(Product, int);
        void decrementQuantity(Product, int);
};