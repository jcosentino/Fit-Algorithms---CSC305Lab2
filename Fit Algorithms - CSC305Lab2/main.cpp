/*
This is Lab 2 of Operating Systems
The purpose of this lab is to demonstrate the algorithms for:
First fit, Best Fit, Worst Fit, and Next Fit.
The user will input the number of jobs and partitions,
and the sizes of each. The user will also input the total
space. The program will print out which partitions are
taken up by a job, how much space each hole contains,
the total waste, which jobs are waiting, and which partitions
each jobs is currently using. NOTE: a hole is the amount of space
wasted by a job when taking up a partition.
*/
#include "Jobs.h"
#include "Partition.h"
#include "FitAlgs.h"
#include <iostream>

using namespace std;

int main() {
	FitAlgs f;
	f.print();

	system("pause");
	return 0;
}