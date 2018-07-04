#include "stdafx.h"
#include "Cart.h"
#include <iostream>

Cart::Cart(int cartSize) {
	maxItem = cartSize;
	itemsInCart = 0;

	quantityItem = new int[maxItem];
	for (int i = 0; i < maxItem; i++) {
		quantityItem[i] = 0; // Fill with zeroes
	}

	items = new Item[maxItem]();
	Item* itemPtr;
	Item item;
	item.setName("ddd");
	item.setPrice(333);
	itemPtr = &item;
	items = new Item[maxItem]();
	for (int i = 0; i < maxItem; i++) {
		items[i] = *itemPtr; // Intialize memory
	}
}

Cart::~Cart() {
	// deletes array when it is no longer needed
	delete[] items;
	delete[] quantityItem;
}


// Function to increase price of an item in the cart
void Cart::increasePrice(Item changeItem, double priceIncrease) {

	for (int i = 0; i < itemsInCart; i++) {
		if (items[i].getName() == changeItem.getName()) {
			items[i].setPrice(priceIncrease + items[i].getPrice());
			return;
		}
	}
	//throw exception if item not found
}

Cart::Cart(const Cart & cart) {
	itemsInCart = cart.itemsInCart;
	maxItem = cart.maxItem;

	quantityItem = new int[cart.maxItem];
	for (int i = 0; i < cart.itemsInCart; i++) {
		quantityItem[i] = cart.quantityItem[i]; 
	}

	items = new Item[cart.maxItem]();
	for (int j = 0; j < cart.itemsInCart; j++) {
		items[j] = cart.items[j];
	}
}


// Function to decrease price of an item in the cart
void Cart::decreasePrice(Item changeItem, double amountDecreased) {

	for (int i = 0; i < itemsInCart; i++) {

		if (items[i].getName() == changeItem.getName()) {
			items[i].setPrice(items[i].getPrice() - amountDecreased);
			return;
		}
	}
	//throw exception if item not found
}


// Function to remove item from cart
void Cart::removeItem(Item itemToRemove) {

	//locate index of item
	int index = 0;
	for (int i = 0; i < itemsInCart; i++) {
		if (items[i].getName() == itemToRemove.getName()) {
			index = i;
		}
	}
	Item*tempArr = new Item[maxItem];
	int *tempQuantity = new int[maxItem];

	for (int i = 0; i < itemsInCart; i++) {
		if (i < index) {
			tempArr[i] = items[i];
			tempQuantity[i] = quantityItem[i];

		}
		else if (i > index) {
			tempArr[i - 1] = items[i];
			tempQuantity[i - 1] = quantityItem[i];

		}

	}
	delete[]items;
	items = tempArr;
	tempArr = NULL;
	itemsInCart--;
	delete[]quantityItem;
	quantityItem = tempQuantity;
	tempQuantity = NULL;

	
}


// Function to add item to cart
void Cart::addItem(Item newItem, int quantity) {

	bool cartBool = false;

	/*
	if (maxItem == itemsInCart)
	{
	doubleItemsArray();
	}
	*/

	if (itemsInCart > 0) {

		for (int i = 0; i < itemsInCart; i++) {
			if (items[i].getName() == newItem.getName()) {
				quantityItem[i] += quantity;
				cartBool = true;
			}
		}

		// Work around for not doubling cart
		/* Ugly bool
		if (cartBool == false && itemsInCart == maxItem) {
			cout << "unable to add item, cart is to full!" << endl;
		}
		else if (cartBool == false) {
			quantityItem[itemsInCart] = quantity;
			items[itemsInCart] = newItem;
			itemsInCart++;
		}
		*/
		// Pretty bool
		if (!cartBool)
		{
			if (itemsInCart == maxItem)
			{
				cout << "unable to add item, cart is to full!" << endl;
			}
			else
			{
				quantityItem[itemsInCart] = quantity;
				items[itemsInCart] = newItem;
				itemsInCart++;
			}
		}
	}
	else {
		quantityItem[itemsInCart] = quantity;
		items[itemsInCart] = newItem;
		itemsInCart++;
	}

}

// Function to print the cart ** not needed due to overloading << operator
/*
void Cart::printCart() {

	double totalPrice = 0;
	for (int i = 0; i < itemsInCart; i++) {
		cout << quantityItem[i];
		cout << " ";
		cout << items[i].getName();
		cout << " ";
		cout << items[i].getPrice() * quantityItem[i];
		cout << " ";
		cout << endl;
		totalPrice += items[i].getPrice() * quantityItem[i];

	}
	cout << "The total number of items in the cart is: " << itemsInCart << endl;
	cout << "The total price of the cart is: " << totalPrice << endl << endl;
	}
*/


// Functions to double and half array ** not needed since using an error message when cart is full
/*
void Cart::doubleItemsArray() {


	int tempSize = maxItem;
	maxItem = maxItem * 2;
	Item *tempItemArray = new Item[maxItem];

	for (int k = 0; k < tempSize; k++)
	{
		tempItemArray[k] = items[k];
	}

	items = tempItemArray;



	int *tempQntArray = new int[maxItem];
	int k;
	for (k = 0; k < tempSize; k++)
	{
		tempQntArray[k] = quantityItem[k];
	}
	quantityItem = tempQntArray;
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
*/