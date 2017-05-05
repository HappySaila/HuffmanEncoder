#include <iostream>
#include <fstream>
#include <unordered_map>

#include "HuffmanNode.h"
#include "HuffmanTree.h"
#include "cstdlib"

using namespace std;
using namespace WLSGRA012;

int main(int argc, char const *argv[])
{
	system("clear");
	HuffmanTree m(argv[1], argv[2]);
	m.CreateTree();
	cout << endl;
	m.GetCodeTable();
	cout << endl;
	m.EncodeInput();
	cout << endl;
	m.WriteOutput();
	cout << endl;
	m.DecodeOutput();
	cout << endl;

}