#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <iostream>
#include <unordered_map>
#include <fstream>
#include <queue>

#include "HuffmanNode.h"


namespace WLSGRA012{
	class HuffmanTree{
		private:
			std::string inputFile;	
			std::string outputFile;
			std::string outputString;

			std::unordered_map<char, int> map;
			std::unordered_map<char, int>::iterator it;
			std::priority_queue<HuffmanNode> queue;
		public:
			HuffmanTree(std::string inputFile, std::string outputFile);
			~HuffmanTree();
			void CreateTree();
			void GenerateTree();
			void CreatePriorityQueue();
			void GetData();
			void GetCodeTable();
			void PrintQueue();
			void ReadData();
			void WriteData();
			void PrintEncoderMap();
			void EncodeInput();
			void WriteOutput();
			void DecodeOutput();

			std::unordered_map<char, std::string> encoder;
			std::unordered_map<char, std::string>::iterator encoderIt;
			std::shared_ptr<HuffmanNode> root;

	};
}

#endif