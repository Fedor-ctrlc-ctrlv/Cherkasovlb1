#include "Pipe.h"
using namespace std;
Pipe::Pipe(const string&name, double length,double diameter):name(name),length(length),diameter(diameter),inRepair(false){}
void Pipe::input() {
	cout << "Enter the name of the pipe:";
	cin >> name;
	cout << "Enter pipe`s length";
	cin >> length;
	cout << "Enter pipe`s diameter";
	cin >> diameter;
	inRepair = false;
}

void Pipe::display() const {
	cout << "Pipe: " << name << ",Length: " << length << ",diameter: " << diameter << ", in Repair?" << inRepair << endl;
}
void Pipe::RepairStatus(bool status) {
	inRepair = status;
}
string Pipe::toFileFormat() const {
	return "PIPE|"+ name +"|"+ to_string(length) +"|"+ to_string(diameter)+"|" + to_string(inRepair);
}
Pipe Pipe::fromFileFormat(const string& line) {
	istringstream iss(line);
	string token;
	getline(iss, token, '|');


}