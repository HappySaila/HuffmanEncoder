#include <iostream>
#include <fstream>
#include <unordered_map>

#include "HuffmanTree.h"
#include "HuffmanNode.h"

using namespace WLSGRA012;
using namespace std;


//##################################################################################
//constructors 
//##################################################################################

HuffmanTree::HuffmanTree(string inputFile, string outputFile){
	//set the input and output files
	this->inputFile = inputFile;
	this->outputFile = outputFile;

	//read data into the map
	ReadData();
}


HuffmanTree::~HuffmanTree(){
	cout << "tree destroyed" << endl;
}

//##################################################################################
//methods
//##################################################################################

void HuffmanTree::CreateTree(){
	//will create the tree using the data from the map
	CreatePriorityQueue();
}

void HuffmanTree::CreatePriorityQueue(){
	cout << "Creating priority queue" << endl;
	priority_queue<HuffmanNode> queue;

	for (it=map.begin(); it != map.end(); it++)
	{
		//create huffman node and put it in the queue
		HuffmanNode node(it->first, it->second);
		queue.push(node);
	}

	for (int i = 0; i < map.size(); ++i)
	{
		queue.top().PrintData();
		queue.pop();
	}
}

void HuffmanTree::ReadData(){
	//will read data from input.txt and add them to the map
	fstream fileIn(inputFile, fstream::in);
	char ch;
	while(fileIn >> noskipws >> ch){
		map[ch] = map[ch] + 1;
	}
}

void HuffmanTree::WriteData(){
	//will write data from the map to output.txt
	fstream fileOut(outputFile, fstream::out);

	for (it=map.begin(); it != map.end(); it++)
	{
		fileOut << it->first << " " << it->second << endl;
	}

	fileOut.close();
}

void HuffmanTree::GetData(){
	//will print out the data in the map
	for (it=map.begin(); it != map.end(); it++)
	{
		cout << it->first;
		cout << it->second << endl;
	}
}