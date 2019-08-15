
#ifndef INVENTORY_H
#define	INVENTORY_H

#include <iostream>
#include <vector>
#include "StockItem.h"
using namespace std;

class Inventory
{
private:
    vector<StockItem*> listOfStockItems;
    
public:
    Inventory();
    void addItem(StockItem* sItem);
    StockItem* getItem(int index);
    void sortList(); 
    void removeItem(int index);  
    void getSize();
    void printList();
    
    //queries
    void sortHighestComponent();
    void NPNFinder();
    void unitPriceCheck();
    void findResistance();
};
#endif	/* INVENTORY_H */

