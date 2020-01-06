#include "Item.h"

Item::Item()
{
}

Item::~Item()
{
}

void Item::Describe()
{
	cout << "=======================================================================================================================" << endl;
	cout << "������ �̸� : " << ItemName << endl;
	cout << "������ ���� : " << ItemDescription << endl;
	cout << "������ ���� : " << ItemPrice << "��" << endl;
	cout << "��� : " << Rare << endl;
	cout << "=======================================================================================================================" << endl << endl;
}

int Item::Sword()
{
	ItemName = "��";
	ItemDescription = "���� ���� ���̴�.";
	ItemPrice = 50;
	Rare = "��";

	return ItemPrice;
}

int Item::PotionSmall()
{
	ItemName = "����(��)";
	ItemDescription = "ü���� ȸ���� �� �ִ�. [ȿ�� ����ġ : (��)]";
	ItemPrice = 30;
	Rare = "��";

	return ItemPrice;
}

int Item::PotionMedium()
{
	ItemName = "����(��)";
	ItemDescription = "ü���� ȸ���� �� �ִ�. [ȿ�� ����ġ : (��)]";
	ItemPrice = 80;
	Rare = "��";

	return ItemPrice;
}

int Item::PotionLarge()
{
	ItemName = "����(��)";
	ItemDescription = "ü���� ȸ���� �� �ִ�. [ȿ�� ����ġ : (��)]";
	ItemPrice = 175;
	Rare = "�ڡ�";

	return ItemPrice;
}

int Item::ElementalOrb()
{
	ItemName = "������Ż ����";
	ItemDescription = "��ų ��� ��, �Ҹ�Ǵ� �ڿ��� ���� ���ҽ�Ų��. [ȿ�� ����ġ : (��)]";
	ItemPrice = 800;
	Rare = "�ڡ�";

	return ItemPrice;
}

int Item::DimensionElementalOrb()
{
	ItemName = "���� ������Ż ����";
	ItemDescription = "��ų ��� ��, �Ҹ�Ǵ� �ڿ��� ���� ������Ű����, ��ų�� ���ݷ��� ����Ѵ�. [ȿ�� ����ġ : (��),(��)]";
	ItemPrice = 1500;
	Rare = "�ڡڡ�";

	return ItemPrice;
}