#include "headers/inventory.h"


Inventory::Inventory() {
    stock.clear(); // Initialize stock as empty

    ifstream file("data/stock.json", ios::in | ios::ate); // Open the file in read mode
    if (!file.is_open()) {
        cout << "Failed to open stock file. Initializing empty stock." << endl;
        return;
    }

    if (file.tellg() == 0) { // Check if the file is empty
        cout << "Stock file is completely empty." << endl;
        file.close();
        return;
    }

    file.seekg(0); // Reset the file pointer to the beginning
    json stockJson;
    try {
        file >> stockJson; // Parse the JSON content
    } 
    catch (const std::exception& e) {
        cout << "Error parsing JSON: " << e.what() << endl;
        file.close();
        return;
    }
    file.close();

    // Ensure the JSON is an array
    if (!stockJson.is_array()) {
        cout << "Stock file is malformed or not a valid JSON array." << endl;
        return;
    }

    // Parse each entry in the JSON array
    for (const auto& entryJson : stockJson) {
        try {
            // Extract required fields from each entry
            string name = entryJson.at("name");
            string id = entryJson.at("id");
            float price = entryJson.at("price");
            int quantity = entryJson.at("quantity");

            // Create a Product and insert it into the stock map
            Product product(name, price, id);
            stock[product] = quantity;
        } 
        catch (const std::exception& e) {
            cout << "Error parsing entry: " << e.what() << endl;
        }
    }

    for (const auto& p : stock) {
        if (p.second < ALERT_THRESHOLD) {
            alert[p.first.getName()] = true;
        }
        else {
            alert[p.first.getName()] = false;
        }
    }
}

map<Product, int> Inventory::getStock() const {
    return stock;
}

void Inventory::addProduct(Product item) {
    if (stock.count(item)) {
        stock[item]++;
    } 
    else {
        stock[item] = 1;
    }

    if (stock[item] < ALERT_THRESHOLD) {
        alert[item.getName()] = true;
    } 
    else {
        alert[item.getName()] = false;
    }

    saveToFile();
}

void Inventory::removeProduct(Product item) {
    stock.erase(item);
    alert.erase(item.getName());
    saveToFile();
}

void Inventory::incrementQuantity(Product item, int count) {
    stock[item] += count;

    if (stock[item] < ALERT_THRESHOLD) {
        alert[item.getName()] = true;
    } else {
        alert[item.getName()] = false;
    }

    saveToFile();
}

void Inventory::decrementQuantity(Product item, int count) {
    if (stock[item] - count < 0) { 
        cout << "Not enough products" << endl;
        exit(-1);
    }
    stock[item] -= count;

    if (stock[item] < ALERT_THRESHOLD) {
        alert[item.getName()] = true;
    } else {
        alert[item.getName()] = false;
    }

    saveToFile();
}

void Inventory::saveToFile() {
    json stockJson = json::array(); // Create a JSON array for stock

    // Serialize stock into the JSON array
    for (const auto& pair : stock) {
        json productJson;
        productJson["name"] = pair.first.getName();   // Product name
        productJson["id"] = pair.first.getCode();     // Product ID
        productJson["price"] = pair.first.getPrice(); // Product price
        productJson["quantity"] = pair.second;        // Product quantity

        stockJson.push_back(productJson); // Add product JSON to the array
    }

    ofstream file("data/stock.json"); // Open the file for writing
    if (!file.is_open()) {
        cout << "Failed to open stock file for saving." << endl;
        return;
    }

    file << stockJson.dump(4); // Write the JSON array to the file (pretty-printed)
    file.close(); // Close the file after saving
    cout << "Stock saved successfully." << endl;
}
