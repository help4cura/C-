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
	cout << "아이템 이름 : " << ItemName << endl;
	cout << "아이템 설명 : " << ItemDescription << endl;
	cout << "아이템 가격 : " << ItemPrice << "원" << endl;
	cout << "레어도 : " << Rare << endl;
	cout << "=======================================================================================================================" << endl << endl;
}

int Item::Sword()
{
	ItemName = "검";
	ItemDescription = "날이 무딘 검이다.";
	ItemPrice = 50;
	Rare = "★";

	return ItemPrice;
}

int Item::PotionSmall()
{
	ItemName = "포션(소)";
	ItemDescription = "체력을 회복할 수 있다. [효과 적용치 : (소)]";
	ItemPrice = 30;
	Rare = "★";

	return ItemPrice;
}

int Item::PotionMedium()
{
	ItemName = "포션(중)";
	ItemDescription = "체력을 회복할 수 있다. [효과 적용치 : (중)]";
	ItemPrice = 80;
	Rare = "★";

	return ItemPrice;
}

int Item::PotionLarge()
{
	ItemName = "포션(대)";
	ItemDescription = "체력을 회복할 수 있다. [효과 적용치 : (대)]";
	ItemPrice = 175;
	Rare = "★★";

	return ItemPrice;
}

int Item::ElementalOrb()
{
	ItemName = "엘레멘탈 오브";
	ItemDescription = "스킬 사용 시, 소모되는 자원의 양을 감소시킨다. [효과 적용치 : (중)]";
	ItemPrice = 800;
	Rare = "★★";

	return ItemPrice;
}

int Item::DimensionElementalOrb()
{
	ItemName = "디멘션 엘레멘탈 오브";
	ItemDescription = "스킬 사용 시, 소모되는 자원의 양을 증가시키지만, 스킬의 공격력이 상승한다. [효과 적용치 : (중),(중)]";
	ItemPrice = 1500;
	Rare = "★★★";

	return ItemPrice;
}