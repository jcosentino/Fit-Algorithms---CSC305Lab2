#pragma once
#include "Jobs.h"
#include "Partition.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class FitAlgs {
private:
	int total_size, waste;
	vector<Partition> partitions;
	vector<Jobs> jobs;
public:
	FitAlgs();
	FitAlgs(int total_size);
	int getTotal_Size();
	void setTotal_Size(int total_size);
	int getWaste();
	void setWaste(int waste);
	void best_fit();
	void worst_fit();
	void first_fit();
	void next_fit();
	void fillTotal_Size();
	void fillJobs();
	void fillPartitions();
	void listPartitions();
	void listJobs();
	void clearAll();
	void printWaste();
	void print();
};
FitAlgs::FitAlgs() {
	total_size = 0;
	waste = 0;
}
FitAlgs::FitAlgs(int total_size) {
	this->total_size = total_size;
	waste = 0;
}
int FitAlgs::getTotal_Size() {
	return total_size;
}
void FitAlgs::setTotal_Size(int total_size) {
	this->total_size = total_size;
}
int FitAlgs::getWaste() {
	return waste;
}
void FitAlgs::setWaste(int waste) {
	this->waste = waste;
}
void FitAlgs::best_fit() {
	cout << "This is the best fit algorithm:" << endl
		 << "------------------------------" << endl;
	for (int jobsPosition = 0; jobsPosition < jobs.size(); jobsPosition++) {
		int smallestHole = jobs[jobsPosition].getSize()+1, partsIndex = -1;
		for (int partsPosition = 0; partsPosition < partitions.size(); partsPosition++) {
			if (jobs[jobsPosition].getSize() <= partitions[partsPosition].getSize()
				&& partitions[partsPosition].getSize() -
				jobs[jobsPosition].getSize() < smallestHole
				&& partitions[partsPosition].isFreeOrBusy() == "free") {
				smallestHole = partitions[partsPosition].getSize() - 
					jobs[jobsPosition].getSize();
				partsIndex = partsPosition;
			}
		}
		if (partsIndex != -1) {
			jobs[jobsPosition].setPartitionName(partitions[partsIndex].getName());
			jobs[jobsPosition].setRunningOrWaiting("running");
			partitions[partsIndex].setFreeOrBusy("busy");
			partitions[partsIndex].setHole(
				partitions[partsIndex].getSize() - jobs[jobsPosition].getSize());
			partitions[partsIndex].setJobUsed(jobs[jobsPosition].getName());
			waste = waste + partitions[partsIndex].getHole();
		}
	}
	listJobs();
	listPartitions();
	printWaste();
	clearAll();
}
void FitAlgs::worst_fit() {
	cout << "This is the worst fit algorithm:" << endl
		<< "------------------------------" << endl;
	for (int jobsPosition = 0; jobsPosition < jobs.size(); jobsPosition++) {
		int biggestHole = -1, partsIndex = -1;
		for (int partsPosition = 0; partsPosition < partitions.size(); partsPosition++) {
			if (jobs[jobsPosition].getSize() <= partitions[partsPosition].getSize()
				&& partitions[partsPosition].getSize() -
				jobs[jobsPosition].getSize() > biggestHole
				&& partitions[partsPosition].isFreeOrBusy() == "free") {
				biggestHole = partitions[partsPosition].getSize() -
					jobs[jobsPosition].getSize();
				partsIndex = partsPosition;
			}
		}
		if (partsIndex != -1) {
			jobs[jobsPosition].setPartitionName(partitions[partsIndex].getName());
			jobs[jobsPosition].setRunningOrWaiting("running");
			partitions[partsIndex].setFreeOrBusy("busy");
			partitions[partsIndex].setHole(
				partitions[partsIndex].getSize() - jobs[jobsPosition].getSize());
			partitions[partsIndex].setJobUsed(jobs[jobsPosition].getName());
			waste = waste + partitions[partsIndex].getHole();
		}
	}
	listJobs();
	listPartitions();
	printWaste();
	clearAll();
}
void FitAlgs::first_fit() {
	cout << "This is the first fit algorithm:" << endl
		<< "------------------------------" << endl;
	for (int jobsPosition = 0; jobsPosition < jobs.size(); jobsPosition++) {
		bool taken = false;
		for (int partsPosition = 0; partsPosition < partitions.size()
			&& taken == false; 
			partsPosition++) {
			if (jobs[jobsPosition].getSize() <= partitions[partsPosition].getSize()
				&& partitions[partsPosition].isFreeOrBusy() == "free") {
				jobs[jobsPosition].setPartitionName(partitions[partsPosition].getName());
				jobs[jobsPosition].setRunningOrWaiting("running");
				partitions[partsPosition].setFreeOrBusy("busy");
				partitions[partsPosition].setHole(
					partitions[partsPosition].getSize() - jobs[jobsPosition].getSize());
				partitions[partsPosition].setJobUsed(jobs[jobsPosition].getName());
				taken = true;
				waste = waste + partitions[partsPosition].getHole();
			}
		}
	}
	listJobs();
	listPartitions();
	printWaste();
	clearAll();
}
void FitAlgs::next_fit() {
	cout << "This is the next fit algorithm:" << endl
		<< "------------------------------" << endl;
	int partsPosition = 0;
	for (int jobsPosition = 0; jobsPosition < jobs.size(); jobsPosition++) {
		int partitionTraversals = 0;
		while (partitionTraversals < partitions.size()) {
			if (partsPosition == partitions.size()) {
				partsPosition = 0;
			}
			if (jobs[jobsPosition].getSize() <= partitions[partsPosition].getSize()) {
				jobs[jobsPosition].setPartitionName(partitions[partsPosition].getName());
				jobs[jobsPosition].setRunningOrWaiting("running");
				partitions[partsPosition].setFreeOrBusy("busy");
				partitions[partsPosition].setHole(
					partitions[partsPosition].getSize() - jobs[jobsPosition].getSize());
				partitions[partsPosition].setJobUsed(jobs[jobsPosition].getName());
				waste = waste + partitions[partsPosition].getHole();
				partitionTraversals = partitions.size();
			}
			partitionTraversals++;
			partsPosition++;
		}
	}
	listJobs();
	listPartitions();
	printWaste();
	clearAll();
}
void FitAlgs::fillTotal_Size() {
	int memorySize;
	cout << "How much memory is there?" << endl;
	cin >> memorySize;
	while (memorySize <= 5) {
		cout << "That is not enough memory. Please try again:" << endl;
		cin >> memorySize;
	}
	total_size = memorySize;
}
void FitAlgs::fillJobs() {
	int numJobs = 0, tempSize;
	cout << "How many jobs are there? Please enter no more than 5." << endl;
	while (numJobs > 5 || numJobs < 1) {
		cin >> numJobs;
		if (numJobs > 5) {
			cout << "That is too many. Please re-enter the number of jobs."
				<< endl;
		}
		if (numJobs < 1) {
			cout << "That is too few. Please re-enter the number of jobs."
				<< endl;
		}
	}
	for (int i = 1; i <= numJobs; i++) {
		cout << "How big is Job" << i << "?" << endl;
		cin >> tempSize; //need to implement error-checking
		jobs.push_back(Jobs("Job" + to_string(i), tempSize));
	}
}
void FitAlgs::fillPartitions() {
	int numParts = 0, tempSize, totalTempSize = 0;
	cout << "How many partitions are there? Please enter no more than 5." << endl;
	while (numParts > 5 || numParts < 1) {
		cin >> numParts;
		if (numParts > 5) {
			cout << "That is too many. Please re-enter the number of partitions."
				<< endl;
		}
		if (numParts < 1) {
			cout << "That is too few. Please re-enter the number of partitions."
				<< endl;
		}
	}
	for (int i = 1; i <= numParts; i++) {
		cout << "How big is Partition" << i << "?" << endl;
		cin >> tempSize; //need to implement error-checking
		totalTempSize += tempSize;
		partitions.push_back(Partition("Partition" + to_string(i), tempSize));
	}
	if (totalTempSize > total_size) {
		cout << "The partitions are bigger than the size of memory!"
			<< " Please re-enter your partitions." << endl;
		partitions.clear();
		fillPartitions();
	}
}
void FitAlgs::listPartitions() {
	if (partitions.size() == 0) {
		cout << "There are no partitions." << endl;
		return;
	}
	for (int i = 0; i < partitions.size(); i++) {
		partitions[i].print();
	}
}
void FitAlgs::listJobs() {
	if (jobs.size() == 0) {
		cout << "There are no jobs." << endl;
		return;
	}
	for (int i = 0; i < jobs.size(); i++) {
		jobs[i].print();
	}
}
void FitAlgs::clearAll() {
	for (int partsPosition = 0; partsPosition < partitions.size(); partsPosition++) {
		partitions[partsPosition].setFreeOrBusy("free");
		partitions[partsPosition].setHole(0);
		partitions[partsPosition].setJobUsed("");
	}
	for (int jobsPartition = 0; jobsPartition < jobs.size(); jobsPartition++) {
		jobs[jobsPartition].setRunningOrWaiting("waiting");
		jobs[jobsPartition].setPartitionName("");
	}
	waste = 0;
}
void FitAlgs::printWaste() {
	if (waste == 0) {
		cout << "There is no waste" << endl;
	}
	else {
		cout << "There was " << waste << "kb wasted." << endl;
	}
}
void FitAlgs::print() {
	fillTotal_Size();
	fillJobs();
	cout << endl;
	fillPartitions();
	cout << endl;
	first_fit();
	cout << endl;
	best_fit();
	cout << endl;
	worst_fit();
	cout << endl;
	next_fit();
	cout << endl;
}