#pragma once

#include <string>
#include <iostream>

using namespace std;

class Item
{

public:

	Item();
	~Item();

	void Describe();

	int Sword();

	int ElementalOrb();
	int DimensionElementalOrb();

	int PotionSmall();
	int PotionMedium();
	int PotionLarge();

	/*
	string getName() { return ItemName; }
	void setName(string name) { ItemName = name; }
	string getDescription() { return ItemDescription; }
	void setDescription(string description) { ItemDescription = description; }
	int getPrice() { return ItemPrice; }
	int setPrice(int price) { ItemPrice = price; }
	*/

private:

	string ItemName;
	string ItemDescription;
	string Rare;
	int ItemPrice;

};