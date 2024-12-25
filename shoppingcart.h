#include <iostream>
#include <stack>
#include "product.h"
#include "Double_LL.h"

using namespace std;

class ShoppingCart {
private:
    Double_LL<product> cartItems;       // Doubly linked list to store cart items
    stack<pair<string, int>> undoStack; // Stack to handle undo actions (stores product name and action type)
    enum ActionType { ADD = 1, REMOVE = 2, UPDATE = 3 }; // Define action types for undo
public:
    ShoppingCart();
    void addItem(const product& item, int quantity = 1);
    void removeItem(const string& itemName);
    void updateQuantity(const string& itemName, int newQuantity);
    void undoLastAction();
    void cartSummary(float taxRate = 0.0) const;
    bool isEmpty() const;
};
