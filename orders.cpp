#include <orders.h>


    Orders::Orders() {
        // if file not empty -> read from file
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
    }

    void Orders::processOrder(){
        Order current = pendingQ.front();
        // remove product quantities from inventory
        processed.push_back(current);
        pendingQ.pop();
    }