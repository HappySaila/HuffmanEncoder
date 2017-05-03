# run:
# 	make compile
# 	./Driver input.txt output.txt

# compile: huffencode.o HuffmanNode.o HuffmanTree.o
# 	g++ *.o -o Driver

# huffencode.o: huffencode.cpp
# 	g++ -c huffencode.cpp

# HuffmanNode.o: HuffmanNode.cpp HuffmanNode.h 
# 	g++ -c HuffmanNode.cpp

# HuffmanTree.o: HuffmanTree.cpp HuffmanTree.h 
# 	g++ -c HuffmanTree.cpp

clean:
	rm *.o
	rm Driver

go:
	g++ *.cpp -c
	g++ *.o -o Driver
	./Driver input.txt output.txt

