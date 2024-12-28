#include <fstream>
#include "json.hpp"
#include "headers/orders.h"
using namespace std;
using json = nlohmann::json;

Orders::Orders()
{
    ifstream pendingFile("D:/PBLB/UNI/Data Structs/SuperMarket/supermarket-manager/data/pending_orders.json");
    ifstream processedFile("D:/PBLB/UNI/Data Structs/SuperMarket/supermarket-manager/data/processed_orders.json");
    pendingQ = queue<Order*>();
    processed = vector<Order*>();
    if (pendingFile.is_open())
    {
        json pendingJson;
        pendingFile >> pendingJson;
        for (const auto& orderData : pendingJson)
        {
            std::string id = orderData["id"];
            std::string name = orderData["name"];
            DoubleLL<Product>* items;
            for (const auto& item : orderData["items"])
            {
                cout<<Product(item);
                items->AddtoTail(Product(item));
            }
            Order* order=  new Order(id,items); // remove name
            pendingQ.push(order);
        }
    }

    if (processedFile.is_open()) {
        json processedJson;
        processedFile >> processedJson;
        for (const auto& orderData : processedJson) {
            string id = orderData["id"];
            string name = orderData["name"];
            DoubleLL<Product>* items;
            for (const auto& item : orderData["items"])
            {
                cout<<Product(item);
                items->AddtoTail(Product(item));
            }
            Order* order = new Order(id, items);
            processed.push_back(order);
        }
    }
}

void Orders::savePendingOrders()
{
    ofstream pendingFile("D:/PBLB/UNI/Data Structs/SuperMarket/supermarket-manager/data/pending_orders.json");
    if (pendingFile.is_open())
    {
        json pendingJson;
        // Iterate through the pending orders and serialize them
        while (!pendingQ.empty()) {
            Order* order = pendingQ.front();
            pendingQ.pop();

            json orderJson;
            orderJson["id"] = order->getId();
//          orderJson["name"] = order.getName();
            Node<Product>* temp = order->getItems()->getHead();
            orderJson["items"];
            while (temp != nullptr)
            {
                orderJson["items"].push_back(temp->data.toJson());
                temp = temp->next;
            }
            pendingJson.push_back(orderJson);
        }

        pendingFile << pendingJson.dump(4);  // Pretty print JSON with 4 spaces of indentation
    }
    cout<<"Saved Successfully"<<endl;
}

void Orders::saveProcessedOrders()
{
    std::fstream processedFile("data/processed_orders.json", std::ios::out | std::ios::trunc);
    if (processedFile.is_open()) {
        json processedJson;

        // Serialize processed orders
        for (const auto& order : processed) {
            json orderJson;
            orderJson["id"] = order->getId();
            //orderJson["name"] = order.getName();
            Node<Product>* temp = order->getItems()->getHead();
            orderJson["items"];
            while (temp != nullptr)
            {
                orderJson["items"].push_back(temp->data.toJson());
                temp = temp->next;
            }
            processedJson.push_back(orderJson);
        }

        processedFile << processedJson.dump(4);  // Pretty print JSON with 4 spaces of indentation
    }
}

queue<Order*>* Orders::getPending()
{
    return &pendingQ;
}

vector<Order*>* Orders::getProcessed()
{
    return &processed;
}

void Orders::addOrder(Order* order)
{
    pendingQ.push(order);
    savePendingOrders();  // Save updated pending orders to file
}

void Orders::processOrder() {
    Order* current = pendingQ.front();
    // Remove product quantities from inventory (assuming such logic exists elsewhere)
    processed.push_back(current);
    pendingQ.pop();
    savePendingOrders();   // Save updated pending orders to file
    saveProcessedOrders(); // Save updated processed orders to file
}
