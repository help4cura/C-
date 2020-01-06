#include "Shop.h"
#include <Windows.h>

Shop::Shop()
{

}

Shop::~Shop()
{
}

void Shop::Buying()
{
	Item* item = new Item;

	while (true) {
		cout << "1." << endl;
		item->Sword();
		item->Describe();

		cout << "2." << endl;
		item->PotionSmall();
		item->Describe();

		cout << "3." << endl;
		item->PotionMedium();
		item->Describe();

		cout << "4." << endl;
		item->PotionLarge();
		item->Describe();

		cout << "5." << endl;
		item->ElementalOrb();
		item->Describe();

		cout << "6." << endl;
		item->DimensionElementalOrb();
		item->Describe();

		cout << "====================================" << endl;
		cout << "=         소지금 : " << money << "원" << "          =" << endl;
		cout << "====================================" << endl << endl;

		cout << "어떤 아이템을 구매하시겠습니까?" << endl;
		cout << "-> ";

		cin >> select;

		cout << endl;
		cout << "몇 개 구매하시겠습니까?" << endl;
		cout << "-> ";

		cin >> amount;
		cout << endl;

		if (select == 1) {
			totalprice = item->Sword() * amount;
			cout << "물품의 합계는 총 " << totalprice << "원입니다. 정말 구매하시겠습니까? (Y/N)" << endl;
			cout << "-> ";
			cin >> yn;
			if ((yn == "Y") && (totalprice <= money)) {
				money -= totalprice;
				cout << "물품을 정상적으로 구매하였습니다." << endl;
				cout << money << "원 남았습니다." << endl;
				cout << "3초 뒤, 화면이 갱신됩니다.";
				Sleep(3000);
				system("cls");
			}
			else {
				cout << "구매를 취소하셨거나, 소지금이 부족합니다." << endl << endl;;
				cout << "3초 뒤, 화면이 갱신됩니다.";
				Sleep(3000);
				system("cls");
			}
		}
		else if (select == 2) {
			totalprice = item->PotionSmall() * amount;
			cout << "물품의 합계는 총 " << totalprice << "원입니다. 정말 구매하시겠습니까? (Y/N)" << endl;
			cout << "-> ";
			cin >> yn;
			if ((yn == "Y") && (totalprice <= money)) {
				money -= totalprice;
				cout << "물품을 정상적으로 구매하였습니다." << endl;
				cout << money << "원 남았습니다." << endl;
				cout << "3초 뒤, 화면이 갱신됩니다.";
				Sleep(3000);
				system("cls");
			}
			else {
				cout << "구매를 취소하셨거나, 소지금이 부족합니다." << endl << endl;;
				cout << "3초 뒤, 화면이 갱신됩니다.";
				Sleep(3000);
				system("cls");
			}
		}
		else if (select == 3) {
			totalprice = item->PotionMedium() * amount;
			cout << "물품의 합계는 총 " << totalprice << "원입니다. 정말 구매하시겠습니까? (Y/N)" << endl;
			cout << "-> ";
			cin >> yn;
			if ((yn == "Y") && (totalprice <= money)) {
				money -= totalprice;
				cout << "물품을 정상적으로 구매하였습니다." << endl;
				cout << money << "원 남았습니다." << endl;
				cout << "3초 뒤, 화면이 갱신됩니다.";
				Sleep(3000);
				system("cls");
			}
			else {
				cout << "구매를 취소하셨거나, 소지금이 부족합니다." << endl << endl;;
				cout << "3초 뒤, 화면이 갱신됩니다.";
				Sleep(3000);
				system("cls");
			}
		}
		else if (select == 4) {
			totalprice = item->PotionLarge() * amount;
			cout << "물품의 합계는 총 " << totalprice << "원입니다. 정말 구매하시겠습니까? (Y/N)" << endl;
			cout << "-> ";
			cin >> yn;
			if ((yn == "Y") && (totalprice <= money)) {
				money -= totalprice;
				cout << "물품을 정상적으로 구매하였습니다." << endl;
				cout << money << "원 남았습니다." << endl;
				cout << "3초 뒤, 화면이 갱신됩니다.";
				Sleep(3000);
				system("cls");
			}
			else {
				cout << "구매를 취소하셨거나, 소지금이 부족합니다." << endl << endl;;
				cout << "3초 뒤, 화면이 갱신됩니다.";
				Sleep(3000);
				system("cls");
			}
		}
		else if (select == 5) {
			totalprice = item->ElementalOrb() * amount;
			cout << "물품의 합계는 총 " << totalprice << "원입니다. 정말 구매하시겠습니까? (Y/N)" << endl;
			cout << "-> ";
			cin >> yn;
			if ((yn == "Y") && (totalprice <= money)) {
				money -= totalprice;
				cout << "물품을 정상적으로 구매하였습니다." << endl;
				cout << money << "원 남았습니다." << endl;
				cout << "3초 뒤, 화면이 갱신됩니다.";
				Sleep(3000);
				system("cls");
			}
			else {
				cout << "구매를 취소하셨거나, 소지금이 부족합니다." << endl << endl;;
				cout << "3초 뒤, 화면이 갱신됩니다.";
				Sleep(3000);
				system("cls");
			}
		}
		else if (select == 6) {
			totalprice = item->DimensionElementalOrb() * amount;
			cout << "물품의 합계는 총 " << totalprice << "원입니다. 정말 구매하시겠습니까? (Y/N)" << endl;
			cout << "-> ";
			cin >> yn;
			if ((yn == "Y") && (totalprice <= money)) {
				money -= totalprice;
				cout << "물품을 정상적으로 구매하였습니다." << endl;
				cout << money << "원 남았습니다." << endl;
				cout << "3초 뒤, 화면이 갱신됩니다.";
				Sleep(3000);
				system("cls");
			}
			else {
				cout << "구매를 취소하셨거나, 소지금이 부족합니다." << endl << endl;;
				cout << "3초 뒤, 화면이 갱신됩니다.";
				Sleep(3000);
				system("cls");
			}
		}
	}
}
