#include <iostream>
#include "HuffmanNode.h"

using namespace WLSGRA012;
using namespace std;

HuffmanNode::HuffmanNode(char value, int freq){
	this->value = value;
	this->freq = freq;
}

HuffmanNode::HuffmanNode(char value, int freq, HuffmanNode left, HuffmanNode right){
}

HuffmanNode::~HuffmanNode(){
	// cout << "node deleted" << endl;
}

bool HuffmanNode::operator< (const HuffmanNode & node) const{
	return freq < node.freq;
}

void HuffmanNode::PrintData() const{
	if (value.equals("\n")){
		cout << "New Line-" << freq << endl;
	} else if (value.equals(" ")){
		cout <<"Space-" << freq << endl;
	} else {
		cout << value << "-" << freq << endl;
	}
}
