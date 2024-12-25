#include <double-ll.h>
#include <product.h>
// include shopping cart
// include user


class Order {
    private:
        string id;
        // user person;
        Double_LL<product> checkoutItems;

    public:
        Order(string, Double_LL<product>);
        Double_LL<product> getItems() const;
        // get user
};