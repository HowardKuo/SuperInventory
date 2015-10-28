#ifndef INVENTORY_CPP
#define INVENTORY_CPP

#include <string>
#include <iostream>
using namespace std;

class Inventory
{
public:
	void setQty(int);
	int getQty();
	void setPrice(double);
	double getPrice();
	void setID(int);
	int getID();
	void setCategory(string);
	string getCategory();
	void setName(string);
	string getName();
	void displayItem();

private: 
	string _category, _name;
	int _qty, _id;
	double _price;
};

#endif