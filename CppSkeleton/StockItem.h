
#ifndef STOCKITEM_H
#define	STOCKITEM_H


#include <stdio.h>
#include <stdlib.h>


using namespace std;

class StockItem
{
private:
    string componentType, stockCode, info;       
    int numItemsStock, unitPrice;

public:

     
    //getters
    string getComponentType() const;
    string getStockCode() const; 
    int getNumItemsStock() const;
    int getUnitPrice() const;
    string getInfo() const;

    //setters
    void setComponentType(char componentTypeInput);
    void setStockCode(char stockCodeInput); 
    void setNumItemsStock(char numItemsStockInput);
    void setUnitPrice(char unitPriceInput);
    void setInfo(char infoInput);
    string toString();
    
    StockItem(string componentType = "", string stockCode = "", 
    int numItemsStock = 0, int unitPrice = 0, string info = "");
 
};

//StockItem classes that inherit the StockItem class
class Resistor : public StockItem
{
public:
    Resistor(string componentType = "", string stockCode = "", 
    int numItemsStock = 0, int unitPrice = 0, string info = ""):
    StockItem(componentType, stockCode, numItemsStock,unitPrice,info){}
    
};

class Capacitor : public StockItem
{
public: 
    Capacitor(string componentType = "", string stockCode = "", 
    int numItemsStock = 0, int unitPrice = 0, string info = ""):
    StockItem(componentType, stockCode, numItemsStock,unitPrice,info){}
};

class Diode : public StockItem
{
public:
    Diode(string componentType = "", string stockCode = "", 
    int numItemsStock = 0, int unitPrice = 0):
    StockItem(componentType, stockCode, numItemsStock,unitPrice){}
};


class Transistor : public StockItem
{
public:

    Transistor(string componentType = "", string stockCode = "", 
    int numItemsStock = 0, int unitPrice = 0, string info = ""):
    StockItem(componentType, stockCode, numItemsStock,unitPrice,info){}
};



class IC : public StockItem
{
public:
    IC(string componentType = "", string stockCode = "", 
    int numItemsStock = 0, int unitPrice = 0, string info = ""):
    StockItem(componentType, stockCode, numItemsStock,unitPrice,info){}
};
#endif	/* STOCKITEM_H */