#include "headers/store.h"


Categories* Store::getCategories() const {
    return this->categories;
}

Inventory* Store::getInventory() const {
    return this->inventory;
}

Orders* Store::getOrders() const {
    return this->orders;
}

User* Store::getUser() const {
    return this->user;
}

bool Store::addCategory(const string& name) {
    if (this->categories->isInCategories(name)) return false;

    Category* category = new Category(name);
    this->categories->addCategory(category);
    return true;
}

bool Store::removeCategory(const string& name) {
    if (!this->categories->isInCategories(name)) return false;

    string identifier = name.substr(0, 3);
    auto stock = this->inventory->getStock();
    for (auto kv : *stock) {
        if (kv.first.getCode().substr(0,3) == identifier) inventory->removeProduct(kv.first);
    }
    return categories->removeCategory(name);
}

void Store::addProduct(const string& cName, const string& pName, float price) {
    auto it = categories->findCategory(cName);
    string id = (*it)->addProduct(pName, price);
    this->inventory->addProduct((pName, price, id));
}

bool Store::removeProduct(const string& name) {
    string categoryStart;
    for (const auto& p : *(this->inventory->getStock())) {
        if (p.first.getName() == name) {
            categoryStart = p.first.getCode();
            this->inventory->removeProduct((p.first));
        }
    }
    for (const auto& c : *(this->categories->getGroups())) {
        if (c->getName().substr(0, 3) == categoryStart) {
            c->removeProduct(name);
            return true;
        }
    }
    return false;
}

void Store::addToCart(const Product& added) {
    this->shoppingCart->addItem(added);
}

vector<Order*> Store::getPendingQueue() {
    vector<Order*> pendingView;
    queue<Order*> qCopy = *(this->orders->getPending());
    while (!qCopy.empty()) {
        pendingView.push_back(qCopy.front());
        qCopy.pop();
    }
    return pendingView;
}

void Store::checkout() {
    Order* order = new Order(this->user->getEmail(), this->shoppingCart->getObject());
    this->orders->addOrder(order);
}

unordered_map<Order*, bool> Store::getUserHistory() const {
    unordered_map<Order*, bool> userHistory;
    for (const auto& o : *(this->orders->getProcessed())) {
        if (o->getBuyer() == this->user->getEmail()) {
            userHistory.insert(make_pair(o, true));
        }
    }
    queue<Order*> qCopy = *(this->orders->getPending());
    while (!qCopy.empty()) {
        if (qCopy.front()->getBuyer() == this->user->getEmail()) {
            userHistory.insert(make_pair(qCopy.front(), false));
        }
        qCopy.pop();
    }
    return userHistory;
}

bool Store::enterStore(const string& email, const string& password) {
    regex emailPattern(R"((\w+)(\.\w+)*@(\w+\.)+\w{2,3})");
    regex passwordPattern(R"((?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[\W_]).{8,})");

    if (!regex_match(email, emailPattern)) return false;
    if (!regex_match(password, passwordPattern)) return false;

    return this->user->manageRegisterOrLogin(email, password);
}
