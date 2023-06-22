#include "Produce.h"



Produce::Produce(){									//default constructor
	name = "";										//set to empty string and 1 item
	numItems = 1;
}

Produce::Produce(string name, int numItems){		//constructor
	this->name = name;
	this->numItems = numItems;
}

int Produce::getNum() const{
	return numItems;
}

string Produce::getName() const{
	return name;
}

void Produce::setName(string produceName){
	name = produceName;
}

void Produce::setNum(int number){
	numItems = number;
}

void Produce::printHistogram() {
	int numStars = this->getNum();
	for (int i = 0; i < numStars; i++) {
		cout << "*";
	}
}

void Produce::incrementItem() {
	this->numItems = this->numItems + 1;
}







