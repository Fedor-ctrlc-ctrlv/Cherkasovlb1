#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
struct Pipe {
	string name;
	double length;
	double diameter;
	bool inRepair;
	void input() {
		cout << "Enter pipe`s name: ";
		cin >> name;
		cout << "Enter pipe`s length: ";
		cin >> length;
		cout << "Enter pipe`s diameter";
		cin >> diameter;
		inRepair = false;
	}
	void display() const {
		cout << "Pipe: " << name << ", length: " << length << " km, Diameter: " << diameter << " m, In Repair: " << (inRepair ? "YES" : "NO") << endl;

	}
	void Repair() {
		inRepair = !inRepair;
	}

};
struct CS {
	string name;
	int NumberofShops;
	int RabochieShops;
	double efficiency;

	void input() {
		cout << "Enter CS`s shop: ";
		cin >> name;
		cout << "Enter number of Shops: ";
		cin >> NumberofShops;
		RabochieShops = 0;
		cout << "Enter efficiency";
		cin >> efficiency;
	}
	void display() const {
		cout << "CS: " << name < " ,Shops: " << NumberofShops << ", in works: " << RabochieShops << ", effectiveness" << efficiency << endl;
	}

};


int main(){

}

