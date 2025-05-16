#ifndef ITEM_H
#define ITEM_H


class Item
{
 private:
    int itemNo; // product number
    char itemDesc[21]; // product description
    float itemPrice; // product price
 public:
    Item();
    Item(int itemNo1, char itemDesc1[], float itemPrice1);
    void readData();
    void setData(int itemNo1, char itemDesc1[], float itemPrice1);
    void printData();
    int getItemNo();
    char * getItemDesc();
    float getItemPrice();
};
#endif
