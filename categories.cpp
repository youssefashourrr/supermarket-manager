#include "categories.h"


Categories::Categories() {
    // if categories file not empty ->
        // go over each category
        // copy name and product count into variables
        // create vector for products
        // add all products to avl
        // call category constructor
        // add category to set
    // else -> empty set
}

void Categories::addCategory(Category c)
{
    groups.insert(c);
    // add new category to file
        // name, product count, products
}

void Categories::removeCategory(string name) {
    if (this->isInCategories(name)) {
        auto it = this->findCategory(name);
        groups.erase(it);
        // remove category and all its data from file
    }
}

bool Categories::isInCategories(string name) {
    for (auto c : groups) {
        if (c.getName() == name) return true;
    }
    return false;
}

set<Category>::iterator Categories::findCategory(string name) {
    for (set<Category>::iterator it = groups.begin(); it != groups.end(); it++) {
        if (it->getName() == name) return it;
    }
    return groups.end();
}
