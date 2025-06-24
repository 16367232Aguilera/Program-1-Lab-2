//Michelle Aguilera
//Chocolate Factory - Program 1

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

void orderInventory(int& l, int& m, int& s);
void fillOrder(int& l, int& m, int& s, int& o);
void printInventory(int l, int m, int s);
float calculateShipping(int weight);

int main() {
	int large = 1500, medium = 1200, small = 7000;
	int orderNum = 1;
	char choice;
	cout << fixed << setprecision(2); 

	do {
		cout << "\nMenu:\n";
		cout << "F:  Fill Order\n";
		cout << "P:  Print Inventory\n";
		cout << "O:  Order Inventory\n";
		cout << "E:  Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		choice = toupper(choice);

		switch (choice) {
		case 'F':
			fillOrder(large, medium, small, orderNum);
			break;
		case 'P':
			printInventory(large, medium, small);
			break;
		case 'O':
			orderInventory(large, medium, small);
			break;
		case 'E':
			cout << "\nThank you for using my program!" << endl;
			break;
		default:
			cout << "\nWARNING: " << choice << " is an invalid choice. Please try again.\n";
		}

	}
	while (choice != 'E');
	return 0;
}

void orderInventory(int& l, int& m, int& s) {
	char type;
	int amount;

	cout << "Enter the number of bars to add: ";
	cin >> amount;

	cout << "Enter the type of chocolate bar to add (L/M/S): ";
	cin >> type;
	type = toupper(type);

	switch (type) {
	case 'L':
		l += amount;
		cout << "\nAn additional " << amount << " large bars ordered. New total of large bars = " << l << endl;
		break;
	case 'M':
		m += amount;
		cout << "\nAn additional " << amount << " medium bars ordered. New total of medium bars = " << m << endl;
		break;
	case 'S':
		s += amount;
		cout << "\nAn additional " << amount << " small bars ordered. New total of small bars = " << s << endl;
		break;
	default:
		cout << "\nWARNING: " << type << " is an invalid type. Command ignored.\n"; 
	}
}

void fillOrder(int& l, int& m, int& s, int& o) {
	int pounds;
	cout << "Enter number of pounds of chocolate to order: ";
	cin >> pounds;

	int totalPoundsAvailable = l * 5 + m * 3 + s;

	if (pounds > totalPoundsAvailable) {
		int shortage = pounds - totalPoundsAvailable;
		cout << "\nWARNING: Unable to fill order of " << pounds << " pounds. We are "
			<< shortage << " pounds short. We are sorry for the inconvenience." << endl;
		return;
	}

	int useL = min(pounds / 5, l);
	pounds -= useL * 5;

	int useM = min(pounds / 3, m);
	pounds -= useM * 3;

	int useS = min(pounds, s);
	pounds -= useS;

	if (pounds > 0) {
		cout << "\nWARNING: Unable to fill order. Not enough small bars." << endl;
		return;
	}
	//Prices
	float largeTot = useL * 41.25;
	float mediumTot = useM * 25.80;
	float smallTot = useS * 13.50;
	float subtotal = largeTot + mediumTot + smallTot;
	float tax = subtotal * 0.072;
	float shipping = calculateShipping((useL * 5) + (useM * 3) + useS);
	float total = subtotal + tax + shipping;

	//Print reciept
	cout << fixed << setprecision(2);
	cout << "\nChocolate Order #" << o << endl;
	cout << "Large Bars: " << setw(4) << useL << " " << setw(7) << useL * 5 << setw(12) << largeTot << endl;
	cout << "Medium Bars: " << setw(3) << useM << " " << setw(7) << useM * 3 << setw(12) << mediumTot << endl;
	cout << "Small Bars: " << setw(4) << useS << " " << setw(7) << useS << setw(12) << smallTot << endl;
	cout << "Sub Total: " << setw(13) << (useL * 5 + useM * 3 + useS) << setw(12) << subtotal << endl;
	cout << "\nTax Total: " << setw(25) << tax << endl;
	cout << "Shipping: " << setw(26) << shipping << endl;
	cout << "Total Cost: " << setw(24) << total << endl << endl << endl;

	//Update Inventory
	l -= useL;
	m -= useM;
	s -= useS;
	o++; //increment order number
}

float calculateShipping(int weight) {
	if (weight <= 10) return 8.25;
	else if (weight <= 20) return 12.75;
	else if (weight <= 50) return 15.25;
	else return 19.75;
}

void printInventory(int l, int m, int s) {
	cout << "\nChocolate Inventory:\n";
	cout << "Large Bars: " << setw(5) << l << endl;
	cout << "Medium Bars: " << setw(4) << m << endl;
	cout << "Small Bars: " << setw(5) << s << endl;
}


