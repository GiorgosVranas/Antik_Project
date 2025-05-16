#ifndef ORDER_H
#define ORDER_H
#include "Item.h"
#include "Customer.h"


class Order : public Customer , public Item // multiple inheritance
{
 private:
    int orderNo; // orders number
    char orderDate[11]; // orders date
    float totalAmount; // total amount
 public:
    Order();
    Order(int orderNo1, char orderDate1[], float totalAmount1,
    int custNo1, char custName1[], char custEmail1[],
    int itemNo1, char itemDesc1[], float itemPrice1);
    void readData(); // kalw thn sunarthsh readData() ths Customer prwta
 					 // kai meta zhta na plhktrologhthei to orderNo kai to orderDate
 					 
    void setData(int orderNo1, char orderDate1[], float totalAmount1,
    int custNo1, char custName1[],char custEmail1[],
    int itemNo1, char itemDesc1[], float itemPrice1);
    void printData();
    int getOrderNo();
    char * getOrderDate();
    float getTotalAmount();
    void buyItem(float price, int qty); // pollaplasiazei thn posothta me thn timh monados tou prointos
									    //  pou agorasthke kai athrizei thn aksia sto sunoliko poso agorwn
									    
    int shippingCost(); // an to sunoliko poso gorwn einai megalutero apo 200 eurw
 						// emfanizei 0,alliws emfanizei 20 eurw sta metaforika eksoda
 }; 

#endif

