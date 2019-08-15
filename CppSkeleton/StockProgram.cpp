
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "StockItem.h"
#include "Inventory.h"
using namespace std;


string line;
vector<string> field;

//stock items
StockItem* sItem;
Resistor* rItem;
Capacitor* cItem;
Diode* dItem;
Transistor* tItem;
IC* icItem;

//inventory list
Inventory* invList = new Inventory();

int main(int argc, char** argv) 
{
    //variables
    ifstream myfile;
    myfile.open ("inventory.txt");
    
    //adding the contents into the inventory list
    if(myfile)
    {
        while(getline(myfile,line)) // To get you all the lines.     
        {
           
            for(int i=0; i < line.length(); i++)
            {
         
                if(line.at(i) == ' ')
                {
                    line.erase(i,1);
                    i = i-2;
                }
            }
            for(int i=0; i < line.length(); i++) 
            {
                if(line.at(i) == ',')
                {
                    field.push_back(line.substr(0,i)); //puts the substring of the line into the field vector
                    line.erase(0, i+1); //erases what was put in
                    i = 0; //reset i
                }
            }
            field.push_back(line);
            
            //diode field size is 4 so this is a check to see if it is a diode
            if (field.size() == 5)
            {
                if(field[0] == "resistor") {
                    rItem = new Resistor(field[0], field[1], atoi(field[2].c_str()), atoi(field[3].c_str()), field[4]);
                    invList->addItem(rItem);
                    //cout << sItem->getStockCode() << endl;
                    field.clear();
                }
                if(field[0] == "capacitor") {
                    cItem = new Capacitor(field[0], field[1], atoi(field[2].c_str()), atoi(field[3].c_str()), field[4]);
                    invList->addItem(cItem);
                    //cout << sItem->getStockCode() << endl;
                    field.clear();
                }
                if(field[0] == "transistor") {
                    tItem = new Transistor(field[0], field[1], atoi(field[2].c_str()), atoi(field[3].c_str()), field[4]);
                    invList->addItem(tItem);
                    //cout << sItem->getStockCode() << endl;
                    field.clear();
                }
                if(field[0] == "IC") {
                    icItem = new IC(field[0], field[1], atoi(field[2].c_str()), atoi(field[3].c_str()), field[4]);
                    invList->addItem(icItem);
                   //cout << sItem->getStockCode() << endl;
                    field.clear();
                }
                
            }
            if(field.size() == 4)
            {
                if(field[0] == "diode") {
                    dItem = new Diode(field[0], field[1], atoi(field[2].c_str()), atoi(field[3].c_str()));
                    invList->addItem(dItem);
                    //cout << sItem->getStockCode() << endl;
                    field.clear();
                }
            }
        }
    }
    
    myfile.close(); 
    
    //query1
    cout << "Query 1: Sorted Inventory List: " << endl;
    invList->sortList();
    invList->printList();
    cout << endl;
    //query2
    cout << "Query 2: Stock Item with the highest stock: " << endl;
    invList->sortHighestComponent();
    cout << endl;
    
    //query3
    cout << "Query 3: Total Amount of NPN Transistors: " << endl;
    invList->NPNFinder();
    cout << endl;
    //query4
    cout << "Query 4: Total Resistance of all Resistors: " << endl;
    invList->findResistance();
    cout << endl;
    
    //query5
    cout << "Query 5: Amount of Stock Items above 10p: " << endl;
    invList->unitPriceCheck();
    cout << endl;
    
    return 0;    
}