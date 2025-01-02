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
        map<Product, int>* getStock();
        map<string, bool>* getAlert();
        //void addProduct(Product);
        map<Product,int>::iterator removeProduct(Product);
        void addProduct(Product item, int count);
        //void incrementQuantity(Product, int);
        void decrementQuantity(Product, int);
        void saveToFile();
};