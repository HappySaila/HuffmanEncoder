run:
	make compile
	./Driver

compile: huffencode.o HuffmanNode.o HuffmanTree.o
	g++ -o *.o Driver

huffencode.o: huffencode.cpp
	g++ -c huffencode.cpp

HuffmanNode.o: HuffmanNode.h HuffmanNode.cpp
	g++ -c HuffmanNode.cpp

HuffmanTree.o: HuffmanTree.h HuffmanTree.cpp
	g++ -c HuffmanTree.cpp

clean:
	rm *.o
	rm Driver

