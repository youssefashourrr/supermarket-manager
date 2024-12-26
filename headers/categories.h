#include <iostream>
#include <set>
#include "category.h"


class Categories {
    private:
        set<Category> groups;
    
    public:
        Categories();
        void addCategory(Category);
        void removeCategory(string);
        set<Category>::iterator findCategory(string);
        bool isInCategories(const string &name) const;
        void saveCategoriesToFile();
};