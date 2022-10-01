
s: node.o stack.o stacktest.o
	g++ node.o stack.o stacktest.o -o s

node.o: node.cpp node.hpp
	g++ -c node.cpp -o node.o

stack.o: stack.cpp stack.hpp
	g++ -c stack.cpp -o stack.o

stacktest.o: StackTest.cpp
	g++ -c StackTest.cpp -o stacktest.o

run:
	./s

clean:
	rm s *.o
