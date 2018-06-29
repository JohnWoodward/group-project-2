#pragma once
class Item {
	// Sets default value of attributes
	string name = "";
	double price = 0;

public:

	// Functions setting name and price
	void setName(string namePassed);
	void setPrice(double pricePassed);

	// Functions getting name and price
	void getName();
	void getPrice();

private:

	// Class attributes
	string name;
	double price;
};