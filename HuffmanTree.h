#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <iostream>
#include <unordered_map>
#include <fstream>
#include <queue>


namespace WLSGRA012{
	class HuffmanTree{
		private:
			std::string inputFile;	
			std::string outputFile;
			std::unordered_map<char, int> map;
			std::unordered_map<char, int>::iterator it;	
		public:
			HuffmanTree(std::string inputFile, std::string outputFile);
			~HuffmanTree();
			void CreateTree();
			void CreatePriorityQueue();
			void GetData();
			void ReadData();
			void WriteData();
	};
}

#endif