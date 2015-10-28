#include "Inventory.h";
#include <string>
using namespace std;

	void Inventory::setQty(int value)
	{
		_qty = value;
	}
	int Inventory::getQty()
	{
		return _qty;
	}
	void Inventory::setPrice(double value)
	{
		_price = value;
	}
	double Inventory::getPrice()
	{
		return _price;
	}
	void Inventory::setID(int value)
	{
		_id = value;
	}
	int Inventory::getID()
	{
		return _id;
	}
	void Inventory::setCategory(string value)
	{
		_category = value;
	}
	string Inventory::getCategory()
	{
		return _category;
	}
	void Inventory::setName(string value)
	{
		_name = value;
	}
	string Inventory::getName()
	{
		return _name;
	}
	void Inventory::displayItem()
	{
		cout << "Item #" << getID() << ":  "  << getName() << endl; 
		cout << "Category: " << getCategory() << endl;
		cout << "Price:    " << getPrice() << endl;
		cout << "Qty:      " << getQty() << endl;
		cout << " " << endl;
	}


