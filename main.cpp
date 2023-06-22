#include "Produce.h"
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <stdexcept>		
//#include <ifstream>
#include <map>
#include <iostream>
using namespace std;


void introMssg() {								//function prints intro message
	cout << "Please choose option:\n";
	cout << "1 - particular item's quantity\n";
	cout << "2 - list each item with its quantity\n";
	cout << "3 - list each item with quantity and histogram\n";
	cout << "4 - quit\n";
}
//function inputs data from file stream, and populates map<string,int>
map<string,int> populateMap() {					 
	ifstream inputFS;							//input file stream
	string produceItem;							//data from file
	
	map<string, int> map;						//declare map to associate"map" each key (produce item) to its value (numItems)

	inputFS.open("GroceryInput.txt");			//try to open GroceryInput.txt file
	if (!inputFS.is_open()) {
		cout << "Could not open file GroceryInput.txt." << endl;
		return map;								//prematurely exit function and return empty map if cannot open file
	}

	inputFS >> produceItem;						//read first item from file
	while (!inputFS.eof()) {					//while-loop to input each item from file (until eof)

		if (!inputFS.fail()) {					//assuming input was successful: 
												
			if (map.count(produceItem) == 0) {	//if item DNE in map, add this item using:   map.emplace(key,value);
				map.emplace(produceItem, 1);	//NOTE: map.count(key): returns 1 if the key exists, 0 if key DNE
			}									//NOTE: map.emplace(key,value): associates key w/ value, if key already exists, map entry is unchanged
			else {								//ELSE:  item is ALREADY in map:   
				map.at(produceItem) = map.at(produceItem) + 1;		// increment key's value 
			}									//NOTE: map.at(key) returns key's assoc'd VALUE so  aka: value = value + 1
			inputFS >> produceItem;				//update for while-loop: read next item from file into produceItem string var.
		}
		else {									//ELSE: inputting DID have a FAILURE: 
			cout << "Program failed to input all items from GroceryInput.txt file.";
												//print error messg
		}
	}
	inputFS.close();							//CLOSE input file stream b/c done using it
	//cout << "file was read in full.\n";					//used for future troubleshooting 
	//print size of the map (how many key-value pairs?)		//used for future troubleshooting
	//cout << "Size of map:\t" << map.size() << endl;		//used for future troubleshooting
	return map;
}
//function backs up data into file: frequency.dat										
int backUpFile(map<string, int> map) {			
	
	ofstream outFS;								//declare an ofstream object: output file stream
	outFS.open("frequency.dat");				//open file attempt
	if (!outFS.is_open()) {						//print mssg if could not open, return 1, and exit function prematurely
		cout << "could not open file: frequency.dat" << endl;
		return 1;
	}
		
	for (auto const& pair : map) {				//iterate through each pair in map,  writing to backup file
		outFS << pair.first << ": " << pair.second << endl;
	}
	outFS.close();								//close output file stream b/c done using it.
	return 0;
}
//function inputs the map, and creates a new Object Instance for each different produce fruit/veggie, adds it to a vector
vector<Produce> useMapToMkObjects(map<string,int> map) {
	Produce produceObj;							//declare a Produce object instance (calls default constructor)							
	vector <Produce> produceVector;				//declare vector to contain Produce instances: produceVector
	
												//for-loop to iterate through map, creating an instance for each type 
	for (auto i = map.begin(); i != map.end(); i++){
		produceObj = Produce(i->first, i->second); //call Produce constructor to make a new Produce item
												   //NOTE: next 2 lines are for future troubleshooting
		//cout << "produceObj:\t" << produceObj.getName() << "\t\tamt:\t " << produceObj.getNum() << endl;
		//add this produce item to the end of vector of Produce items.
		produceVector.push_back(produceObj);	   //use push_back to add each new Produce instance to produceVector
	}
	return produceVector;
}
//______________________________main:_set-up__________________________________________________________________________

int main() {
	vector <Produce> produceVector;			//declare vector to contain Produce class instances
	int vectorSize;							//vector contains each type of fruit/veg produce item
	string searchItem;
	char userInput;							//****NOTE: I wasn't able to ensure the input is a SINGLE character

	map<string,int> map = populateMap();	//call populateMap() function to input data from file. ASSIGN to map
	
	backUpFile(map);						//back up the file, saving daily data into frequency.dat

	produceVector = useMapToMkObjects(map); //use map to make Produce objects, save all into produceVector
	vectorSize = produceVector.size();

	//__________________________main:_user-interaction_&_interface____________________________________________________
	cout << "Welcome." << endl;
				
	bool runs = true;						//bool: 'runs' for while-loop. will run until 'runs' is false (option 4)
	while (runs) {							//WHILE loop until input = '4' ****should I EVER have it end? runs indef'ly.
		try {								//try-throw-catch input validation 
			introMssg();					//output intro message detailing four options
			cin >> userInput;				//input user character ****I was unable to ensure this was a SINGLE char
			if ((cin.fail() == true) || !(userInput == '1' || userInput == '2' || userInput == '3' || userInput == '4')) {
				cout << "throwing exception" << endl;
				throw runtime_error("Invalid choice");
			}								//throw runtime_error exception if cin.fail or input isn't 1, 2, 3, or 4

			switch (userInput) {			//switch case statement to organize four cases
			case '1':						//user enters word, use map.find until map.end, to search for a match
				cout << "Enter produce item you'd like to search:\t";
				cin >> searchItem;
				if (map.find(searchItem) != map.end()) {//output key, then map[key] (which outputs corresponding value)
					cout << searchItem << "\t" << map[searchItem] << "\n" << endl;
					break;
				}
											//if get to here, no item matched.
				cout << "No such item in our records.\t";
				break;

			case '2':						//print each key:value pair in map
				cout << "Item\t\t" << "Number" << endl;
				for (auto i = map.begin(); i != map.end(); i++) {
					cout << left << setw(20) << i->first << right << i->second << endl;
				}
				break;

			case '3':										//print each key and its corresponding histogram
															//access and print each item in vector using iterator
				for (int i = 0; i < vectorSize; i++) {
					cout << left << setw(20) << produceVector.at(i).getName();
					produceVector.at(i).printHistogram();	//class instance accesses function via access operator '.'
					cout << endl;			
				}
				break;

			case '4':										//exit program
				cout << "Thank you. Come again.";
				runs = false;								//change bool 'runs' to false. this EXITS while-loop
				break;

			default:										//executes if expression doesn't match any character
				cout << "default: Please enter either: 1, 2, 3, or 4: ";
				break;										//****was this enough, should I NOT have used try/catch?
			}
		}
		
		catch (runtime_error& excpt) {						//****What would have been the ideal input validation?
			cout << "Invalid choice. Please enter either: 1, 2, 3, or 4." << endl;
			continue;
		}
		
	}

	return 0;
}