#include "../ds-templates/double-ll.h"
#include "product.h"
// include shopping cart (ashour)
// include user (ashour)

class Order
{
    private:
        string id;
        DoubleLL<Product>* checkoutItems;

    public:
        Order(string, DoubleLL<Product>*);
        string getId();
        DoubleLL<Product>* getItems();
        // get user (ashour)
};