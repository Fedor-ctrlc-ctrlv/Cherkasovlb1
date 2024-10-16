#pragma once
#include <string>
#include <iostream>
#define PIPE_H

using namespace std;
class Pipe
{
private:
	string name;
	double length;
	double diameter;
	bool inRepair;
public:
	Pipe(const string& name, double length, double diameter);
	void input();
	void display() const;
	void RepairStatus(bool status);
	string toFileFormat() const;
	static Pipe fromFileFormat(const string& line);

};

