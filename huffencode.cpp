#include <iostream>
#include <fstream>
#include <unordered_map>

#include "HuffmanNode.h"

void readData();
void writeData();
void getData();

using namespace std;
using namespace WLSGRA012;
string inputFile;
string outputFile;
unordered_map<char, int> map;
unordered_map<char, int>::iterator it;



int main(int argc, char const *argv[])
{
	inputFile = argv[1];
	outputFile = argv[2];

	HuffmanNode n;
	// readData();
	// writeData();
	// getData();
}

void readData(){
	//will read data from input.txt and add them to the map
	fstream fileIn(inputFile, fstream::in);
	char ch;
	while(fileIn >> noskipws >> ch){
		map[ch] = map[ch] + 1;
	}
}

void writeData(){
	//will write data from the map to output.txt
	fstream fileOut(outputFile, fstream::out);

	for (it=map.begin(); it != map.end(); it++)
	{
		fileOut << it->first << " " << it->second << endl;
	}

	fileOut.close();
}

void getData(){
	//will print out the data in the map
	for (it=map.begin(); it != map.end(); it++)
	{
		cout << it->first;
		cout << it->second << endl;
	}
}