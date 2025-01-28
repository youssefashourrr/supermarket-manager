#include "../include/user.h"


User::User()
{
    this->purchaseHistory = {};
}

bool User::manageRegisterOrLogin(string email, string password)
{
    ifstream file("../data/user_profiles.json", ios::in | ios::ate);
    json profilesJson;

    if (!file.is_open()) {
        cout << "Failed to open profiles file. Initializing empty profiles." << endl;
        profilesJson = json::array();
    } 
    else if (file.tellg() == 0) {
        cout << "Profiles file is completely empty." << endl;
        profilesJson = json::array();
    } 
    else {
        file.seekg(0);
        try {
            file >> profilesJson;
        } 
        catch (const std::exception& e) {
            cout << "Error parsing JSON: " << e.what() << endl;
            file.close();
            return false;
        }
    }
    file.close();

    for (const auto& profileJson : profilesJson) {
        try {
            if (profileJson.at("email") == email)
            {
                if (profileJson.at("password") != password) {
                    cout << "Password does not match for email" << endl;
                    return false;
                }
                this->email = email;
                this->password = password;
                if (profileJson.contains("purchaseHistory") && profileJson.at("purchaseHistory").is_object()) {
                    for (const auto& [productName, quantity] : profileJson.at("purchaseHistory").items()) {
                        this->purchaseHistory[productName] = quantity;
                    }
                }

                cout << "Login successful for email: " << email << endl;
                return true;
            }
        } 
        catch (const std::exception& e) {
            cout << "Error processing profile: " << e.what() << endl;
        }
    }
    this->email = email;
    this->password = password;
    json newProfile = {
        {"email", email},
        {"password", password},
        {"purchaseHistory", json::object()}
    };
    profilesJson.push_back(newProfile);

    ofstream outFile("../data/user_profiles.json", ios::out | ios::trunc);
    if (!outFile.is_open()) {
        cout << "Failed to write to profiles file." << endl;
        return false;
    }
    outFile << profilesJson.dump(4);
    outFile.close();

    cout << "New user registered with email: " << email << endl;
    return true;
}

void User::savePurchases() {
    ifstream inFile("../data/user_profiles.json", ios::in);
    if (!inFile.is_open()) {
        cout << "Failed to open the profiles file." << endl;
        return;
    }

    json profilesJson;
    try {
        inFile >> profilesJson;
        inFile.close();
    } catch (const std::exception& e) {
        cout << "Error parsing JSON: " << e.what() << endl;
        inFile.close();
        return;
    }

    for (auto& profileJson : profilesJson) {
        if (profileJson.contains("email") && profileJson["email"] == email) {
            json purchaseHistoryJson;
            for (const auto& entry : purchaseHistory) {
                purchaseHistoryJson[entry.first] = entry.second;
            }
            profileJson["purchaseHistory"] = purchaseHistoryJson;
        }
    }
}

string User::getEmail() const {
    return this->email;
}

vector<string> User::frequentlyPurchased() const {
    int maxValue = -1;
    vector<string> topProducts;

    for (const auto& p : this->purchaseHistory) {
        if (p.second > maxValue) {
            maxValue = p.second;
            topProducts = {p.first};
        }
        else if (p.second == maxValue) {
            topProducts.push_back(p.first);
        }
    }
    return topProducts;
}

unordered_map<string, int>* User::getHistory() {
    return &(this->purchaseHistory);
}