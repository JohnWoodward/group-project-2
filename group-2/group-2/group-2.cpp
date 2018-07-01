// group-2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include <string>

using namespace std;


class Item {
	// Sets default value of attributes

	
	

public:
	//constructors 
	Item();

	// Functions setting name and price
	void setName(string namePassed);
	void setPrice(double pricePassed);

	// Functions getting name and price
	string getName();
	double getPrice();

private:

	// Class attributes
	string name;
	double price;


};

Item::Item() {
	string name = "";
	double price = 0;
}


// Function to set the name of the item
void Item::setName(string namePassed) {
	name = namePassed;

}

// Function to set the price of the item
void Item::setPrice(double pricePassed) {
	price = pricePassed;
}

// Function to get name of item
string Item::getName() {
	return name;
}

// Function to get price of item
double Item::getPrice() {
	return price;
}


class Cart {


public:
	Cart();
	Cart(int cartSize);
	void increasePrice(Item changeItem, double priceIncrease);
	void decreasePrice(Item item, double amountDecreased);
	void removeItem(Item item);
	void addItem(Item newItem, int quantity);
	void printCart();
	


private:

	int maxItem;
	int itemsInCart;
	int* quantityItem = new int[maxItem];
	Item* items = new Item[maxItem];
	void doubleItemsArray();
	void halfItemsArray();
	

};

Cart::Cart()
{
	int maxItem = 50;
	int itemsInCart = 0;
	Item* currentItem = new Item();
	int* quantityItem = NULL;
	Item* items = NULL;
}

Cart::Cart(int cartSize) {
	int const maxItem = cartSize;
	int itemsInCart = 0;
	int* quantityItem = new int[maxItem];
	Item* items = new Item[maxItem];
}


// Function to increase price of an item in the cart

void Cart::increasePrice(Item changeItem, double priceIncrease) {
/*
	for (int i = 0; i < maxItem; i++) {
		if (*items[i] == changeItem) {

		}
	}
	*/
	// TODO build function that finds item and increases price using overloaded + operator
	// also inform user if item is not in cart
}


// Function to decrease price of an item in the cart
void Cart::decreasePrice(Item items, double amountDecreased) {

	// TODO build function that finds item and decreases price using overloaded + operator
	// also if item is not in the cart inform the user
	// also if resulting price is negative inform user and do not change price   
}

// Function to remove item from cart
void Cart::removeItem(Item items) {

	// TODO build function that removes an item from cart and shifts elements in cart to the left to fill empty space
}

// Function to add item to cart
void Cart::addItem(Item newItem, int quantity) {
	
	Item* tempPointer = NULL;
	int* qntPointer = NULL;

	if (maxItem == itemsInCart)
	{
		doubleItemsArray();
	}
	tempPointer = &newItem;
	qntPointer = &quantity;

	items[itemsInCart] = *tempPointer;
	quantityItem[itemsInCart] = *qntPointer;
	

	
	// TODO build function that adds an item and quantity of item to the cart
}

// Function to print the cart
void Cart::printCart() {

	



	// TODO build function that will print out all contents of cart along with their qty and price
	// also it needs to print out total number of items and total cart price
}
void Cart::doubleItemsArray(){
	

	int tempSize = maxItem;
	maxItem = maxItem * 2;
	Item *tempItemArray = new Item[maxItem];
	
	for (int k = 0; k < tempSize; k++)
	{
		tempItemArray[k] = items[k];
	}
	items = tempItemArray;

	int tempQuantity = maxItem;
	maxItem = maxItem * 2;
	int *tempQntArray = new int[maxItem];
	int k;
	for (k = 0; k < tempSize; k++)
	{
		tempQntArray[k] = quantityItem[k];
	}
	items = tempItemArray;
}

void Cart::halfItemsArray() {


	int tempSize = maxItem;
	maxItem = maxItem / 2;
	Item *tmp_array = new Item[maxItem];
	
	for (int k = 0; k < tempSize; k++)
	{
		tmp_array[k] = items[k];

	}
	items = tmp_array;
}



int main()
{

	//Initial cart content
	const int ITEMLIST_SIZE = 10; // this needs to be constant
	int cartSize = 0;
	int i = 0;

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
	for (i = 0; i < cartSize; i++) {
		cart.addItem(itemList[i], itemQuantities[i]); 
	}

	cout << "Printing cart " << endl;
	cart.printCart();

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
	cart.printCart();

	//Eliminating item from cart
	Item keyItem;
	keyItem.setName(itemNames[2]);
	keyItem.setPrice(itemPrices[2]);
	cout << "Removing item " << keyItem.getName() << endl;
	cart.removeItem(keyItem);

	cout << "Printing cart again" << endl;
	cart.printCart();

	//Increasing price of one item in the cart
	Item changeItem;
	changeItem.setName(itemNames[3]);
	changeItem.setPrice(itemPrices[3]);
	double priceIncrease = 2.99;
	cout << "Increasing item " << changeItem.getName() << " old price: " << itemPrices[3] << " price increase:" << priceIncrease << endl;
	cart.increasePrice(changeItem, priceIncrease);
	cout << "Printing cart with changed price" << endl;
	cart.printCart();

	//Decreasing price of one item in the cart
	changeItem.setName(itemNames[3]);
	changeItem.setPrice(itemPrices[3]);
	double priceDecrease = 1.99;
	cout << "Decreasing item " << changeItem.getName() << " old price: " << itemPrices[3] << " price decrease:" << priceDecrease << endl;
	cart.decreasePrice(changeItem, priceDecrease);
	cout << "Printing cart with changed price" << endl;
	cart.printCart();

	//Creating copy of cart using copy constructor
	cout << "Creating a new cart using copy constructor" << endl;
	Cart newCart(cart);
	cout << "Printing NEW cart" << endl;
	newCart.printCart();
	newItem.setName(itemNames[7]);
	newItem.setPrice(itemPrices[7]);
	cout << "Adding new item " << newItem.getName() << endl;
	newCart.addItem(newItem, itemQuantities[7]);
	cout << "Printing NEW cart again" << endl;
	newCart.printCart();

	cout << "Printing OLD cart to check the difference" << endl;
	cart.printCart();

	system("pause");

	return 0;
}


