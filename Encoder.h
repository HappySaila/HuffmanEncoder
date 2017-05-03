#ifndef ENCODER_H
#define ENCODER_H

#include <iostream>
#include <unordered_map>

namespace WLSGRA012{

	class Encoder{
		private:
		public:
			//constructor
			Encoder();
			//variables
			static std::unordered_map<char, std::string> map;

			static void Encode(char c, std::string code);
			static Encoder* Instance;
	};
}

#endif