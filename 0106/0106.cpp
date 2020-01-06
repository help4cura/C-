#include <iostream>
#include "Item.h"

int main()
{
	int money = 1000;
	int select = 0, amount = 0;

	Item* item = new Item;

	cout << "1." << endl;

	item->Sword();
	item->Describe();

	cout << "2." << endl;

	item->Potion();
	item->Describe();

	cout << "어떤 아이템을 구매하시겠습니까?" << endl << endl;
	cout << "->";

	cin >> select;

	cout << endl;
	cout << "몇 개 구매하시겠습니까?" << endl;
	cout << "->";

	cin >> amount;

	if (select == 1) {
		money -= item->Sword() * amount;
	}
	else if (select == 2) {
		money -= item->Potion() * amount;
	}

	cout << money;
}

