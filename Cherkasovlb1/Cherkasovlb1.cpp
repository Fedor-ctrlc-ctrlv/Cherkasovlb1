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

void saveToFile() {
	ofstream file("data.txt");
	for (const auto& pipe:pipes) {
		file << "Pipe " << pipe.name << " " << pipe.length << " " << pipe.diameter << " " << pipe.inRepair << "\n";
	}
	for (const auto& station : stations) {
		file << "Station " << station.name << " " << station.NumberofShops << " " << station.RabochieShops << " " << station.efficiency << endl;
	}
	file.close();
	cout << " Data have been saved\n";
}
void loadFromFile() {
	ifstream file("data.txt");
	string type;
	while (file >> type) {
		if (type == "Pipe") {
			Pipe pipe;
			file >> pipe.name >> pipe.length >> pipe.diameter >> pipe.inRepair;
			pipes.push_back(pipe);
		}
		else if (type == "Station") {
			CS station;
			file >> station.name >> station.NumberofShops >> station.RabochieShops >> station.efficiency;
			stations.push_back(station);
		}
	}
	file.close();
	cout << "data has been load from file";
}

void menu() {
	while (true) {
		cout << "\n1. Add pipe\n2. Add CS\n3. view all objects\n4. Redact Pipe\n5. Redact CS\n6. Save\n7. Load\n0. EXIT\n";
		int choice;
		cin >> choice;
		switch (choice) {
		case 1: {
			Pipe pipe;
			pipe.input();
			pipes.push_back(pipe);
			break;
		}
		case 2: {
			CS station;
			station.input();
			stations.push_back(station);
			break;
		}
		case 3:{
			for (const auto& pipe : pipes)pipe.display();
			for (const auto& station : stations) station.display();
			break;
		}
		case 4: {
			cout << "Enter pipe`s name to redact";
			string name;
			cin >> name;
			for (auto& pipe : pipes) {
				if (pipe.name == name) {
					pipe.Repair();
					cout << "The sign in the repair has been changed";
					break;
				}
			}
			break;
		}
		case 5: {
			cout << "Enter CS`s name for redact";
			string name;
			cin >> name;
			for (auto& station : stations) {
				if (station.name == name) {
					int action;
					cout << "1. Start shop\n2. stop shop";
					cin >> action;
					if (action == 1)station.startShop();
					else if (action == 2)station.stopShop();
					break;
				}
			}
			break;
		}
		case 6: {
			saveToFile();
			break;
		}
		case 7: {
			loadFromFile();
			break;
		}
		case 0:
			return;
		default:
			cout << "the wrong number, try again\n";
		}
	}
}

int main(){
	menu();
	return 0;
}

