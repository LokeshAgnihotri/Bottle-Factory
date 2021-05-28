#pragma once
#include "Scan.h"

class ScanList
{
private:
	Scan* scans; // pointer to linked list of Scans 
public:
	ScanList(); // post: this->scans is empty


	
	virtual ~ScanList(); // post: all scans have been destructed


	void AddNode(Scan* scan);
	void AddScan(int serialNumber);
	
	bool removeScan(int serialNumber);
	
	int getTimesRecycled(int serialNumber);
	

	
};

