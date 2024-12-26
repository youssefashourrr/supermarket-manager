#include "shoppingcart.h"
shoppingcart::shoppingcart(){}    
void shoppingcart::addItem(const Product &item, int quantity)
{
     if(cartItems.search(item)){
        updateQuantity(item,true);
        return;
     }
    cartItems.AddtoTail(item);
}
void shoppingcart::removeItem(const Product &item)
{
    if(cartItems.search(item)==false) return;
    updateQuantity(item,false);
}
void shoppingcart::updateQuantity(const Product& item, bool flag){
    if(cartItems.search(item)==false) return;
    if(flag) cartItems.incrementQuantity(item);
    else cartItems.decrementQuantity(item);
}
DoubleLL<Product> shoppingcart::getCart()
{
    return cartItems;
}
