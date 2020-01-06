#include <iostream>
#include "Item.h"

int main()
{
	int money = 1000;
	int select = 0, amount = 0, totalprice = 0;
	char yn;

	Item* item = new Item;

	cout << "1." << endl;

	item->Sword();
	item->Describe();

	cout << "2." << endl;

	item->Potion();
	item->Describe();

	cout << "소지금 : " << money << endl << endl;

	cout << "어떤 아이템을 구매하시겠습니까?" << endl << endl;
	cout << "->";

	cin >> select;

	cout << endl;
	cout << "몇 개 구매하시겠습니까?" << endl;
	cout << "->";

	cin >> amount;

	if (select == 1) {
		totalprice = item->Sword() * amount;
		cout << "물품의 합계는 총 " << totalprice << "원 입니다. 정말 구매하시겠습니까? (Y/N)" << endl;
		cout << "->";
		cin >> yn;
		if ((yn == 'Y') && ((money -= totalprice) >= 0)) {
			money -= totalprice;
			cout << "물품을 정상적으로 구매하였습니다." << endl;
			cout << money << "원 남았습니다.";
		}
		else {
			cout << "구매를 취소하셨거나, 소지금이 부족합니다.";
		}
	}
	else if (select == 2) {
		totalprice = item->Potion() * amount;
		cout << "물품의 합계는 총 " << totalprice << "원 입니다. 정말 구매하시겠습니까? (Y/N)" << endl;
		cout << "->";
		cin >> yn;
		if ((yn == 'Y') && ((money -= totalprice) >= 0)) {
			money -= totalprice;
			cout << "물품을 정상적으로 구매하였습니다." << endl;
			cout << money << "원 남았습니다.";
		}
		else {
			cout << "구매를 취소하셨거나, 소지금이 부족합니다.";
		}
	}
}