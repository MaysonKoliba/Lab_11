#include "..\\Lab11\Hash.h"
#include <iostream>
#include <chrono>
#include <string>
typedef std::chrono::high_resolution_clock Clock;
using namespace std;

int main()
{
	string inputLine = "";
	string outputLine = "";
	Node* output = nullptr;
	int input = 0;

	Hash userHash(10);

	while (input != 6) {
		cout << "Press 1 to add an item to the hash table" << endl;
		cout << "Press 2 remove an item from the hash table" << endl;
		cout << "Press 3 to find an item in the hash table" << endl;
		cout << "Press 4 to get the length of the hash table" << endl;
		cout << "Press 5 to print the hash table" << endl;
		cout << "Press 6 to quit" << endl;

		getline(cin, inputLine);
		input = stoi(inputLine);

		switch (input)
		{
		case 1:

			output = userHash.addItem();

			if(output != nullptr){ 
				cout << "<< Adding item! >>" << endl; 
			}
			else {
				cout << "<< Can't add any more items! >>" << endl;
			}
			
			break;

		case 2:
			cout << "Enter the index of the item that you would like to remove" << endl;
			cin >> input;

			output = userHash.removeItem(input);

			if (output != nullptr) {
				cout << "<< Item removed! >>" << endl << endl;
			}
			else {
				cout << "<< You can't remove that item! >>" << endl << endl;
			}
			cin.ignore();
			break;

		case 3:
			cout << "Enter the index of the item that you would like to find" << endl;
			cin >> input;

			output = userHash.getItem(input);

			if (output != nullptr) {
				cout << "<< Item found! >>" << endl << endl;
			}
			else {
				cout << "<< Item not found! >>" << endl << endl;
			}
			cin.ignore();
			break;

		case 4:
			input = userHash.getLength();
			cout << "<< The length of the hash table is " << input << " >>" << endl;
			break;

		case 5:
			cout << "<< Printing table... >>" << endl;
			outputLine = userHash.printTable();
			cout << outputLine << endl;
			break;

		case 6:
			cout << "<< Quiting... >>" << endl;
			break;
		}
	}


	Hash test500(500);
	Hash test1000(1000);
	Hash test2000(2000);
	Hash test5000(5000);

	auto t1 = Clock::now();
	for (int i = 0; i < 500; i++) { test500.addItem(); }
	auto t2 = Clock::now();

	cout << "Hash table 500: "
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
		<< " nanoseconds" << std::endl;

	auto t3 = Clock::now();
	for (int i = 0; i < 1000; i++) { test1000.addItem(); }
	auto t4 = Clock::now();

	cout << "Hash Table 1000: "
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(t4 - t3).count()
		<< " nanoseconds" << std::endl;
    
	auto t5 = Clock::now();
	for (int i = 0; i < 2000; i++) { test2000.addItem(); }
	auto t6 = Clock::now();

	cout << "Hash Table 2000: "
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(t6 - t5).count()
		<< " nanoseconds" << std::endl;

	auto t7 = Clock::now();
	for (int i = 0; i < 5000; i++) { test5000.addItem(); }
	auto t8 = Clock::now();

	cout << "Hash Table 5000: "
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(t8 - t7).count()
		<< " nanoseconds" << std::endl;

	return 0;
}