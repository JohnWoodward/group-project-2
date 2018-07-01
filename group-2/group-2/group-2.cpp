// group-2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include <string>

using namespace std;


class Item {
	string name;
	double price; // Sets default value of attributes
	

public:
	Item(); //takes no parameters

	// Functions setting name and price
	void setName(string namePassed);
	void setPrice(double pricePassed);

	// Functions getting name and price
	string getName() const;
	double getPrice() const;

private:

	// Class attributes
	string name;
	double price;
};


Item::Item()
{
	name = "";
	price = 0.0;
}

// Function to set the name of the item
void Item::setName(string namePassed) {
	if (!(namePassed == "")) {
		name = namePassed;

	}
	else{
	 cout << "Not a valid name." << endl;

	}
	// TODO build function that sets the name of the item
	// if nothing is enterd inform user the opperation cannot take place

}

// Function to set the price of the item
void Item::setPrice(double pricePassed) {
	
	if (!(price < 0)) {
		price = pricePassed;
		//TODO build function that sets price of item
		// if price is <= 0 inform user that opperation cannot take place
	}
	else {
		cout << "Price needs to be greater than zero." << endl;
	}
}


// Function to get name of item
string Item::getName() const{
	return name;
}

// Function to get price of item
double Item::getPrice()const {
	return price;
	// FIXME add parameters to function
	// TODO build function that gets current item price

}


class Cart {

	// Sets default values of attributes
	/*int maxSize = 0;
	int quantity = 0;
	int numItems = 0;
	int* cart = NULL;*/

public:
	Cart(int size);
	~Cart();
	int getNumItems();
	void increasePrice(Item changeItem, double priceIncrease);
	void decreasePrice(Item item, double amountDecreased);
	void removeItem(Item item);
	void addItem(Item newItem, int quantity);
	friend ostream& operator << (ostream& os, Cart& cart);

private:


	Item* items;
	int maxSize;
	int* quantityItem;
	//double totalPrice;
	int numItems;

};

Cart::Cart (int size)
{
	maxSize = size;
	// use the size to create dynamic array for items
	Item*items = new Item[size];
	Item*quantity = new Item[size];
	// use the size to create dynamic array for quantityItem

}

// This is a destructor. Because your class dynamically allocates two arays, you must delete them when the object goes out of scope
Cart::~Cart()
{
	// syntax for deleting an array
	delete[] items;
	delete[] quantityItem;
}

int Cart::getNumItems()
{
	return numItems;
}


// Function to increase price of an item in the cart
void Cart::increasePrice(Item changeItem, double priceIncrease) { //should be double, not int
	// FIXME add parameters to function
	// TODO build function that finds item and increases price using overloaded + operator
	// also inform user if item is not in cart
}

// Function to decrease price of an item in the cart
void Cart::decreasePrice(Item item, double amountDecreased) {
	// FIXME add parameters to function
	// TODO build function that finds item and decreases price using overloaded + operator
	// also if item is not in the cart inform the user
	// also if resulting price is negative inform user and do not change price   
}

// Function to remove item from cart
void Cart::removeItem(Item item) {
	// TODO build function that removes an item from cart and shifts elements in cart to the left to fill empty space
	
	//locate index of item
	int index = 0;
	for (int i = 0; i < numItems; i++) {
		if (item.getName() == items[i].getName()) {
			index = i;
		}
	}
	Item*tempArr = new Item[maxSize];
	int *tempQuantity = new int[maxSize];

	for (int i; i < numItems; i++) {
		if (i < index) {
			tempArr[i] = items[i];
			tempQuantity[i] = quantityItem[i];

		}
		else if (i > index) {
			tempArr[i - 1] = items[i];
			tempQuantity[i-1] = quantityItem[i];

		}
	
	}
	delete[]items;
	items = tempArr;
	tempArr = NULL;
	numItems--;
	delete[]quantityItem;
	quantityItem = tempQuantity;
	tempQuantity = NULL;
	
}

// Function to add item to cart
void Cart::addItem(Item newItem, int quantity) {

	if (numItems < maxSize) {
		items[numItems] = newItem;
		quantityItem[numItems] = quantity;
		numItems++;
	}
	else {
		cout << "Cart is full. Can not add anymore items." << endl;
	}
}



int main()
{

	//Initial cart content
	const int ITEMLIST_SIZE = 10; // this needs to be constant
	int cartSize = 0, i = 0;

	Item itemList[ITEMLIST_SIZE]; // requires said constant size ^^
	string itemNames[] = { "Notebook", "Bat", "Ball", "Pencil", "Ruler", "Pen", "Box","Stapler", "Folder", "Glue" };
	double itemPrices[] = { 1.00, 4.00, 3.50, 0.99, 1.99, 0.75, 3.00, 6.49, 2.00, 0.69 };
	for (i = 0; i<ITEMLIST_SIZE; i++) {
		Item item;
		item.setName(itemNames[i]);
		item.setPrice(itemPrices[i]);

		itemList[i] = item;
	}

	int itemQuantities[] = { 5, 1, 1, 12, 2, 6, 1, 1, 5, 2 };

	//Creating a cart object of size 5 and filling it with initial content,
	//first 5 items from list
	cartSize = 5;
	cout << "Creating a cart of size: " << cartSize << endl;
	Cart cart(cartSize);
	cout << "Adding " << cartSize << " items to the cart" << endl;
	for (i = 0; i<cartSize; i++) {
		cart.addItem(itemList[i], itemQuantities[i]);
	}

	cout << "Printing cart " << endl;
	cout << cart << endl;
	//cart.printCart();

	//Increasing quantity of one item already in cart
	Item newItem;
	newItem.setName(itemNames[2]);
	newItem.setPrice(itemPrices[2]);
	cout << "Adding one item already in the cart " << newItem.getName() << ", with additional quantity: " << itemQuantities[2] << endl;
	cart.addItem(newItem, itemQuantities[2]);

	//Adding a new item to the cart. NOTE: this operation should fail,
	//because the cart is already full
	newItem.setName(itemNames[5]);
	newItem.setPrice(itemPrices[5]);
	cout << "Adding new item " << newItem.getName() << endl;
	cart.addItem(newItem, itemQuantities[5]);

	cout << "Printing cart again" << endl;
	//cart.printCart();
	cout << cart << endl;


	//Eliminating item from cart
	Item keyItem;
	keyItem.setName(itemNames[2]);
	keyItem.setPrice(itemPrices[2]);
	cout << "Removing item " << keyItem.getName() << endl;
	cart.removeItem(keyItem);

	cout << "Printing cart again" << endl;
	//cart.printCart();
	cout << cart << endl;


	//Increasing price of one item in the cart
	Item changeItem;
	changeItem.setName(itemNames[3]);
	changeItem.setPrice(itemPrices[3]);
	double priceIncrease = 2.99;
	cout << "Increasing item " << changeItem.getName() << " old price: " << itemPrices[3] << " price increase:" << priceIncrease << endl;
	cart.increasePrice(changeItem, priceIncrease);
	cout << "Printing cart with changed price" << endl;
	//cart.printCart();
	cout << cart << endl;


	//Decreasing price of one item in the cart
	changeItem.setName(itemNames[3]);
	changeItem.setPrice(itemPrices[3]);
	double priceDecrease = 1.99;
	cout << "Decreasing item " << changeItem.getName() << " old price: " << itemPrices[3] << " price decrease:" << priceDecrease << endl;
	cart.decreasePrice(changeItem, priceDecrease);
	cout << "Printing cart with changed price" << endl;
	//cart.printCart();
	cout << cart << endl;


	//Creating copy of cart using copy constructor
	cout << "Creating a new cart using copy constructor" << endl;
	Cart newCart(cart);
	cout << "Printing NEW cart" << endl;
	//newCart.printCart();
	cout << newCart << endl;

	newItem.setName(itemNames[7]);
	newItem.setPrice(itemPrices[7]);
	cout << "Adding new item " << newItem.getName() << endl;
	newCart.addItem(newItem, itemQuantities[7]);
	cout << "Printing NEW cart again" << endl;
	//newCart.printCart();
	cout << newCart << endl;

	cout << "Printing OLD cart to check the difference" << endl;
	//cart.printCart();
	cout << cart << endl;

	return 0;
}


// remember to create a readme.txt file just to state that we've done the bonus
ostream & operator<<(ostream & os, Cart & cart)
{
	os << "Items in cart:" << endl;
	for (int i; i < cart.getNumItems(); i++) {
		os << cart.items[i].getName() << " ";
	}
	os << endl;
	return os;
}
