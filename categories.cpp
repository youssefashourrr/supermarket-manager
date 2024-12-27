#include "headers/categories.h"


Categories::Categories() {
    // Load categories from the file
    ifstream file("data/categories.json"); // Open JSON file for reading
    json categoriesJson;             // JSON object to parse data
    if (file.is_open()) {
        file >> categoriesJson; // Read JSON content
        file.close();           // Close the file

        if (!categoriesJson.empty()) { // If file is not empty
            for (const auto& categoryJson : categoriesJson) {
                string name = categoryJson["name"];         // Extract category name
                int productCount = categoryJson["productCount"]; // Extract product count
                AvlTree<Product> products;
                for (const auto& productJson : categoryJson["products"]) {
                    Product product(productJson);  // Create Product object from JSON
                    products.insert(product);
                }
                // Create a category and add it to the set
                groups.insert(Category(name, productCount, products));
            }
        }
    }
    else {
        groups = {};
    }
}

set<Category> Categories::getGroups() const {
    return groups;
}

bool Categories::isInCategories(const string &name) const
{
    // Iterate over the categories in the set
    for (const auto& category : groups) {
        if (category.getName() == name) {
            return true; // Found a matching category
        }
    }
    return false; // No matching category found
}

set<Category>::iterator Categories::findCategory(string name) {
    for (set<Category>::iterator it = groups.begin(); it != groups.end(); it++) {
        if (it->getName() == name) return it;
    }
    return groups.end();
}

void Categories::addCategory(Category c) {
    groups.insert(c); // Add new category to the set
    // Save updated categories to the file
    saveCategoriesToFile();
    cout << "finished saving" << endl;
}

void Categories::removeCategory(string name) {
    if (this->isInCategories(name)) {
        auto it = this->findCategory(name); // Find the category
        groups.erase(it);                   // Remove it from the set
        // Save updated categories to the file
        saveCategoriesToFile();
    }
}

void Categories::saveCategoriesToFile() {
    // Step 1: Create the JSON object for categories
    json categoriesJson = json::array(); // JSON array to hold all categories

    // Iterate through the set of categories and build the JSON structure
    for (const auto& category : groups) {
        json categoryJson; // JSON object for a single category

        // Save category details
        categoryJson["name"] = category.getName();
        categoryJson["productCount"] = category.getProductCount();

        // Retrieve products as a vector and save to JSON
        vector<Product> productList = category.getProducts().AvlTreeAsVector();
        categoryJson["products"] = json::array(); // JSON array for products

        for (auto& product : productList) {
            categoryJson["products"].push_back(product.toJson()); // Serialize each product to JSON
        }

        // Add the category JSON object to the JSON array
        categoriesJson.push_back(categoryJson);
    }

    // Step 2: Open the file and overwrite its content with the new categories JSON
    ofstream file("data/categories.json", ios::trunc); // Open in trunc mode to clear file content
    if (file.is_open()) {
        // Write the categories JSON to the file, pretty-printing with 4 spaces of indentation
        file << categoriesJson.dump(4);  
        file.close();  // Close the file after writing
        cout << "Categories saved successfully to the file." << endl;
    } 
    else {
        cerr << "Failed to open the file for saving categories." << endl;
    }
}
