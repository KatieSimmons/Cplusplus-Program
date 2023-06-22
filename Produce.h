#ifndef PRODUCE_H
#define PRODUCE_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Produce{
public: 
	void incrementItem();
	Produce();
	Produce(string name, int numItems);
	//int getNumItems
	int getNum() const;					//will return numItems
	string getName() const;				//will return name;
	void setName(string produceName);	//will set name = produceName;
	void setNum(int number);			//will set numItems = number;
	void printHistogram();				//will print Histogram
	

private:
	int numItems;
	string name;
	string histogram;
	int numStars;

};



#endif

