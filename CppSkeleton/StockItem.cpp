#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include "StockItem.h"

using namespace std;

StockItem::StockItem(string componentType, string stockCode, 
    int numItemsStock, int unitPrice, string info)
{
        this->componentType = componentType;
        this->stockCode = stockCode;    
        this->numItemsStock = numItemsStock;
        this->unitPrice = unitPrice;
        this->info = info;
        
        
};

//getter methods
string StockItem::getComponentType() const {return componentType;}
string StockItem::getStockCode() const {return stockCode;}
int StockItem::getNumItemsStock() const {return numItemsStock;}
int StockItem::getUnitPrice() const {return unitPrice;}
string StockItem::getInfo() const {return info;}


//setter methods
void StockItem::setComponentType(char componentTypeInput) {componentType = componentTypeInput;}
void StockItem::setStockCode(char stockCodeInput){stockCode = stockCodeInput;}
void StockItem::setNumItemsStock(char numItemsStockInput){numItemsStock = numItemsStockInput;}
void StockItem::setUnitPrice(char unitPriceInput){unitPrice = unitPriceInput; }
void StockItem::setInfo(char infoInput){info = infoInput;}

//toString method
string StockItem::toString(){return componentType + " ," + stockCode + " ,"  + to_string(numItemsStock) + " ,"  + to_string(unitPrice) + " ,"  + info;}


