#pragma once
#include <string>

using namespace std;

class Item {
	// Sets default value of attributes




public:
	//constructors 
	Item();
	Item operator+(Item rhs);
	Item operator-(Item rhs);





	// Functions setting name and price
	void setName(string namePassed);
	void setPrice(double pricePassed);
	void currentItem();

	// Functions getting name and price
	string getName();
	double getPrice();

private:



	// Class attributes
	string name;
	double price;



};