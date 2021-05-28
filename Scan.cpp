#include <iostream>
#include "Scan.h"

Scan::Scan(int number)
{
	this->serialNumber= number;
	this->timesRecycled = 1;
	next = nullptr;
}

Scan::~Scan()
{
	std::cout << "Destructor is called";
}

int Scan::getSerialNumber()
{
	return this->serialNumber;
}

Scan* Scan::getNext()
{
	return this->next;
}

void Scan::setNext(Scan* nextScan)
{
	this->next = nextScan;
}

void Scan::recycle()
{
	this->timesRecycled += 1;
}

int Scan::getTimesRecycled()
{
	return this->timesRecycled;
}
	

