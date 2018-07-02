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

	//Item* itemPtr = new Item;
	//Item* itemPtr = new Item{ "333", 3.33 };

	Item* itemPtr;
	Item item;
	item.setName("ddd");
	item.setPrice(333);
	itemPtr = &item;
	items = new Item[maxItem]();
	for (int i = 0; i < maxItem; i++) {
		items[i] = *itemPtr; // Fill with zeroes
	}
}

Cart::~Cart() {
	// syntax for deleting an array
	delete[] items;
	delete[] quantityItem;
}


// Function to increase price of an item in the cart

void Cart::increasePrice(Item changeItem, double priceIncrease) {

	for (int i = 0; i < itemsInCart; i++) {

		if (items[i].getName() == changeItem.getName()) {
			items[i].setPrice(priceIncrease + items[i].getPrice());
		}
	}
}




// Function to decrease price of an item in the cart
void Cart::decreasePrice(Item changeItem, double amountDecreased) {

	for (int i = 0; i < itemsInCart; i++) {

		if (items[i].getName() == changeItem.getName()) {
			items[i].setPrice(items[i].getPrice() - amountDecreased);
		}
	}
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

	/*
	Item *tempItemArray = new Item[maxItem];
	int tempSize = maxItem;

	for (int i = 0; i < itemsInCart; i++) {
	if (items[i].getName == itemToRemove.getName) {

	if (quantityItem[i] > 0); {
	quantityItem[i] = 0;
	}

	for (int k = 0; k < tempSize; k++)
	{
	tempItemArray[k] = items[k];
	}

	items = tempItemArray;
	}


	}
	*/
}

// TODO build function that removes an item from cart and shifts elements in cart to the left to fill empty space


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

		if (cartBool == false && itemsInCart == maxItem) {
			cout << "unable to add item, cart is to full!" << endl;
		}

		else if (cartBool == false) {

			quantityItem[itemsInCart] = quantity;

			items[itemsInCart] = newItem;
			itemsInCart++;
		}

	}



	else {

		quantityItem[itemsInCart] = quantity;

		items[itemsInCart] = newItem;
		itemsInCart++;
	}





	// TODO build function that adds an item and quantity of item to the cart
}

// Function to print the cart
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




// TODO build function that will print out all contents of cart along with their qty and price
// also it needs to print out total number of items and total cart price
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