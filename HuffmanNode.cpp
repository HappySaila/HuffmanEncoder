#include <iostream>
#include <unordered_map>
#include "HuffmanNode.h"
#include "HuffmanTree.h"

using namespace WLSGRA012;
using namespace std;

//constructors
//default constructors
HuffmanNode::HuffmanNode(char value, int freq){
	this->value = value;
	this->freq = freq;

}

HuffmanNode::HuffmanNode(HuffmanNode left, HuffmanNode right){
	freq = left.freq + right.freq;
	value = 0;

	this->left = make_shared<HuffmanNode>(left);
	this->right = make_shared<HuffmanNode>(right);
}


//destructor
HuffmanNode::~HuffmanNode(){
	// cout << "node deleted" << endl;
}

//methods
bool HuffmanNode::operator< (const HuffmanNode & node) const{
	return freq > node.freq;
}

void HuffmanNode::PrintData() const{
	if (value=='\n'){
		cout << "New Line-" << freq << endl;
	} else if (value == ' '){
		cout << "Space-" << freq << endl;
	} else {
		cout << value << "-" << freq << endl;
	}
}

void HuffmanNode::SetCode(string code, std::unordered_map<char, std::string> & encoder){
	this->code = code;
 
	if (left != nullptr){
		//node has a left node
		//set the left node with code+=1
		left->SetCode(code + '0', encoder);
	}

	if (right != nullptr){
		//node has a right node
		//set the right node with code+=0
		right->SetCode(code + '1', encoder);
	} 

	if (left == nullptr && right == nullptr) {
		encoder[value] = code;
	}
}

