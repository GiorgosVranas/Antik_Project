#include "Item.h"
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

Item::Item() {
	itemNo=0;
	strcpy(itemDesc,"\0");
	itemPrice = 0;
	
}

Item::Item(int itemNo1, char itemDesc1[], float itemPrice1)
{
	itemNo=itemNo1;
	strcpy(this->itemDesc,itemDesc1);
	itemPrice=itemPrice1;
}

void Item::readData()
{
	cout << "Enter itemNo: ";
	cin >> itemNo;
	cout << "Enter itemDesc: ";
	cin >> strcpy(this->itemDesc,"");
	cout << "Enter itemPrice: ";
	cin >> itemPrice;
	cout << endl;
}

void Item::setData(int itemNo1, char itemDesc1[], float itemPrice1)
{
	itemNo=itemNo1;
    strcpy(this->itemDesc,itemDesc1);
	itemPrice=itemPrice1;
}

void Item::printData()
{
//	cout << "Available Products" << endl ;
	cout << "===================" << endl;
	
	cout << itemNo << " " << "," << itemDesc << " " << ", " <<itemPrice << endl;
}

int Item::getItemNo()
{
	return itemNo;
}

char* Item::getItemDesc()
{
	return itemDesc;
}

float Item::getItemPrice()
{
	return itemPrice;
}



