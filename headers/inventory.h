#define ALERT_THRESHOLD 3

#include <fstream>
#include <iostream>
#include <map>
#include "../json.hpp"
#include "product.h"

using namespace std;
using json = nlohmann::json;


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
        void saveToFile();
};