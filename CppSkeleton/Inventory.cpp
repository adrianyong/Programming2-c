#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream> 
#include "StockItem.h"
#include "Inventory.h"
using namespace std;

Inventory::Inventory(){}

void Inventory::addItem(StockItem* sItem)
{
    this->listOfStockItems.push_back(sItem);
}

StockItem* Inventory::getItem(int index)
{
    return this->listOfStockItems[index];
}

void Inventory::sortList()
{
    sort(listOfStockItems.begin(), listOfStockItems.end(), [](const StockItem* sItem1, const StockItem* sItem2)
    {
        return sItem1->getUnitPrice() < sItem2->getUnitPrice();
    });
    
}

void Inventory::sortHighestComponent()
{
    StockItem* temp;
    for (StockItem* s: listOfStockItems)
    {
        if (s->getNumItemsStock() > temp->getNumItemsStock())
        {
            temp = s;
        }
        
    }
    cout << "Highest Stock: " + temp->toString() << endl;
   
    
}



void Inventory::NPNFinder()
{
    int temp = 0;
    string str2 = ("NPN\r"); //comparison string for NPN Device
    
    for(StockItem* s: listOfStockItems)
    {
        string str1 = s->getInfo(); //string for getting the info
        
        if(str1.compare(str2) == 0)
        {
           
           temp += s->getNumItemsStock();
        }
    }
    cout << "Total number of NPNs in stock: " + to_string(temp) << endl;
}

void Inventory::unitPriceCheck()
{
    int counter = 0;
    for(StockItem* s: listOfStockItems)
    {      
        if(s->getUnitPrice() > 10)
        {
            counter++;
        }
    }
    cout << "Total number of Stock Units above 10p: " + to_string(counter) << endl;
    
}

void Inventory::findResistance()
{
    
    int intA;
    float intB; //integers for the resistance
    double totalRes = 0;    //total resistance
    
    char resMod;    //resistance modifier
    stringstream resStream; //stringstream to put the info into
    string str2 = ("resistor");     //comparison string for resistor
    int counter = 0;
    
    for(StockItem* s: listOfStockItems)
    {
       double resVal = 0; //resistor value
       string str1 = s->getComponentType(); //string for the component type
       double numStock = static_cast<double>(s->getNumItemsStock()); //double for the number of items in stock
       //int numStock = s->getNumItemsStock();
       string valueString = s->getInfo();  //string for the resistanceValue
       
       
       /*if the item is a resistor*/
       if(str1.compare(str2) == 0)
        {        
            valueString.pop_back(); //remove whitespace
            resStream << valueString; //put the valueString into the stream
            
            if(isdigit(valueString.back()))
            {
                resStream >> intA >> resMod >> intB;
//                counter++;
//                cout << "resistor number: " << counter << endl;

                if (resMod == 'R')
                {
                    resVal = intA + (intB/10);
                }
                if(resMod == 'K')
                {
                    
                    resVal = (intA + (intB/10)) * 1000;
                    
                
                }
                if(resMod =='M')
                {
                    
                    resVal = (intA + (intB/10)) * 1000000;
                }
            }
            else 
            {
                resStream >> intA >> resMod;
//                counter++;
//                cout << "resistor number: " << counter << endl;
                
                if (resMod == 'R')
                {
                    resVal = intA;
                
                }
                if(resMod == 'K')
                {
                    resVal = intA * 1000;
                                     
                }
                if(resMod =='M')
                {
                    resVal = intA * 1000000;
                }
                
            }  
//            cout << "current value: " << resVal << endl;
//            cout << "current stock: " << numStock << endl;
            totalRes += resVal * numStock;
            
            /*flush the stream*/
            resStream.clear();
            resStream.str("");
        }
    }
    //cout << counter << endl;
    cout << "Total Resistance Value: " + to_string(totalRes) + " Ohms" << endl;
}

void Inventory::getSize(){cout << "Size of Inventory List: " + listOfStockItems.size() << endl;}

void Inventory::printList()
{ 
   for (StockItem* s: listOfStockItems)
    {
        cout << s->toString() << endl;   
    }
}