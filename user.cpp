#include "user.h"


User::User() {
    this->purchaseHistory = {};
}

bool User::manageRegisterOrLogin(string email, string password) {
    ifstream file("data/user_profiles.json", ios::in | ios::ate);
    json profilesJson;

    if (!file.is_open()) {
        cout << "Failed to open profiles file. Initializing empty profiles." << endl;
        profilesJson = json::array(); // Initialize an empty JSON array if file cannot be read
    } 
    else if (file.tellg() == 0) {
        cout << "Profiles file is completely empty." << endl;
        profilesJson = json::array(); // Initialize an empty JSON array for an empty file
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

    // Check if the email exists in the profiles
    for (const auto& profileJson : profilesJson) {
        try {
            if (profileJson.at("email") == email) {
                // Check if the password matches
                if (profileJson.at("password") != password) {
                    cout << "Password does not match for email" << endl;
                    return false;
                }

                this->email = email;
                this->password = password;

                // Copy purchase history
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

    // If email not found, add new profile
    json newProfile = {
        {"email", email},
        {"password", password},
        {"purchaseHistory", json::object()} // Empty JSON object for future purchases
    };
    profilesJson.push_back(newProfile);

    // Save the updated profiles back to the file
    ofstream outFile("data/user_profiles.json", ios::out | ios::trunc);
    if (!outFile.is_open()) {
        cout << "Failed to write to profiles file." << endl;
        return false;
    }
    outFile << profilesJson.dump(4); // Pretty-print with indentation
    outFile.close();

    cout << "New user registered with email: " << email << endl;
    return true;
}

void User::savePurchases() {
    // Open the file for reading
    ifstream inFile("data/user_profiles.json", ios::in);
    if (!inFile.is_open()) {
        cout << "Failed to open the profiles file." << endl;
        return;
    }

    json profilesJson;
    try {
        inFile >> profilesJson;  // Read the existing profiles JSON
        inFile.close();
    } catch (const std::exception& e) {
        cout << "Error parsing JSON: " << e.what() << endl;
        inFile.close();
        return;
    }

    // Loop through the profiles to find the user by email
    for (auto& profileJson : profilesJson) {
        if (profileJson.contains("email") && profileJson["email"] == email) {
            // Convert purchaseHistory to JSON format
            json purchaseHistoryJson;
            for (const auto& entry : purchaseHistory) {
                purchaseHistoryJson[entry.first] = entry.second;
            }
            // Update the purchase history of the found user
            profileJson["purchaseHistory"] = purchaseHistoryJson;  // Update purchase history
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
}