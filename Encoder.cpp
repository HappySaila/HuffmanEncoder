#include <iostream>
#include <unordered_map>
#include "Encoder.h"

using namespace WLSGRA012;
using namespace std;

void Encoder::Encode(char c, string code){
	cout << c << " " << code << endl;
}

Encoder::Encoder(){
	// Encoder::Instance = this;
}