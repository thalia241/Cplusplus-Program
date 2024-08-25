// Charity Deel
// 08/16/2024
// CS-210

#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <map>
#include <string>

using namespace std;

class GroceryTracker {
private:
	map<string, int> itemFrequency;

public:
	// Constructor to initialize and read input
	GroceryTracker(const string& inputFile);

	// Method to read the data from file and create map
	void readFile(const string& inputFile);

	// Method to backup to frequency.dat
	void backupData(const string& outputFile) const;

	// Method to search for item frequency
	void searchItem(const string& item) const;

	// Method to print items adn frequencies
	void printItems() const;

	// Method to print histogram
	void printHistogram() const;
};

#endif // GROCERYTRACKER_H
