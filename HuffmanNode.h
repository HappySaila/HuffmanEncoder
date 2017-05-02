#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <iostream>


namespace WLSGRA012{

	class HuffmanNode{
		private:
			std::string code;
			char value;
			HuffmanNode* left;
			HuffmanNode* right;
		public:
			//constructor
			HuffmanNode(char value, int freq);
			HuffmanNode(char value, int freq, HuffmanNode left, HuffmanNode right);
			~HuffmanNode();

			//variables
			int freq;

			void PrintData() const;

			//methods
			bool operator< (const HuffmanNode & node) const;
	};

}

#endif