#include <iostream> 
#include <string>
#include <vector>
#include "Inventory.h"
#include <iomanip>
using namespace std;

int total = 0;
int uniqueID = 0;

vector<Inventory> vInventorys;

int main()
{
	// Initialize menu variables
	int selection = 0;

	// Welcome user
	cout << "Welcome to SuperInventory!" << endl;
	cout << " " << endl;

	while (selection != 7)  // System menu
	{
		cout << ":-----------:" << endl;
		cout << ": Main Menu :" << endl;
		cout << ":-----------:" << endl;
		cout << " 1. Add a new item" << endl;
		cout << " 2. Edit an item" << endl;
		cout << " 3. Search for an item" << endl;
		cout << " 4. Delete an item" << endl;
		cout << " 5. View all items" << endl;
		cout << " 6. Populate Sample Data" << endl;
		cout << " 7. Exit system" << endl;
		cout << " " << endl;
		cout << "Enter your selection: ";

		// Capture user selection
		cin >> selection;
		cout << endl;

		if(selection == 1)  // Adds a new Item into the inventory system
		{
			cout << ":-------------:" << endl;
			cout << ": Add an item :" << endl;
			cout << ":-------------:" << endl;

			// Initialize item variables
			string name, category;
			int qty;
			double price;
			Inventory i1;
			
			// Create new item based on user input
			cout << "Enter a name: ";
			cin >> name;
			i1.setName(name);
			cout << "Enter a price: ";
			cin >> price;
			i1.setPrice(price);
			cout << "Enter a quantity: ";
			cin >> qty;
			i1.setQty(qty);
			cout << "Enter a category: ";
			cin >> category;
			i1.setCategory(category);
			i1.setID(uniqueID);
			vInventorys.push_back(i1);
			uniqueID++;
			total++;
			
			cout << " " << endl;
		}
		else if(selection == 2)  // Allows for the properties of an item to be edited
		{
			cout << ":--------------:" << endl; 
			cout << ": Edit an item :" << endl;
			cout << ":--------------:" << endl;
			cout << "Enter the item by ID: ";

			// Initialize item variables
			int search;
			cin >> search;
			bool found = false;

			for(int i = 0; i < total; i++)
			{
				int str = vInventorys[i].getID();

				if (str == search)
				{
					// Display item
					cout << endl;
					vInventorys[i].displayItem();

					// Prompt for user input, make changes
					found = true;
					cout << "Which section do you want to edit?" << endl;
					cout << "1. Item Name " << endl;
					cout << "2. Category " << endl;
					cout << "3. Price " << endl;
					cout << "4. Quantity " << endl;
					int editSelection = 0;
					cin >> editSelection;
					if (editSelection == 1)
					{
						cout << "Enter new name: ";
						string newName;
						cin >> newName;
						vInventorys[i].setName(newName);
					}
					if (editSelection == 2)
					{
						cout << "Enter new category: ";
						string newCategory;
						cin >> newCategory;
						vInventorys[i].setCategory(newCategory);
					}
					if (editSelection == 3)
					{
						cout << "Enter new price: ";
						double newPrice;
						cin >> newPrice;
						vInventorys[i].setPrice(newPrice);
					}
					if (editSelection == 4)
					{
						cout << "Enter new quantity: ";
						int newQuantity;
						cin >> newQuantity;
						vInventorys[i].setQty(newQuantity);
					}
					cout << endl;
					cout << "Item " << i << " has been updated.";
					cout << endl;
				}
			}
			
			// Show message if no item is found
			if (!found)
				cout << "Item not found!" << endl;
			cout << endl;
		}

		else if(selection == 3)  // Searches the inventory for an item
		{
			int searchSelection = 0;
			bool found = false;
			cout << ":--------------------:" << endl;
			cout << ": Search for an item :" << endl;
			cout << ":--------------------:" << endl;
			cout << "1. By ID: " << endl;
			cout << "2. By Name: " << endl;
			cout << "3. By Category: " << endl;
			cout << " " << endl;
			cout << "Enter your selection: ";
			cin >> searchSelection;
			cout << " " << endl;
			
			// Search for item by ID
			if (searchSelection == 1)
			{
				cout << "Enter the item by ID: ";
				int search;
				cin >> search;
				bool found = false;

				for(int i = 0; i < total; i++)
				{
					int str = vInventorys[i].getID();

					if (str == search)
					{
						vInventorys[i].displayItem();
						found = true;
					}					
				}
				if (!found)
					cout << "Item not found!" << endl;
				cout << endl;
			}
			// Search for item by Name
			else if (searchSelection == 2)
			{
				cout << "Enter the item by name: ";
				string search;
				cin >> search;
				bool found = false;

				for(int i = 0; i < total; i++)
				{
					string str = vInventorys[i].getName();
					string::size_type loc = str.find( search, 0 );

					if( loc != string::npos )
					{
						vInventorys[i].displayItem();
						found = true;
					}
				}
				if (!found)
					cout << "Item not found!" << endl;
				cout << endl;
			}
			// Search for item by Category
			else if (searchSelection == 3)
			{
				cout << ":----------------------------:" << endl;
				cout << ": Enter the item by category :" << endl;
				cout << ":----------------------------:" << endl;
				string search;
				cin >> search;
				bool found = false;

				for(int i = 0; i < total; i++)
				{
					string str = vInventorys[i].getCategory();
					string::size_type loc = str.find( search, 0 );

					if( loc != string::npos )
					{
						vInventorys[i].displayItem();
						found = true;
					}
				}
				if (!found)
					cout << "Item not found!" << endl;
				cout << endl;
			}
			else
			{
				cout << "Please enter a valid selection." << endl;
				cout << endl;
			}
		}
		else if(selection == 4)  // Deletes an item from the inventory
		{
			cout << ":----------------:" << endl;
			cout << ": Delete an item :" << endl;
			cout << ":----------------:" << endl;
			cout << "Enter the item by ID: ";

			int search;
			cin >> search;
			int incr = 0;
			int inputID = -1;
			int match = -1;
			bool found = false;
			cout << endl;
			int temp = 0;

			for(int i = 0; i < total; i++)
			{
				
				int str = vInventorys[i].getID();

				if (str == search)
				{
					vInventorys[i].displayItem();
					match = vInventorys[i].getID();
					incr++;
					found = true;
					temp = i;
				}					
			}
			string yn = "";
			if(incr == 1)
			{
				cout << "Do you want to delete this item? (y/n): ";
				cin >> yn;
				cout << endl;
				if(yn == "y")
				{
					vInventorys.erase(vInventorys.begin() + match);					
					cout << "Item " << temp << " was deleted." << endl;
					total--;
				}
				else
				{
					cout << "Item was not deleted!" << endl;
				}
			}
			if (!found)
				cout << "Item not found!" << endl;
			cout << endl;			
		}

		else if(selection == 5)  // View all items in inventory system
		{
			cout << ":----------------:" << endl;
			cout << ": View all items :" << endl;
			cout << ":----------------:" << endl;

			for(int i = 0; i < total; i++)
				vInventorys[i].displayItem();
		}

		else if(selection == 6)  // Populate the inventory system with sample data
		{
			cout << ":----------------------:" << endl;
			cout << ": Populate sample data :" << endl;
			cout << ":----------------------:" << endl;

			
			Inventory i1;
			i1.setName("Apples");
			i1.setPrice(3.50);
			i1.setQty(150);
			i1.setCategory("Fruit");
			i1.setID(total);
			vInventorys.push_back(i1);
			total++;
			uniqueID++;
			
			Inventory i2;
			i2.setName("Bananas");
			i2.setPrice(5.25);
			i2.setQty(60);
			i2.setCategory("Fruit");
			i2.setID(total);
			vInventorys.push_back(i2);
			total++;
			uniqueID++;
			
			Inventory i3;
			i3.setName("Oranges");
			i3.setPrice(3.25);
			i3.setQty(200);
			i3.setCategory("Fruit");
			i3.setID(total);
			vInventorys.push_back(i3);
			total++;
			uniqueID++;
		
			Inventory i4;
			i4.setName("Pizza");
			i4.setPrice(11.99);
			i4.setQty(25);
			i4.setCategory("Frozen");
			i4.setID(total);
			vInventorys.push_back(i4);
			total++;
			uniqueID++;
			
			Inventory i5;
			i5.setName("Chicken");
			i5.setPrice(14.99);
			i5.setQty(20);
			i5.setCategory("Frozen");
			i5.setID(total);
			vInventorys.push_back(i5);
			total++;
			uniqueID++;
			
			cout << endl;
			cout << "Sample data has been entered into the inventory system. " << endl;
			cout << endl;
		}
		else if(selection == 7)  // Show exit message
		{
			cout << "You have exited the system." << endl;
		}
	}

	system("pause");
	return 0;
}