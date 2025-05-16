#include "Item.h"
#include "Customer.h"
#include "Order.h"
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

Order::Order() : Item::Item() , Customer::Customer()
{
     
	             
}

Order::Order(int orderNo1, char orderDate1[], float totalAmount1, int custNo1, char custName1[], char custEmail1[], int itemNo1,char  itemDesc1[],float itemPrice1)
: Item::Item(itemNo1, itemDesc1, itemPrice1) , Customer::Customer(custNo1, custName1, custEmail1)
             {
                 orderNo=orderNo1;
                 orderDate[21] = orderDate1[21];
                 totalAmount=totalAmount1;
            }

void Order::readData()
{
    Customer::readData();
    cout << "Type Order's Number :";
    cin >> orderNo;
    cout << "Type Order's Date   :" ;
    cin >> orderDate ;
    
}            


void Order::setData(int orderNo1, char orderDate1[], float totalAmount1,
             int custNo1, char custName1[], char custEmail1[],
             int itemNo1, char itemDesc1[], float itemPrice1)
             {
                orderNo=orderNo1;
                orderDate[21]=orderDate1[21];
                totalAmount=totalAmount1;
                Item::setData(itemNo1, itemDesc1, itemPrice1);
                Customer::setData(custNo1, custName1, custEmail1);
            }


void Order::printData()
{
    cout << "Your Order" << endl;
    cout << "===============" << endl;
    
    cout << "Number: " << orderNo << endl;
    cout << "Date: " << orderDate << endl;
    cout << "Total: " << totalAmount << endl;
    Item::printData();
    Customer::printData();
}


int Order::getOrderNo()
{
    return orderNo;
}

char* Order::getOrderDate()
{
    return orderDate;
}

float Order::getTotalAmount()
{
    return totalAmount;
}

void Order::buyItem(float price, int qty)
{
    totalAmount = totalAmount + price*qty;
}

int Order::shippingCost()
{
    if (totalAmount > 200)
    {
        return 0;
    }
    else
    {
        return 20;
    }
}


