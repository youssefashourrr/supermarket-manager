#include "headers/store.h"

Store::Store()
{
    this->categories = new Categories;
    this->inventory= new Inventory;
    this->shoppingCart= new ShoppingCart;
    this->orders=new Orders;
    this->user=new User;
}

Categories* Store::getCategories() const {
    return this->categories;
}

Inventory* Store::getInventory() const {
    return this->inventory;
}

ShoppingCart* Store::getShoppingCart() const
{
    return this->shoppingCart;
}

Orders* Store::getOrders() const {
    return this->orders;
}

User* Store::getUser() const {
    return this->user;
}

bool Store::addCategory(const string& name)
{
    if (this->categories->isInCategories(name)) return false;
    Category* category = new Category(name);
    this->categories->addCategory(category);
    return true;
}

bool Store::removeCategory(const string& name) {
    if (!this->categories->isInCategories(name)) return false;

    string identifier = name.substr(0, 3);

    for (auto& i : identifier) i = toupper(i);
    auto stock = this->inventory->getStock();
    for (auto it = stock->begin(); it != stock->end();)
    {
        if (it->first.getCode().substr(0, 3) == identifier)
        {
            it = inventory->removeProduct(it->first); // Safely remove and advance the iterator
        }
        else
        {
            ++it; // Advance the iterator if no removal
        }
    }
    cout << name<< endl;
    return categories->removeCategory(name);
}

void Store::addProduct(const string& cName, const string& pName, float price,int quantity) {
    auto it = categories->findCategory(cName);
    string id = (*it)->addProduct(pName, price);
    this->categories->saveToFile();
    this->inventory->addProduct(Product(pName, price, id),quantity);
}

bool Store::removeProduct(const string& name)
{
    string categoryStart;
    for (const auto& p : *(this->inventory->getStock()))
        {
            if (p.first.getName() == name)
                {
                categoryStart = p.first.getCode();
                this->inventory->removeProduct(p.first);
                break;
                }
        }
    cout<<"Saved In Inventory";
    for (const auto& c : *(this->categories->getGroups()))
        {
            cout<<c->getName()<<endl;
            string cname = c->getName().substr(0, 3);
            for (auto& l:cname) l=toupper(l);
            if (cname == categoryStart.substr(0,3))
            {
                c->removeProduct(name);
                this->categories->saveToFile();
                return true;
            }
    }
    return false;
}

void Store::addToCart(const Product& added) {
    this->shoppingCart->addItem(added);
}

void Store::removeFromCart(const Product& removed)
{
    this->shoppingCart->removeItem(removed);
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
    Node<Product>* ptr = this->shoppingCart->getItems()->getHead();
    while (ptr != nullptr) {
        (*this->user->getHistory())[ptr->data.getName()] = ptr->quantity;
        ptr = ptr->next;
    }
    this->user->savePurchases();
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

bool Store::checkOrderValidity() {
    Node<Product>* itemPtr = this->orders->getPending()->front()->getCart()->getItems()->getHead();
    map<Product, int>* stockPtr = this->getInventory()->getStock();
    map<string,bool>* alertPtr = this->getInventory()->getAlert();
    while (itemPtr != nullptr)
    {
        int q = itemPtr->quantity;
        if ((*stockPtr)[itemPtr->data] < q || (*alertPtr)[itemPtr->data.getName()]) return false;
        this->inventory->decrementQuantity(itemPtr->data, q);
        itemPtr = itemPtr->next;
    }
    this->orders->processOrder();
    return true;

}