// Charity Deel
// 08/16/2024
// CS-210

#include "GroceryTracker.h"
#include <iostream>
#include <fstream>

using namespace std;

GroceryTracker::GroceryTracker(const string& inputFile) {
	readFile(inputFile);
}

void GroceryTracker::readFile(const string& inputFile) {
	ifstream file(inputFile);
	string item;
	while (file >> item) {
		itemFrequency[item]++;
	}
	file.close();
}

void GroceryTracker::backupData(const string& outputFile) const {
	ofstream file(outputFile);
	for (const auto& pair : itemFrequency) {
		file << pair.first << " " << pair.second << endl;
	}
	file.close();
}

void GroceryTracker::searchItem(const string& item) const {
	auto it = itemFrequency.find(item);
	if (it != itemFrequency.end()) {
		cout << item << " was purchased " << it->second << " times." << endl;
	}
	else {
		cout << item << " was not found." << endl;
	}
}

void GroceryTracker::printItems() const {
	for (const auto& pair : itemFrequency) {
		cout << pair.first << " " << pair.second << endl;
	}
}

void GroceryTracker::printHistogram() const {
	for (const auto& pair : itemFrequency) {
		cout << pair.first << " ";
		for (int i = 0; i < pair.second; i++) {
			cout << "*";
		}
		cout << endl;
	}
}
