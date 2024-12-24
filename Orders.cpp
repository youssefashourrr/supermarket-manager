Orders::Orders(){
     orderQueue.clear();

}

    void Orders::addOrder(const Double_LL<product>& order){
        orderQueue.push(order);

    }

Double_LL<product> Orders::processOrder(){
    if(orderQueue.empty()){
        exit(-1);
    }
    else
    {
     Double_LL<product> order = orderQueue.front();
     orderQueue.pop();
    }
     return order;
    
}

void Orders::viewOrders(){
    if(orderQueue.empty()){
        return;
    }
    while(!tempQueue.empty()){ //to be continued
        tempQueue.pop();
    }
    

}
bool Orders::isempty() const{
    return orderQueue.empty();
}

