#include <fstream>
#include "json.hpp"
#include "headers/orders.h"
using namespace std;
using json = nlohmann::json;

Orders::Orders() {
    ifstream pendingFile("D:/PBLB/UNI/Data Structs/SuperMarket/supermarket-manager/data/pending_orders.json");
    ifstream processedFile("D:/PBLB/UNI/Data Structs/SuperMarket/supermarket-manager/data/processed_orders.json");

    if (pendingFile.is_open())
    {
        json pendingJson;
        pendingFile >> pendingJson;
        for (const auto& orderData : pendingJson)
        {
            std::string id = orderData["id"];
            std::string name = orderData["name"];
            DoubleLL<Product> items;
            for (const auto& item : orderData["items"])
            {
                items.AddtoTail(Product(item));
            }
            Order order(id,items); // remove name
            pendingQ.push(order);
        }
    } else {
        // If the file is empty, create an empty queue
        pendingQ = std::queue<Order>();
    }

    if (processedFile.is_open() && processedFile.peek() != std::ifstream::traits_type::eof()) {
        json processedJson;
        processedFile >> processedJson;
        for (const auto& orderData : processedJson) {
            std::string id = orderData["id"];
            std::string name = orderData["name"];
            DoubleLL<Product> items = convert(orderData["items"]);

            Order order(id, name, items);
            processed.push_back(order);
        }
    } else {
        // If the file is empty, create an empty vector
        processed = std::vector<Order>();
    }
}

DoubleLL<Product> Orders::convert(const json& productsJson) {
    DoubleLL<Product> productList;

    for (const auto& productData : productsJson) {
        std::string id = productData["id"]; // change using yassers code
        std::string name = productData["name"];
        double price = productData["price"];
        Product product(name, price, id);  // Adjusted constructor usage


    }

    return productList;
}

void Orders::savePendingOrders() {
    std::fstream pendingFile("data/pending_orders.json", std::ios::out | std::ios::trunc);
    if (pendingFile.is_open()) {
        json pendingJson;

        // Iterate through the pending orders and serialize them
        while (!pendingQ.empty()) {
            Order order = pendingQ.front();
            pendingQ.pop();

            json orderJson;
            orderJson["id"] = order.getId();
            orderJson["name"] = order.getName();
            orderJson["items"] = serializeProducts(order.getItems()); // Serialize products list

            pendingJson.push_back(orderJson);
        }

        pendingFile << pendingJson.dump(4);  // Pretty print JSON with 4 spaces of indentation
    }
}

void Orders::saveProcessedOrders() {
    std::fstream processedFile("data/processed_orders.json", std::ios::out | std::ios::trunc);
    if (processedFile.is_open()) {
        json processedJson;

        // Serialize processed orders
        for (const auto& order : processed) {
            json orderJson;
            orderJson["id"] = order.getId();
            orderJson["name"] = order.getName();
            orderJson["items"] = serializeProducts(order.getItems()); // Serialize products list

            processedJson.push_back(orderJson);
        }

        processedFile << processedJson.dump(4);  // Pretty print JSON with 4 spaces of indentation
    }
}

json Orders::serializeProducts(const DoubleLL<Product>& products) {
    json productsJson = json::array();

    node<Product>* current = products.getHead(); // Assuming DoubleLL has getHead()
    while (current != nullptr) {
	while(current -> quantity--){

        json productJson;
        productJson["id"] = current->data.getCode();
        productJson["name"] = current->data.getName();
        productJson["price"] = current->data.getPrice();

        productsJson.push_back(productJson);
	}
        current = current->next;
    }

    return productsJson;
}

queue<Order> Orders::getPending() const {
    return this->pendingQ;
}

vector<Order> Orders::getProcessed() const {
    return this->processed;
}

void Orders::addOrder(Order order) {
    pendingQ.push(order);
    savePendingOrders();  // Save updated pending orders to file
}

void Orders::processOrder() {
    Order current = pendingQ.front();
    // Remove product quantities from inventory (assuming such logic exists elsewhere)
    processed.push_back(current);
    pendingQ.pop();
    savePendingOrders();   // Save updated pending orders to file
    saveProcessedOrders(); // Save updated processed orders to file
}
