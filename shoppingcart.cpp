#include "shoppingcart.h"
shoppingcart::shoppingcart(){}    
void shoppingcart::addItem(const product &item, int quantity)
{
     if(cartItems.search(item)){
        updateQuantity(item,quantity);
        return;
     }
     product newitem = item;
    newitem.setPrice(item.getPrice() * quantity);
    cartItems.AddtoTail(newitem);
    undoStack.push(newitem);
}

void shoppingcart::removeItem(const product &item)
{
    if(cartItems.search(item)==false) return;
    product removeditem=item;
    undoStack.push(removeditem);
    cartItems.RemoveItem(item);
}
void shoppingcart::updateQuantity(const product& item, int newQuantity){
    if(cartItems.search(item)==false) return;
    for (int i=0;i<newQuantity;i++){
        product currentItem = item;
        undoStack.push(currentItem);
    }
}
