#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void pressEnterToContinue() {
	cout << "\nPress enter to continue... \n";
	cin.clear();
	while (cin.get() != '\n') continue;
}

bool readFromFile(string filename) {
	ifstream inFile;
	string movieTitle;
	int year;
	inFile.open(filename);

	if (inFile.fail()) {
		cout << "read error - sorry\n";
		return false;
	}
	while (true) {
		inFile >> movieTitle >> year;
		if (inFile.fail()) break;

		cout << movieTitle << ": " << year << endl;
	}
	inFile.close();
	return true;
}

int main() {
	string datafile;
	cout << "Lab 12 Intro to Text Files!\n";
	cout << "Enter filename: ";
	getline(cin, datafile);
	bool status = readFromFile(datafile);
	if (status) cout << "Success!\n";
	else cout << "failure. :-(\n";
	pressEnterToContinue();
}