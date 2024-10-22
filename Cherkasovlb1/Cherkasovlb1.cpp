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
        cin.ignore();
        cout << "Enter pipe's name: ";
        getline(cin, name);
        cout << "Enter pipe's length: ";
        cin >> length;
        cout << "Enter pipe's diameter: ";
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
        cin.ignore(); 
        cout << "Enter CS's name: ";
        getline(cin, name);
        cout << "Enter number of Shops (kol-vo Cehov): ";
        cin >> NumberofShops;
        RabochieShops = 0;
        cout << "Enter efficiency: ";
        cin >> efficiency;
    }

    void display() const {
        cout << "CS: " << name << ", Total shops: " << NumberofShops << ", in works: " << RabochieShops << ", effectiveness: " << efficiency << endl;
    }

    void startShop() {
        if (RabochieShops < NumberofShops) {
            RabochieShops++;
            cout << "Shop started working" << endl;
        }
        else {
            cout << "ALL SHOPS ARE WORKING" << endl;
        }
    }

    void stopShop() {
        if (RabochieShops > 0) {
            RabochieShops--;
            cout << "Shop stopped" << endl;
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
    for (const auto& pipe : pipes) {
        file << "Pipe " << pipe.name << " " << pipe.length << " " << pipe.diameter << " " << pipe.inRepair << "\n";
    }
    for (const auto& station : stations) {
        file << "Station " << station.name << " " << station.NumberofShops << " " << station.RabochieShops << " " << station.efficiency << endl;
    }
    file.close();
    cout << "Data has been saved\n";
}

void loadFromFile() {
    ifstream file("data.txt");
    string type;
    while (file >> type) {
        if (type == "Pipe") {
            Pipe pipe;
            file >> ws; 
            getline(file, pipe.name, ' ');
            file >> pipe.length >> pipe.diameter >> pipe.inRepair;
            pipes.push_back(pipe);
        }
        else if (type == "Station") {
            CS station;
            file >> ws;
            getline(file, station.name, ' ');
            file >> station.NumberofShops >> station.RabochieShops >> station.efficiency;
            stations.push_back(station);
        }
    }
    file.close();
    cout << "Data has been loaded from file\n";
}

void menu() {
    while (true) {
        cout << "\n1. Add pipe\n2. Add CS\n3. View all objects\n4. Edit Pipe\n5. Edit CS\n6. Save\n7. Load data\n0. EXIT\n";
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
        case 3: {
            for (const auto& pipe : pipes) pipe.display();
            for (const auto& station : stations) station.display();
            break;
        }
        case 4: {
            cout << "Enter pipe's name to edit: " << endl;
            cin.ignore();
            string name;
            getline(cin, name);
            for (auto& pipe : pipes) {
                if (pipe.name == name) {
                    cout << "Enter number for 1 to 3\n1. Change length\n2. Change diameter\n3. Change status of Repair\n";
                    int minichoice;
                    cin >> minichoice;
                    switch (minichoice) {
                    case 1: {
                        cout << "Enter new length: " << endl;
                        cin >> pipe.length;
                        break;
                    }
                    case 2: {
                        cout << "Enter new diameter: ";
                        cin >> pipe.diameter;
                        break;
                    }
                    case 3: {
                        cout << "Change status of Repair ";
                        pipe.Repair();
                        break;
                    }
                    default:
                        cout << "The wrong number, please try again" << endl;
                    }
                    cout << "The repair status has been changed" << endl;
                    break;
                }
            }
            break;
        }
        case 5: {
            cout << "Enter CS's name to edit: " << endl;
            cin.ignore();
            string name;
            getline(cin, name);
            for (auto& station : stations) {
                if (station.name == name) {
                    int action;
                    cout << "Enter number for 1 to 3\n1. Start shop\n2. Stop shop\n3. Change number of shops\n";
                    cin >> action;
                    switch (action) {
                    case 1: {
                        station.startShop();
                        break;
                    }
                    case 2: {
                        station.stopShop();
                        break;
                    }
                    case 3: {
                        cout << "Enter new number of shops: ";
                        cin >> station.NumberofShops;
                        break;
                    }
                    default:
                        cout << "The wrong number, try again\n";
                    }
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
            cout << "The wrong number, try again\n";
        }
    }
}

int main() {
    menu();
    return 0;
}


