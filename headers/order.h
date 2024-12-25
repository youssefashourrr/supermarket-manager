#include <double-ll.h>
#include <product.h>
// include shopping cart
// include user


class Order {
    private:
        string id;
        string name;
        DoubleLL<Product> checkoutItems;

    public:
        Order(string, DoubleLL<Product>);
        DoubleLL<Product> getItems() const;
        // get user
};