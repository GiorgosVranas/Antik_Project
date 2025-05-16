#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include "Item.h"
#include "Customer.h"
#include "Order.h"
#define N 20

using namespace std;

int fileToArr(ifstream &fin, Item p[]);
int itemMenu(Item p[], int n);
int searchItem(Item p[], int n, int kok);

int main() {
    int overall,NumberArray,positionArray,quantityitems,agorasmena[N],agorasmenaquantity[N];
    int counterquantity=0;
    int countofile;
    ifstream infile("ITEMS.txt");
    ofstream outfile("ORDERS.txt");
    Item itemArr[N];
    Order order1;

    overall = fileToArr(infile, itemArr);
    order1.readData();
    do {
        NumberArray = itemMenu(itemArr, overall);
        positionArray = searchItem(itemArr, overall, NumberArray);
            if (positionArray == -1){
                cout << "Not on the list." << endl;
            } else {
                cout << "Amount: ";
                cin >> quantityitems;
                order1.buyItem(itemArr[positionArray].getItemPrice(), quantityitems);
                agorasmena[counterquantity] = NumberArray;
                agorasmenaquantity[counterquantity] = quantityitems;
                counterquantity++;
                cout << "Successful purchase" << endl;
                cout << endl;
            }
    } while (NumberArray != 0);
    outfile << "Customer No\t: " << order1.getCustNo() << endl << "Customer Name\t: " << order1.getCustName() << endl 
	<< "Customer Email\t: " << order1.getCustEmail() << endl << "Order No\t: " << order1.getOrderNo() << endl 
	<< "Order Date\t: " << order1.getOrderDate() << endl << endl 
	<< "Code\t        Item\t\t            Amount\t        Price\tFinal Price" << endl 
	<< "=======\t       ===================\t    ========\t        ======\t======" << endl;
    for (countofile=0; countofile<counterquantity; countofile++){
        int kodikos = agorasmena[countofile];
        int searchfor = searchItem(itemArr, overall, kodikos);
        int posotita = agorasmenaquantity[countofile];
        float timi = itemArr[searchfor].getItemPrice();
        float teliki_timi = ((itemArr[searchfor].getItemPrice()) * posotita);
        char fitemDesc[21];
        strcpy(fitemDesc, itemArr[searchfor].getItemDesc());
        outfile << kodikos << "\t\t" << fitemDesc << "\t\t" << posotita << "\t\t" << timi << "\t" << teliki_timi << endl;
    }
    outfile << endl
    << "\t\t\t\t\t\t  	Total amount: "
    << order1.getTotalAmount()
    << endl
    << "\t\t\t\t\t\t        Shipping: "
    << order1.shippingCost()
    << endl;
    outfile.close();
    return 0;
}

int fileToArr(ifstream &fin, Item p[]){
    int fitemNo;
    char fitemDesc[20];
    float fitemPrice;
    int grammes1 = 0;
    string grammes;
        
            while (getline(fin, grammes)) {
                stringstream linestring(grammes.substr(0, 4));
                linestring >> fitemNo;
                strcpy(fitemDesc, grammes.substr(4, 16).c_str());
                stringstream timi_proiontos_se_string(grammes.substr(20, 10));
                timi_proiontos_se_string >> fitemPrice;
                p[grammes1].setData(fitemNo, fitemDesc, fitemPrice);
                grammes1++;
            }
        return grammes1;
    }

int itemMenu(Item p[], int n){
	cout << endl;
    cout << "Available Item List" << endl;
    cout << "===========================" << endl;
    int countmenu, countmenu2;
    for (countmenu=0; countmenu<n; countmenu++){
        cout << p[countmenu].getItemNo() << ",\t" << p[countmenu].getItemDesc() << ",\t" << p[countmenu].getItemPrice() << endl;
    }
    cout << "Press 0 to exit" << endl;
    cout << endl;
    cout << "Give Number: "; 
    cin >> countmenu2;
    return countmenu2;
}

int searchItem(Item p[], int n, int kok){
    int countitems, countitems2;
    for (countitems=0; countitems<n; countitems++){
        countitems2 = p[countitems].getItemNo();
        if (countitems2 == kok){
            return countitems;
        }
    }
    return -1;
}
