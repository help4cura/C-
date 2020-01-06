#include "Item.h"

Item::Item()
{
}

Item::~Item()
{
}

void Item::Describe()
{
	cout << "===============================================================================" << endl;
	cout << "아이템 이름 : " << ItemName << endl;
	cout << "아이템 설명 : " << ItemDescription << endl;
	cout << "아이템 가격 : " << ItemPrice << endl;
	cout << "===============================================================================" << endl << endl;
}

int Item::Sword()
{
	ItemName = "검";
	ItemDescription = "검";
	ItemPrice = 50;

	return ItemPrice;
}

int Item::Potion()
{
	ItemName = "포션";
	ItemDescription = "체력을 회복할 수 있다.";
	ItemPrice = 80;

	return ItemPrice;
}
