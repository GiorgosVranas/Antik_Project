#include "Customer.h"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;


Customer::Customer() 
{
	custNo=0;
	strcpy(this->custName,"\0");
	strcpy(this->custEmail,"\0");
	
}

Customer::Customer(int custNo1, char custName1[], char custEmail1[])
{
	custNo=custNo1;
	strcpy(this->custName,custName1);
	strcpy(this->custEmail,custEmail1);
}


void Customer::readData()
{
	
	cout << "Enter CustNo: ";
	cin >> custNo ;
	cout << "Enter CustName: ";
	cin >> custName ;
	cout << "Enter CustEmail: ";
	cin >> custEmail ;
	
}

void Customer::setData(int custNo1, char custName1[], char custEmail1[])
{
	custNo=custNo1;
	strcpy(this->custName,custName1);	strcpy(this->custEmail,custEmail1);
}

void Customer::printData()
{
	cout << "Customer List" << endl;
	cout << "=============" << endl;
	
	cout << custNo << " "  << " , " << custName << " " << " , " << custEmail << endl;
}

int Customer::getCustNo()
{
	return custNo;
}

char* Customer::getCustName()
{
	return custName;
}

char* Customer::getCustEmail()
{
	return custEmail;
}






