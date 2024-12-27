#include "headers/orders.h"


    Orders::Orders() {
        // if file not empty -> 
            // read queue file
                // copy id and name to variables
                // use product constructor for each product and store in linked list
                // create order object for each order using constructor
            // same process for proccesed vector
        // else -> empty queue, empty vector
    }

    queue<Order> Orders::getPending() const {
        return this->pendingQ;
    }

    vector<Order> Orders::getProcessed() const {
        return this->processed;
    }

    void Orders::addOrder(Order order){
        pendingQ.push(order);
        // add new order to queue file
    }

    void Orders::processOrder(){
        Order current = pendingQ.front();
        // remove product quantities from inventory (ashour)
        processed.push_back(current);
        pendingQ.pop();
        // remove order from queue file
        // add order to vector file
    }