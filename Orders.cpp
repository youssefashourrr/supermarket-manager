#include <iostream> 
using namespace std;
#include <Double-ll.h>
#include <queue>
#include <shopping.h>


template <class T>
class Orders{
private:
        queue<T> orderQueue;

public:
        Orders(shopping<T>& cart){
            Double_LL<T>* items = cart.getitems();
            node<T>* current = items->getHead();

        
        while(current != nullptr){
            orderQueue.push(current->data);
            current = current->next;
          }
        }

    void addOrder(const T& order){
        orderQueue.push(order);
        cout << "Order added: " << order << endl;
    }

void processOrder(){
    if(orderQueue.empty()){
        cout << "No orders to process" << endl;
        return;
    }
     
     T order = orderQueue.front();
     orderQueue.pop();
     cout << "Order processed: " << order << endl;
}

void viewOrders(){
    if(orderQueue.empty()){
        cout << "No orders are in the queue" << endl;
        return;
    }

    queue<T> tempQueue = orderQueue;
    cout << "Orders in the queue: ";
    while(!tempQueue.empty()){
        cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    cout << endl;

}
bool isempty() const{
    return orderQueue.empty();
}

};