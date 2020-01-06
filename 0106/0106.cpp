#include <iostream>
#include "Item.h"
#include "Shop.h"

int main()
{

	Item* item = new Item;
	Shop* shop = new Shop;

	shop->Buying();
	
	delete item;
	delete shop;

}
