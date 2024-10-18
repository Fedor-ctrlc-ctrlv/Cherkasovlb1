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
		cout << "CS: " << name << "Total shops:" << NumberofShops << ", in works: " << RabochieShops << ", effectiveness" << efficiency << endl;
	}
	void startShop() {
		if (RabochieShops < NumberofShops) {
			RabochieShops++;
			cout << "Shop start working" << endl;
		}
		else {
			cout << "ALL SHOPS ARE WORKING" << endl;
		}
	}
	void stopShop() {
		if (RabochieShops > 0) {
			RabochieShops--;
			cout << "shop stoped"<<endl;
		}
		else {
			cout << "No working shop" << endl;
		}
	}

};
vector<Pipe> pipes;
vector<CS> stations;

int main(){
	while (true) {
		cout << "\n1. Add pipe\n2. Add CS\n3. view all objects\n4. Redact Pipe\n5. Redact CS\n6. Save\n7. Load\n8. EXIT";
		int choice;
		cin >> choice;
		switch (choice) {
		case 1: {

		}
		}
	}
}

