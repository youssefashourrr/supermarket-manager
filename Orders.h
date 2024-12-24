#include <iostream>
#include <queue>
#include "Double_LL.h"
#include "shopping.h"
#include "product.h"
using namespace std;



 
class Orders{
private:
    queue<Double_LL<product>> orderQueue;
public:
    Orders();

void addOrder(const Double_LL<product>&);

void processOrder();

void viewOrders() const;

bool isempty() const;



};