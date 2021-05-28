#include "ScanList.h"
#include "Scan.h"

ScanList::ScanList()
{
	scans = nullptr;
}

ScanList::~ScanList()
{
	for(; scans->getNext() != nullptr;)
	{
		Scan* temp = scans;
		scans = scans->getNext();
		delete temp;
	}
}

void ScanList::AddScan(int serialNumber)
{
	bool isFound = false;
	if (scans)
	{
		Scan* tempNode;
		tempNode = scans;
		while (tempNode != nullptr)
		{
			if (tempNode->getSerialNumber() == serialNumber)
			{
				tempNode->recycle();
				isFound = true;
			}
			tempNode = tempNode->getNext();
		}
	}

	if(!isFound)
	{
		Scan* newNode = new Scan(serialNumber);
		//newNode->setNext(nullptr);
		AddNode(newNode);
	}
}

void ScanList::AddNode(Scan *node)
{
	if (this->scans)
	{
		Scan* tempNode = scans;
		while (tempNode != nullptr)
		{
			if (tempNode->getSerialNumber() > node->getSerialNumber())
			{
				node->setNext(tempNode->getNext());
				tempNode->setNext(node);
			}
			tempNode = tempNode->getNext();
		}
	}
	else
	{
		this->scans = node; // Head node
	}
}


bool ScanList::removeScan(int serialNumber)
{
	int counter = 0;
	Scan* current = scans;
	Scan* previous = scans;
	/*if (scans->getNext() == nullptr)
	{
		delete scans;
	}*/


	 if (scans)
	{
		while (current->getNext() != nullptr)
		{
			current = current->getNext();
			counter++;
			
		}
		if(counter == 1)
		{
			if (scans->getSerialNumber() == serialNumber)
			{
				scans = current->getNext();
				delete current;
				return true;
			}
		}
		else
		{
			if (counter > 1)
			{
				previous = current;
				current = current->getNext();
				previous = current->getNext();
				delete current;
				return true;
			}
		}
	}
	return false;
}

int ScanList::getTimesRecycled(int serialNumber)
{
	if(scans)
	{
		Scan* temp = scans;
		while(temp->getNext()!= nullptr)
		{
			if (temp->getSerialNumber() == serialNumber)
			{
				return temp->getTimesRecycled();
			}
			temp = temp->getNext();
		}
	}
	return 0;
}

	