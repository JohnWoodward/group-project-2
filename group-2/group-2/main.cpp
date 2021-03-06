// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Item.h"
#include "Cart.h"


using namespace std;

ostream & operator<<(ostream & os, Cart & cart)
{
	double totalPrice = 0;

	os << endl;

	os << "Items in cart:" << endl;
	for (int i = 0; i < cart.itemsInCart; i++) {
		os << cart.quantityItem[i] << " $" << cart.items[i].getPrice() << " " << cart.items[i].getName() << endl;
		totalPrice += cart.quantityItem[i] * cart.items[i].getPrice();
	}
	os << "There are " << cart.itemsInCart << " items in the cart" << endl;
	os << "The total price of the cart is $" << totalPrice << endl << endl;
	return os;
}


int main()
{
	//Initial cart content
	int const ITEMLIST_SIZE = 10;
	int cartSize = 0, i = 0;

	Item itemList[ITEMLIST_SIZE];
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
	cout << cart;

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
	cout << cart;

	//Eliminating item from cart
	Item keyItem;
	keyItem.setName(itemNames[2]);
	keyItem.setPrice(itemPrices[2]);
	cout << "Removing item " << keyItem.getName() << endl;
	cart.removeItem(keyItem);

	cout << "Printing cart again" << endl;
	cout << cart;

	//Increasing price of one item in the cart
	Item changeItem;
	changeItem.setName(itemNames[3]);
	changeItem.setPrice(itemPrices[3]);
	double priceIncrease = 2.99;
	cout << "Increasing item " << changeItem.getName() << " old price: " << itemPrices[3] << " price increase:" << priceIncrease << endl;
	cart.increasePrice(changeItem, priceIncrease);
	cout << "Printing cart with changed price" << endl;
	cout << cart;

	//Decreasing price of one item in the cart
	changeItem.setName(itemNames[3]);
	changeItem.setPrice(itemPrices[3]);
	double priceDecrease = 1.99;
	cout << "Decreasing item " << changeItem.getName() << " old price: " << itemPrices[3] << " price decrease:" << priceDecrease << endl;
	cart.decreasePrice(changeItem, priceDecrease);
	cout << "Printing cart with changed price" << endl;
	cout << cart;

	//Creating copy of cart using copy constructor
	cout << "Creating a new cart using copy constructor" << endl;
	Cart newCart(cart);
	cout << "Printing NEW cart" << endl;
	cout << newCart;
	newItem.setName(itemNames[7]);
	newItem.setPrice(itemPrices[7]);
	cout << "Adding new item " << newItem.getName() << endl;
	newCart.addItem(newItem, itemQuantities[7]);
	cout << "Printing NEW cart again" << endl;
	cout << newCart;

	cout << "Printing OLD cart to check the difference" << endl;
	cout << cart;

	system("pause");


	return 0;
}