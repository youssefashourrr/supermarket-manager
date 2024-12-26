#include "categories.h"
#include "avltree.h"
#include "category.h"
#include <iostream>   // For input/output operations (cin, cout)
#include <fstream>    // For file operations (ifstream, ofstream)
#include <set>        // For std::set to store categories
#include <string>     // For std::string
#include <vector>     // For std::vector to store product lists
#include "json.hpp"   // For JSON handling using nlohmann::json

using namespace std;
using json = nlohmann::json;

Categories::Categories() {
    // Load categories from the file
    ifstream file("categories.json"); // Open JSON file for reading
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
}

bool Categories::isInCategories(const string& name) const {
    // Iterate over the categories in the set
    for (const auto& category : groups) {
        if (category.getName() == name) {
            return true; // Found a matching category
        }
    }
    return false; // No matching category found
}

void Categories::addCategory(Category c) {
    groups.insert(c); // Add new category to the set

    // Save updated categories to the file
    saveCategoriesToFile();
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
    json categoriesJson = json::array(); // JSON array to hold all categories

    // Iterate through the set of categories
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

    // Write the JSON array to the file
    ofstream file("categories.json");
    if (file.is_open()) {
        file << categoriesJson.dump(4); // Pretty-print JSON with 4 spaces of indentation
        file.close();
    }
}

