#include "headers/orders.h"


Orders::Orders() {
    pendingQ = queue<Order*>();
    processed = vector<Order*>();
    loadPendingOrders();
    loadProcessedOrders();
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

bool Orders::processOrder() {
    if (!pendingQ.empty()) {    
        Order* current = pendingQ.front();
        processed.push_back(current);
        pendingQ.pop();
        if (pendingQ.empty()) pendingQ = {};
        savePendingOrders();   // Save updated pending orders to file
        saveProcessedOrders(); // Save updated processed orders to file}
        return true;
    }
    return false;
}

void Orders::loadPendingOrders() {
    ifstream pendingFile("D:/PBLB/UNI/Data Stucts/SuperMarket/supermarket-manager/data/pending_orders.json", ios::in | ios::ate);

    if (!pendingFile.is_open()) {
        cout << "Failed to open pending orders file. Initializing empty queue." << endl;
        return;
    }
    if (pendingFile.tellg() == 0) {
        cout << "Pending file is completely empty." << endl;
        pendingFile.close();
        return;
    }

    pendingFile.seekg(0);
    json pendingJson;
    try {
        pendingFile >> pendingJson;
        if (pendingJson.is_null()) return;
    } 
    catch (const std::exception& e) {
        cout << "Error parsing JSON: " << e.what() << endl;
        pendingFile.close();
        return;
    }
    pendingFile.close();

    if (pendingJson.is_array()) {
        if (pendingJson.empty()) {
            cout << "Pending orders file contains an empty array ([])." << endl;
        } 
        else {
            for (const auto& orderData : pendingJson) {
                string buyer = orderData["email"];
                ShoppingCart* cart = new ShoppingCart();;
                for (const auto& item : orderData["items"]) {
                    cart->getItems()->AddtoTail(Product(item));
                }
                cart->setPrice(orderData["price"]);
                Order* order =  new Order(buyer, cart);
                pendingQ.push(order);
            }
        }
    } 
    else {
        cout << "Pending file is malformed or not a valid JSON array." << endl;
    }
}

void Orders::loadProcessedOrders() {
    ifstream processedFile("D:/PBLB/UNI/Data Stucts/SuperMarket/supermarket-manager/data/processed_orders.json",  ios::in | ios::ate);

    if (!processedFile.is_open()) {
        cout << "Failed to open order history file. Initializing empty vector." << endl;
        return;
    }
    if (processedFile.tellg() == 0) {
        cout << "Processed file is completely empty." << endl;
        processedFile.close();
        return;
    }

    processedFile.seekg(0);
    json processedJson;
    try {
        processedFile >> processedJson;
    } 
    catch (const std::exception& e) {
        cout << "Error parsing JSON: " << e.what() << endl;
        processedFile.close();
        return;
    }
    processedFile.close();

    if (processedJson.is_array()) {
        if (processedJson.empty()) {
            cout << "Processed orders file contains an empty array ([])." << endl;
        } 
        else {
            for (const auto& orderData : processedJson) {
                string buyer = orderData["email"];
                ShoppingCart* cart = new ShoppingCart();;
                for (const auto& item : orderData["items"]) {
                    cart->getItems()->AddtoTail(Product(item));
                }
                cart->setPrice(orderData["price"]);
                Order* order =  new Order(buyer, cart);
                processed.push_back(order);
            }
        }
    } 
    else {
        cout << "Processed file is malformed or not a valid JSON array." << endl;
    }
}

void Orders::savePendingOrders() {
    ofstream pendingFile("D:/PBLB/UNI/Data Stucts/SuperMarket/supermarket-manager/data/pending_orders.json");
    if (pendingFile.is_open())
    {
        json pendingJson;
        // Iterate through the pending orders and serialize them
        while (!pendingQ.empty()) {
            Order* order = pendingQ.front();
            pendingQ.pop();

            json orderJson;
            orderJson["email"] = order->getBuyer();
            orderJson["price"] = order->getCart()->getPrice();
            Node<Product>* temp = order->getCart()->getItems()->getHead();
            orderJson["items"];
            while (temp != nullptr) {
                orderJson["items"].push_back(temp->data.toJson());
                temp = temp->next;
            }
            pendingJson.push_back(orderJson);
        }

        pendingFile << pendingJson.dump(4);  // Pretty print JSON with 4 spaces of indentation
    }
    cout<<"Saved Queue Successfully"<<endl;
}

void Orders::saveProcessedOrders() {
    ofstream processedFile("D:/PBLB/UNI/Data Stucts/SuperMarket/supermarket-manager/data/processed_orders.json");
    if (processedFile.is_open()) {
        json processedJson;

        // Serialize processed orders
        for (const auto& order : processed) {
            json orderJson;
            orderJson["email"] = order->getBuyer();
            orderJson["price"] = order->getCart()->getPrice();
            Node<Product>* temp = order->getCart()->getItems()->getHead();
            orderJson["items"];
            while (temp != nullptr) {
                orderJson["items"].push_back(temp->data.toJson());
                temp = temp->next;
            }
            processedJson.push_back(orderJson);
        }

        processedFile << processedJson.dump(4);  // Pretty print JSON with 4 spaces of indentation
    }
}