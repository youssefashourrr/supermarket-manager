#pragma once
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
#include "../json.hpp"
#include "order.h"

using namespace std;
using json = nlohmann::json;


class Orders
{
    private:
        queue<Order*> pendingQ;
        vector<Order*> processed;

    public:
        Orders();
        queue<Order*>* getPending();
        vector<Order*>* getProcessed();
        void addOrder(Order*);
        bool processOrder();
        
        void loadPendingOrders();
        void loadProcessedOrders();
        void savePendingOrders();
        void saveProcessedOrders();
};