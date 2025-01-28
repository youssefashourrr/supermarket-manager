#include "../include/inventory.h"


Inventory::Inventory() {
    stock.clear();

    ifstream file("../data/stock.json", ios::in | ios::ate);
    if (!file.is_open()) {
        cout << "Failed to open stock file. Initializing empty stock." << endl;
        return;
    }

    if (file.tellg() == 0) {
        cout << "Stock file is completely empty." << endl;
        file.close();
        return;
    }

    file.seekg(0);
    json stockJson;
    try {
        file >> stockJson;
    } 
    catch (const std::exception& e) {
        cout << "Error parsing JSON: " << e.what() << endl;
        file.close();
        return;
    }
    file.close();

    if (!stockJson.is_array()) {
        cout << "Stock file is malformed or not a valid JSON array." << endl;
        return;
    }

    for (const auto& entryJson : stockJson) {
        try {
            string name = entryJson.at("name");
            string id = entryJson.at("id");
            float price = entryJson.at("price");
            int quantity = entryJson.at("quantity");

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

map<Product, int>* Inventory::getStock()
{
    return &(this->stock);
}

map<string, bool>* Inventory::getAlert()
{
    return &(this->alert);
}

map<Product, int>::iterator Inventory::removeProduct(Product item)
{
    auto it = stock.find(item);
    if (it != stock.end())
    {
        auto nextIt = stock.erase(it);
        alert.erase(item.getName());
        saveToFile();                
        return nextIt;               
    }
    ProductTrie.remove(item.getName());
    return stock.end(); 
}

void Inventory::addProduct(Product item, int count) {
    stock[item] += count;

    if (stock[item] < ALERT_THRESHOLD) {
        alert[item.getName()] = true;
    } else {
        alert[item.getName()] = false;
    }
    ProductTrie.insert(item.getName());
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
vector<string> Inventory::SearchProduct(const string &prefix)
{
    return ProductTrie.autocomplete(prefix);
}

void Inventory::saveToFile()
{
    json stockJson = json::array(); 

    for (const auto& pair : stock) {
        json productJson;
        if (pair.second)
        {
            productJson["name"] = pair.first.getName();   
            productJson["id"] = pair.first.getCode();     
            productJson["price"] = pair.first.getPrice(); 
            productJson["quantity"] = pair.second;        
        }
        stockJson.push_back(productJson); 
    }

    ofstream file("../data/stock.json");
    if (!file.is_open()) {
        cout << "Failed to open stock file for saving." << endl;
        return;
    }

    file << stockJson.dump(4);
    file.close();
    cout << "Stock saved successfully." << endl;
}
