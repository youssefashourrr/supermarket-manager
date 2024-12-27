#include "category.h"
#include "../json.hpp"   // For JSON handling using nlohmann::json
#include <iostream>   // For input/output operations (cin, cout)
#include <fstream>    // For file operations (ifstream, ofstream)
#include <set>        // For std::set to store categories
#include <string>     // For std::string
#include <vector>     // For std::vector to store product lists

using namespace std;
using json = nlohmann::json;


class Categories {
    private:
        set<Category> groups;
    
    public:
        Categories();
        set<Category> getGroups() const;
        void addCategory(Category);
        void removeCategory(string);
        set<Category>::iterator findCategory(string);
        bool isInCategories(const string &name) const;
        void saveCategoriesToFile();
};