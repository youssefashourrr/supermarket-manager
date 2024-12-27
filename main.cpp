#include "headers/categories.h"
#include <iostream>
using namespace std;


int main() {
    Categories manyCs;
    for (const auto c : manyCs.getGroups()) {
        cout << c->getName() << endl << c->getProductCount() << endl;
        vector<Product> productList = c->getProducts()->AvlTreeAsVector();
        for (auto p : productList) cout << p;
    }

/*     Category* c1;
    c1 = new Category("fruits");
    c1->addProduct("apple", 1);
    c1->addProduct("avocado", 3);
    c1->addProduct("grapes", 2);
    c1->addProduct("banana", 5);

    Category* c2;
    c2 = new Category("vegetables");
    c2->addProduct("tomato", 5);
    c2->addProduct("lettuce", 6);
    c2->addProduct("brocoli", 2);
    c2->addProduct("onion", 1); */

/*  for (auto p : c2->getProducts().AvlTreeAsVector()) cout << p;
    for (auto p : c1->getProducts().AvlTreeAsVector()) cout << p; */

/*     manyCs.addCategory(c1);
    manyCs.addCategory(c2); */

    return 0;
}