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
		cout << "=         ������ : " << money << "��" << "          =" << endl;
		cout << "====================================" << endl << endl;

		cout << "� �������� �����Ͻðڽ��ϱ�?" << endl;
		cout << "-> ";

		cin >> select;

		cout << endl;
		cout << "�� �� �����Ͻðڽ��ϱ�?" << endl;
		cout << "-> ";

		cin >> amount;
		cout << endl;

		if (select == 1) {
			totalprice = item->Sword() * amount;
			cout << "��ǰ�� �հ�� �� " << totalprice << "���Դϴ�. ���� �����Ͻðڽ��ϱ�? (Y/N)" << endl;
			cout << "-> ";
			cin >> yn;
			if ((yn == "Y") && (totalprice <= money)) {
				money -= totalprice;
				cout << "��ǰ�� ���������� �����Ͽ����ϴ�." << endl;
				cout << money << "�� ���ҽ��ϴ�." << endl;
				cout << "3�� ��, ȭ���� ���ŵ˴ϴ�.";
				Sleep(3000);
				system("cls");
			}
			else {
				cout << "���Ÿ� ����ϼ̰ų�, �������� �����մϴ�." << endl << endl;;
				cout << "3�� ��, ȭ���� ���ŵ˴ϴ�.";
				Sleep(3000);
				system("cls");
			}
		}
		else if (select == 2) {
			totalprice = item->PotionSmall() * amount;
			cout << "��ǰ�� �հ�� �� " << totalprice << "���Դϴ�. ���� �����Ͻðڽ��ϱ�? (Y/N)" << endl;
			cout << "-> ";
			cin >> yn;
			if ((yn == "Y") && (totalprice <= money)) {
				money -= totalprice;
				cout << "��ǰ�� ���������� �����Ͽ����ϴ�." << endl;
				cout << money << "�� ���ҽ��ϴ�." << endl;
				cout << "3�� ��, ȭ���� ���ŵ˴ϴ�.";
				Sleep(3000);
				system("cls");
			}
			else {
				cout << "���Ÿ� ����ϼ̰ų�, �������� �����մϴ�." << endl << endl;;
				cout << "3�� ��, ȭ���� ���ŵ˴ϴ�.";
				Sleep(3000);
				system("cls");
			}
		}
		else if (select == 3) {
			totalprice = item->PotionMedium() * amount;
			cout << "��ǰ�� �հ�� �� " << totalprice << "���Դϴ�. ���� �����Ͻðڽ��ϱ�? (Y/N)" << endl;
			cout << "-> ";
			cin >> yn;
			if ((yn == "Y") && (totalprice <= money)) {
				money -= totalprice;
				cout << "��ǰ�� ���������� �����Ͽ����ϴ�." << endl;
				cout << money << "�� ���ҽ��ϴ�." << endl;
				cout << "3�� ��, ȭ���� ���ŵ˴ϴ�.";
				Sleep(3000);
				system("cls");
			}
			else {
				cout << "���Ÿ� ����ϼ̰ų�, �������� �����մϴ�." << endl << endl;;
				cout << "3�� ��, ȭ���� ���ŵ˴ϴ�.";
				Sleep(3000);
				system("cls");
			}
		}
		else if (select == 4) {
			totalprice = item->PotionLarge() * amount;
			cout << "��ǰ�� �հ�� �� " << totalprice << "���Դϴ�. ���� �����Ͻðڽ��ϱ�? (Y/N)" << endl;
			cout << "-> ";
			cin >> yn;
			if ((yn == "Y") && (totalprice <= money)) {
				money -= totalprice;
				cout << "��ǰ�� ���������� �����Ͽ����ϴ�." << endl;
				cout << money << "�� ���ҽ��ϴ�." << endl;
				cout << "3�� ��, ȭ���� ���ŵ˴ϴ�.";
				Sleep(3000);
				system("cls");
			}
			else {
				cout << "���Ÿ� ����ϼ̰ų�, �������� �����մϴ�." << endl << endl;;
				cout << "3�� ��, ȭ���� ���ŵ˴ϴ�.";
				Sleep(3000);
				system("cls");
			}
		}
		else if (select == 5) {
			totalprice = item->ElementalOrb() * amount;
			cout << "��ǰ�� �հ�� �� " << totalprice << "���Դϴ�. ���� �����Ͻðڽ��ϱ�? (Y/N)" << endl;
			cout << "-> ";
			cin >> yn;
			if ((yn == "Y") && (totalprice <= money)) {
				money -= totalprice;
				cout << "��ǰ�� ���������� �����Ͽ����ϴ�." << endl;
				cout << money << "�� ���ҽ��ϴ�." << endl;
				cout << "3�� ��, ȭ���� ���ŵ˴ϴ�.";
				Sleep(3000);
				system("cls");
			}
			else {
				cout << "���Ÿ� ����ϼ̰ų�, �������� �����մϴ�." << endl << endl;;
				cout << "3�� ��, ȭ���� ���ŵ˴ϴ�.";
				Sleep(3000);
				system("cls");
			}
		}
		else if (select == 6) {
			totalprice = item->DimensionElementalOrb() * amount;
			cout << "��ǰ�� �հ�� �� " << totalprice << "���Դϴ�. ���� �����Ͻðڽ��ϱ�? (Y/N)" << endl;
			cout << "-> ";
			cin >> yn;
			if ((yn == "Y") && (totalprice <= money)) {
				money -= totalprice;
				cout << "��ǰ�� ���������� �����Ͽ����ϴ�." << endl;
				cout << money << "�� ���ҽ��ϴ�." << endl;
				cout << "3�� ��, ȭ���� ���ŵ˴ϴ�.";
				Sleep(3000);
				system("cls");
			}
			else {
				cout << "���Ÿ� ����ϼ̰ų�, �������� �����մϴ�." << endl << endl;;
				cout << "3�� ��, ȭ���� ���ŵ˴ϴ�.";
				Sleep(3000);
				system("cls");
			}
		}
	}
}
