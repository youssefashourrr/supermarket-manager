#include <regex>
#include "categories.h"
#include "inventory.h"
#include "orders.h"
#include "user.h"


class Store {
    private:
        Categories* categories;
        Inventory* inventory;
        ShoppingCart* shoppingCart;
        Orders* orders;
        User* user;
    
    public:
        Categories* getCategories() const;
        Inventory* getInventory() const;
        Orders* getOrders() const;
        User* getUser() const;

        bool addCategory(const string&);
        bool removeCategory(const string&);

        void addProduct(const string&, const string&, float);
        bool removeProduct(const string&);

        void addToCart(const Product&);

        vector<Order*> getPendingQueue();
        void checkout();
        unordered_map<Order*, bool> getUserHistory() const;
        bool enterStore(const string&, const string&);
};