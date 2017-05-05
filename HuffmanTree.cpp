#include <iostream>
#include <fstream>
#include <unordered_map>
#include <sstream>

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


//copy constructor
//copy assignment
//move constructor
//move constructor
HuffmanTree::HuffmanTree(HuffmanTree &&tree) : inputFile(tree.inputFile), outputFile(tree.outputFile), outputString(tree.outputString),
	map(tree.map), queue(tree.queue), it(tree.it), encoder(tree.encoder), encoderIt(tree.encoderIt){
	root = std::move(tree.root);
}

//##################################################################################
//methods
//##################################################################################

void HuffmanTree::CreateTree(){
	//will create the tree using the data from the map
	CreatePriorityQueue();

	//will keeping creating nodes until there is on tree left - the huffman tree
	GenerateTree();
}

void HuffmanTree::CreatePriorityQueue(){
	//create a priority queue into the variable queue
	cout << "Creating priority queue..." << endl;
	// priority_queue<HuffmanNode> queue;

	for (it=map.begin(); it != map.end(); it++)
	{
		//create huffman node and put it in the queue
		shared_ptr<HuffmanNode> node(new HuffmanNode(it->first, it->second));
		queue.push(*node.get());
	}

	
}

void HuffmanTree::GenerateTree(){
	//will keeping popping two nodes out of the queue and make a tree
	//the tree will be inserted back into the queue
	//will continue until there is one tree in the queue - the huffman tree
	cout << "Generating Tree..." << endl;

	while(queue.size() > 1){
		//get 2 lowest nodes in queue
		HuffmanNode a = queue.top();
		queue.pop();

		HuffmanNode b = queue.top();
		queue.pop();

		//create a subtree
		HuffmanNode c(a, b);

 		//push tree back onto queue
		queue.push(c);

	}

	HuffmanNode last(queue.top());
	root = make_shared<HuffmanNode>(last);


}

void HuffmanTree::GetCodeTable(){
	//will return the codes for each value
	cout << "Creating Code Table..." << endl;
	root->SetCode("", encoder);

	PrintEncoderMap();
}

void HuffmanTree::PrintEncoderMap(){
	cout << "Printing encoder map..." << endl;
	for (encoderIt = encoder.begin(); encoderIt != encoder.end(); encoderIt++)
	{
		if (encoderIt->first == ' '){
			codeTable << "[Space" << "--" << encoderIt->second << "]" << endl;
		} else if (encoderIt->first == '\n'){
			codeTable << "[New Line" << "--" << encoderIt->second << "]" << endl;
		} else {
			codeTable << "[" << encoderIt->first << "--" << encoderIt->second << "]" << endl;
		}

	}

	cout << codeTable.str() << endl;

}

void HuffmanTree::EncodeInput(){
	//will convert every char to its corrosponding byte code
	cout << "Encoding Input..." << endl;

	fstream fileIn(inputFile, fstream::in);
	char ch;
	while(fileIn >> noskipws >> ch){
		outputString += encoder[ch];
	}

	cout << outputString << endl;
}

void HuffmanTree::WriteOutput(){
	cout << "Writing output to file" << outputFile << "..." << endl;
	fstream fileOut(outputFile, fstream::out | fstream::trunc);

	stringstream s;
	if (fileOut.is_open()){
		string codeTableString = codeTable.str();

		//write the code table to the file
		fileOut << "--Code Table--" << endl << endl;
		fileOut << codeTableString << endl << endl;

		//write the binary code to a file
		fileOut << "--Encoded message--" << endl << endl;
		fileOut << outputString << endl;

	} else {
		cout << "Error writing to the file." << endl;	
	}
		
	fileOut.close();
}

void HuffmanTree::DecodeOutput(){
	cout << "Decoding output..." << endl;
	HuffmanNode current = *root.get();
	string out = "";
	outputString += "0";
	for (int i = 0; i < outputString.size(); ++i)
	{
		if (outputString[i]=='0'){
			//go left
			if (current.left != nullptr){
				//current node has a child
				current = *current.left.get();
			} else {
				//we have reached a leaf
				out += current.value;
				current = *root.get();
				i--;
			}
		} else if (outputString[i]=='1'){
			//go right
			if (current.right != nullptr){
				//current node has a child
				current = *current.right.get();
			} else {
				//ww have reached a leaf
				out += current.value;
				current = *root.get();
				i--;
			}
		}
	}

	cout << "Decoded message is..." << endl;
	cout << out << endl;
}

void HuffmanTree::PrintQueue(){
	priority_queue<HuffmanNode> t = queue;
	while (!t.empty())
	{
		t.top().PrintData();
		t.pop();
		//TODO: make sure the popped node is less than the next node that needs to be popped
	}
	cout << "------------" << endl;
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
