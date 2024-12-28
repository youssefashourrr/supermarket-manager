#include <queue>
#include <vector>
#include "order.h"


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
        void processOrder();
        void savePendingOrders();
        void saveProcessedOrders();

};