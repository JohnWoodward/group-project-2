#include "Item.h"

class Cart {
public:

	Cart(int cartSize);
	~Cart();
	Cart(const Cart & Cart);
	void increasePrice(Item changeItem, double priceIncrease);
	void decreasePrice(Item changeItem, double amountDecreased);
	void removeItem(Item itemToRemove);
	void addItem(Item newItem, int quantity);
	void printCart();
	int itemsInCart;
	Item* items;
	int* quantityItem;
	int maxItem;

private:

	
	Item currentItem;

	//void doubleItemsArray();
	//void halfItemsArray();
};