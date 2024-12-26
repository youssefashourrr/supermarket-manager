#include <iostream>
#include <set>
#include "category.h"


class Categories {
    private:
        set<Category> groups;
    
    public:
        Categories();
        bool isInCategories(const string &name) const;
        void addCategory(Category);
        void removeCategory(string);
        set<Category>::iterator findCategory(string);
        void saveCategoriesToFile();

};