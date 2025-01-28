#include "shopping-cart.h"


class Order {
    private:
        string buyer;
        ShoppingCart* checkout;

    public:
        Order(string, ShoppingCart*);
        string getBuyer() const;
        ShoppingCart* getCart() const;
};