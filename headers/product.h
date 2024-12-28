#include "../json.hpp" 
#include <iostream>
using namespace std;
using json = nlohmann::json;


class Product
{
    private:
		string name;
		float price;
		string code;

	public:
		Product();
		Product(string);
		Product(string,float,string);
		Product(const json& productJson);

		string getName() const;
		float getPrice() const;
		string getCode() const;

		void setName(string);
		void setPrice(float);
		void setCode(string);

		Product& getProduct();
		json toJson();
		friend ostream& operator<<(ostream& os, const Product&);

		bool operator<(const Product& other) const;
		bool operator>(const Product& other) const;
		bool operator<=(const Product& other) const;
		bool operator>=(const Product& other) const;
		bool operator==(const Product& other) const;
		bool operator!=(const Product& other) const;
};