#pragma once

#include <string>
#include <iostream>
#include "Item.h"

using namespace std;

class Shop
{
public:

	Shop();
	~Shop();

	void Buying();

private:

	int money = 1000;
	int select = 0, amount = 0, totalprice = 0;
	string yn;

};