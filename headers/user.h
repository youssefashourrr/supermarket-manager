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
        void savePurchases();
        string getEmail() const;
        vector<string> frequentlyPurchased() const;
};