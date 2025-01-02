#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include "../json.hpp"

using namespace std;
using json = nlohmann::json;


class User {
    private:
        string email;
        string password;
        unordered_map<string, int> purchaseHistory;
        
    public:
        User();
        bool manageRegisterOrLogin(string, string);
        unordered_map<string, int>* getHistory();
        void savePurchases();
        string getEmail() const;
        vector<string> frequentlyPurchased() const;
};