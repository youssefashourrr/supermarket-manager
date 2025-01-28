#include "category.h"
#include "../third-party/json.hpp"
#include <iostream>
#include <fstream>
#include <set>
#include <vector>

using namespace std;
using json = nlohmann::json;


class Categories {
    private:
        set<Category*> groups;
    
    public:
        Categories();
        ~Categories();
        set<Category*>* getGroups();
        bool addCategory(Category*);
        bool removeCategory(string);
        set<Category*>::iterator findCategory(string);
        bool isInCategories(const string &name) const;
        void saveToFile();
};