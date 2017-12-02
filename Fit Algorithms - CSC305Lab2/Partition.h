#pragma once
#include <iostream>
#include <string>

using namespace std;

class Partition {
private:
	int size, hole;
	string name, freeOrBusy, jobName;
public:
	Partition();
	Partition(string name, int size);
	int getSize();
	void setSize(int size);
	int getHole();
	void setHole(int hole);
	string getName();
	void setName(string name);
	string isFreeOrBusy();
	void setFreeOrBusy(string freeOrBusy);
	string getJobUsed();
	void setJobUsed(string jobName);
	void print();
};
Partition::Partition() {
	size = 0;
	name = "";
	hole = 0;
	freeOrBusy = "free";
	jobName = "";
}
Partition::Partition(string name, int size) {
	this->name = name;
	this->size = size;
	hole = 0;
	freeOrBusy = "free";
	jobName = "";
}
int Partition::getSize() {
	return size;
}
void Partition::setSize(int size) {
	this->size = size;
}
int Partition::getHole() {
	return hole;
}
void Partition::setHole(int hole) {
	this->hole = hole;
}
string Partition::getName() {
	return name;
}
void Partition::setName(string name) {
	this->name = name;
}
string Partition::isFreeOrBusy() {
	return freeOrBusy;
}
void Partition::setFreeOrBusy(string freeOrBusy) {
	this->freeOrBusy = freeOrBusy;
}
string Partition::getJobUsed() {
	return jobName;
}
void Partition::setJobUsed(string jobName) {
	this->jobName = jobName;
}
void Partition::print() {
	cout << name << ':' << endl;
	cout << "The size is " << size << endl;
	if (hole == 0) {
		cout << "There is no hole." << endl;
	}
	else {
		cout << "The hole is: " << hole << "kb" << endl;
	}
	if (freeOrBusy == "free") {
		cout << "There are no jobs associated with this partition." << endl;
	}
	else {
		cout << jobName << " is taking up this partition." << endl;
	}
	cout << endl;
}