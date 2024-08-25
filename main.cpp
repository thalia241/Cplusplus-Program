// Charity Deel
// 08/16/2024
// CS-210

#include <iostream>
#include "GroceryTracker.h"

using namespace std;

int getMenuChoice() {
	int choice;
	while (true) {
		cout << "\nMenu Options:" << endl;
		cout << "1. Search for an item frequency" << endl;
		cout << "2. Print all items with frequencies" << endl;
		cout << "3. Print a histogram of item frequencies" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		if (cin.fail() || choice < 1 || choice > 4) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid choice. Please enter a number between 1 and 4" << endl;
		}
		else {
			break;
		}
	}
	return choice;
}

int main() {
	GroceryTracker tracker("data/CS210_Project_Three_input_file.txt");
	tracker.backupData("data/frequency.dat");

	while (true) {
		int choice = getMenuChoice();
		if (choice == 1) {
			string item;
			cout << "Enter the item to search for: ";
			cin >> item;
			tracker.searchItem(item);
		}
		else if (choice == 2) {
			tracker.printItems();
		}
		else if (choice == 3) {
			tracker.printHistogram();
		}
		else if (choice == 4) {
			cout << "Exiting program." << endl;
			break;
		}
	}

	return 0;
}
