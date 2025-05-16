#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer
{
 private:
    int custNo; //customer list
    char custName[21]; // customer name
    char custEmail[21]; // customer email 
 public:
    Customer();
    Customer(int custNo1, char custName1[], char custEmail1[]);
    void readData();
    void setData(int custNo1, char custName1[], char custEmail1[]);
    void printData();
    int getCustNo();
    char * getCustName();
    char* getCustSurname();
    char * getCustEmail();
};

