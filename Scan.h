#pragma once
#ifndef SCAN
#define SCAN
#endif



class Scan
{
private:
	int serialNumber;
	int timesRecycled;
	Scan* next;

public:
	Scan(int number);
	virtual ~Scan();
	int getSerialNumber(); 
	Scan* getNext(); 
	void setNext(Scan* nextScan);
	void recycle(); 
	int getTimesRecycled(); 
	
};

