#include "headers/categories.h"


Categories::Categories() {
    groups = {};
    ifstream file("data/categories.json", ios::in | ios::ate);
    if (!file.is_open()) {
        cout << "Failed to open categories file. Initializing empty categories." << endl;
        return;
    }

    if (file.tellg() == 0) {
        cout << "Categories file is completely empty." << endl;
        file.close();
        return;
    }

    file.seekg(0);
    json categoriesJson;
    try {
        file >> categoriesJson;
    } 
    catch (const std::exception& e) {
        cout << "Error parsing JSON: " << e.what() << endl;
        file.close();
        return;
    }
    file.close();

    if (categoriesJson.is_array()) {
        if (categoriesJson.empty()) {
            cout << "Categories file contains an empty array ([])." << endl;
        } 
        else {
            for (const auto& categoryJson : categoriesJson) {
                try {
                    string name = categoryJson.at("name");
                    int productCount = categoryJson.at("productCount");
                    AvlTree<Product> products;

                    for (const auto& productJson : categoryJson.at("products")) {
                        Product product(productJson);
                        products.insert(product);
                    }

                    groups.insert(new Category(name, productCount, &products));
                } 
                catch (const std::exception& e) {
                    cout << "Error parsing category or product: " << e.what() << endl;
                }
            }
        }
    } 
    else {
        cout << "Categories file is malformed or not a valid JSON array." << endl;
    }
}

Categories::~Categories() {
    for (auto category : groups) {
        delete category;  // Free allocated memory
    }
    groups.clear();  // Clear the set after deletion
}

set<Category*> Categories::getGroups() const {
    return groups;
}

bool Categories::isInCategories(const string& name) const {
    for (const auto& category : groups) {
        if (category != nullptr && category->getName() == name) {
            return true;
        }
    }
    return false;
}

set<Category*>::iterator Categories::findCategory(string name) {
    for (auto it = groups.begin(); it != groups.end(); ++it) {
        if (*it != nullptr && (*it)->getName() == name) {
            return it;
        }
    }
    return groups.end();
}

void Categories::addCategory(Category* c) {
    if (c == nullptr) {
        cerr << "Cannot add a null category." << endl;
        return;
    }
    groups.insert(c);
    saveCategoriesToFile();
}

void Categories::removeCategory(string name) {
    auto it = findCategory(name);
    if (it != groups.end()) {
        delete *it;          // Free memory for the removed category
        groups.erase(it);    // Remove from the set
        saveCategoriesToFile();
    } else {
        cout << "Category '" << name << "' not found, nothing to remove." << endl;
    }
}

void Categories::saveCategoriesToFile() {
    ofstream outFile("data/categories.json");
    if (outFile.is_open()) {
        json categoriesJson = json::array();
        for (const auto category : groups) {
            if (category == nullptr) continue;  // Avoid null pointer access
            json categoryJson;
            categoryJson["name"] = category->getName();
            categoryJson["productCount"] = category->getProductCount();

            vector<Product> productList = category->getProducts()->AvlTreeAsVector();
            categoryJson["products"] = json::array();
            for (auto& product : productList) {
                categoryJson["products"].push_back(product.toJson());
            }

            categoriesJson.push_back(categoryJson);
        }

        outFile << categoriesJson.dump(4);
        outFile.close();
        cout << "File has been cleared and categories saved successfully." << endl;
    } 
    else {
        cerr << "Failed to open the file for saving categories." << endl;
    }
}
