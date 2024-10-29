#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Pipe {
    string name;
    int length;
    int diameter;
    bool underRepair;
};

struct PumpingStation {
    string name;
    int totalShops;
    int activeShops;
    double efficiency;
}; 
void inputPipe(Pipe& pipe) {
    cout << "Enter pipe name: ";
    cin.ignore();
    getline(cin, pipe.name);

    cout << "Enter length (km): ";
    while (!(cin >> pipe.length)) {
        cout << "Invalid input. Please enter a number for length: ";
        cin.clear();
        cin.ignore(10000, '\n'); // Clear input buffer
    }

    cout << "Enter diameter: ";
    while (!(cin >> pipe.diameter)) {
        cout << "Invalid input. Please enter a number for diameter: ";
        cin.clear();
        cin.ignore(10000, '\n'); // Clear input buffer
    }

    char repairStatus;
    cout << "Is the pipe under repair? (y/n): ";
    cin >> repairStatus;
    pipe.underRepair = (repairStatus == 'y' || repairStatus == 'Y');
}

void inputPumpingStation(PumpingStation& ps) {
    cout << "Enter pumping station name: ";
    cin.ignore();
    getline(cin, ps.name);

    cout << "Enter total number of shops: ";
    while (!(cin >> ps.totalShops)) {
        cout << "Invalid input. Please enter a number for total shops: ";
        cin.clear();
        cin.ignore(10000, '\n'); // Clear input buffer
    }

    cout << "Enter number of active shops: ";
    while (!(cin >> ps.activeShops)) {
        cout << "Invalid input. Please enter a number for active shops: ";
        cin.clear();
        cin.ignore(10000, '\n'); // Clear input buffer
    }

    cout << "Enter efficiency: ";
    while (!(cin >> ps.efficiency)) {
        cout << "Invalid input. Please enter a number for efficiency: ";
        cin.clear();
        cin.ignore(10000, '\n'); // Clear input buffer
    }
}

void displayPipe(const Pipe& pipe) {
    cout << "Pipe Name: " << pipe.name << "\n"
        << "Length: " << pipe.length << " km\n"
        << "Diameter: " << pipe.diameter << "\n"
        << "Under Repair: " << (pipe.underRepair ? "Yes" : "No") << "\n";
}

void displayPumpingStation(const PumpingStation& ps) {
    cout << "Pumping Station Name: " << ps.name << "\n"
        << "Total Shops: " << ps.totalShops << "\n"
        << "Active Shops: " << ps.activeShops << "\n"
        << "Efficiency: " << ps.efficiency << "\n";
}

void editPipeRepairStatus(Pipe& pipe) {
    char repairStatus;
    cout << "Change repair status for pipe " << pipe.name << " (y/n): ";
    cin >> repairStatus;
    pipe.underRepair = (repairStatus == 'y' || repairStatus == 'Y');
}

void editPumpingStationShops(PumpingStation& ps) {
    char action;
    cout << "Do you want to activate (a) or deactivate (d) a shop? ";
    cin >> action;

    if (action == 'a' || action == 'A') {
        if (ps.activeShops < ps.totalShops) {
            ps.activeShops++;
            cout << "One shop activated.\n";
        }
        else {
            cout << "All shops are already active.\n";
        }
    }
    else if (action == 'd' || action == 'D') {
        if (ps.activeShops > 0) {
            ps.activeShops--;
            cout << "One shop deactivated.\n";
        }
        else {
            cout << "No active shops to deactivate.\n";
        }
    }
    else {
        cout << "Invalid action.\n";
    }
}
void view_all(const Pipe& pipe, const PumpingStation& ps) {
    if (pipe.name == "None") {
        cout << "Pipe isn`t defined\n";
    }
    else {
        displayPipe(pipe);
    };
    if (ps.name == "None") {
        cout << "PS isn`t defined\n";
    }
    else {
        displayPumpingStation(ps);
    };
}

void pipe_in_file(const Pipe& pipe, ofstream& file) {
    file << "Pipe\n" <<
        pipe.name << endl <<
        pipe.length << endl <<
        pipe.diameter << endl <<
        pipe.underRepair << endl;
}

void ps_in_file(const PumpingStation& ps, ofstream& file) {
    file << "Pump Station\n" <<
        ps.name << endl <<
        ps.totalShops << endl <<
        ps.activeShops << endl <<
        ps.efficiency << endl;
}

void saveToFile(Pipe& pipe, PumpingStation& ps) {
    ofstream file;
    file.open("data.txt");
    if (!file.is_open()) {
        cout << "File is`nt defined";
    }
    else {
        if (!(pipe.name == "None")) {
            pipe_in_file(pipe, file);
        }
        if (!(ps.name == "None")) {
            ps_in_file(ps, file);
        }
    }
}
void info_pipe_fr_file(Pipe& pipe, ifstream& file) {
    getline(file, pipe.name);
    file >> pipe.length;
    file >> pipe.diameter;
    file >> pipe.underRepair;
}
void info_ps_fr_file(PumpingStation& ps, ifstream& file) {
    getline(file, ps.name);
    file >> ps.totalShops;
    file >> ps.activeShops;
    file >> ps.efficiency;
}
void loadFromFile(Pipe& pipe, PumpingStation& ps) {
    string line;
    ifstream file;
    file.open("data.txt");
    if (!file.is_open()) {
        cout << "File isn`t defined";
        return;
    }
    while (getline(file, line)) {
        if (line == "Pipe") {
            info_pipe_fr_file(pipe, file);
        }
        if (line == "Pump Station") {
            info_ps_fr_file(ps, file);
        }
    }
}
int main() {
    Pipe pipe = {"None"};
    PumpingStation ps= { "None"};
    int choice;

    do {
        cout << "\nMenu:\n"
            << "1. Add Pipe\n"
            << "2. Add Pumping Station\n"
            << "3. View All Objects\n"
            << "4. Edit Pipe\n"
            << "5. Edit Pumping Station\n"
            << "6. Save to File\n"
            << "7. Load from File\n"
            << "0. Exit\n"
            << "Choose an action: ";

        cin >> choice;

        switch (choice) {
        case 1:
            inputPipe(pipe);
            break;
        case 2:
            inputPumpingStation(ps);
            break;
        case 3:
            view_all(pipe,ps);
            break;
        case 4:
            editPipeRepairStatus(pipe);
            break;
        case 5:
            editPumpingStationShops(ps);
            break;
        case 6:
            saveToFile(pipe, ps);
            break;
        case 7:
            loadFromFile(pipe, ps);
            break;
        case 0:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}





