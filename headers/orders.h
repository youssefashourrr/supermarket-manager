#include <queue>
#include <vector>
#include "order.h"


class Orders {
    private:
        queue<Order> pendingQ;
        vector<Order> processed;

    public:
        Orders();
        queue<Order> getPending() const;
        vector<Order> getProcessed() const;
        void addOrder(Order);
        void processOrder();
};