#include <iostream>
#include <fstream>
#include <unordered_map>

#include "HuffmanNode.h"
#include "HuffmanTree.h"

using namespace std;
using namespace WLSGRA012;

int main(int argc, char const *argv[])
{
	HuffmanTree m(argv[1], argv[2]);
	m.CreateTree();
	m.GetCodeTable();
	m.EncodeInput();
	m.WriteOutput();
	m.DecodeOutput();
}