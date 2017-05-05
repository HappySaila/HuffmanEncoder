go:
	g++ -std=c++11 *.cpp -c
	g++ *.o -o Driver
	./Driver input.txt output.txt
	
clean:
	rm *.o
	rm Driver


