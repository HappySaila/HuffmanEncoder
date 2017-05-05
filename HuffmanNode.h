#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <iostream>
#include <memory>


namespace WLSGRA012{

	class HuffmanNode{
		private:
		public:
			//default constructors
			HuffmanNode(char value, int freq);
			HuffmanNode(HuffmanNode left, HuffmanNode right);
			//copy constructor
			HuffmanNode(const HuffmanNode &node) = default;
			//copy assignment constructor
			HuffmanNode &operator= (HuffmanNode &node) = default;
			//move constructor
			HuffmanNode (HuffmanNode &&node);
			//move assignment constructor
			HuffmanNode &operator= (HuffmanNode &&node) = default;
			//destructor
			~HuffmanNode() = default;


			//variables
			std::shared_ptr<HuffmanNode> left;
			std::shared_ptr<HuffmanNode> right;
			std::string code;
			char value;
			int freq;

			void PrintData() const;

			//methods
			bool operator< (const HuffmanNode & node) const;
			void SetCode(std::string code, std::unordered_map<char, std::string> & encoder);
	};

}

#endif