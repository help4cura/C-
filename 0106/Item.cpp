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
	cout << "������ �̸� : " << ItemName << endl;
	cout << "������ ���� : " << ItemDescription << endl;
	cout << "������ ���� : " << ItemPrice << endl;
	cout << "===============================================================================" << endl << endl;
}

int Item::Sword()
{
	ItemName = "��";
	ItemDescription = "��";
	ItemPrice = 50;

	return ItemPrice;
}

int Item::Potion()
{
	ItemName = "����";
	ItemDescription = "ü���� ȸ���� �� �ִ�.";
	ItemPrice = 80;

	return ItemPrice;
}
