#pragma once
#include <iostream>
#include <string>

using namespace std;

class Jobs {
private:
	int size;
	string runningOrWaiting, name, partitionName;
public:
	Jobs();
	Jobs(string name, int size);
	int getSize();
	void setSize(int size);
	string isRunningOrWaiting();
	void setRunningOrWaiting(string runningOrWaiting);
	string getName();
	void setName(string name);
	string getPartitionName();
	void setPartitionName(string partitionName);
	void print();
};
Jobs::Jobs() {
	name = "";
	size = 0;
	runningOrWaiting = "";
	partitionName = "";
}
Jobs::Jobs(string name, int size) {
	this->name = name;
	this->size = size;
	runningOrWaiting = "waiting"; //by default process is waiting
	partitionName = "";
}
int Jobs::getSize() {
	return size;
}
void Jobs::setSize(int size) {
	this->size = size;
}
string Jobs::isRunningOrWaiting() {
	return runningOrWaiting;
}
void Jobs::setRunningOrWaiting(string runningOrWaiting) {
	this->runningOrWaiting = runningOrWaiting;
}
string Jobs::getName() {
	return name;
}
void Jobs::setName(string name) {
	this->name = name;
}
string Jobs::getPartitionName() {
	return partitionName;
}
void Jobs::setPartitionName(string partitionName) {
	this->partitionName = partitionName;
}
void Jobs::print() {
	cout << name << ':' << endl;
	cout << "The size is " << size << endl;
	if (runningOrWaiting == "waiting") {
		cout << "This job is waiting to be used." << endl;
	}
	else {
		cout << "This job is taking up " << partitionName << "." << endl;
	}
	cout << endl;
}