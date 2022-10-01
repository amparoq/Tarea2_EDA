
s: node.o stack.o html_check.o
	g++ node.o stack.o html_check.o -o s

node.o: node.cpp node.hpp
	g++ -c node.cpp -o node.o

stack.o: stack.cpp stack.hpp
	g++ -c stack.cpp -o stack.o

html_check.o: html_check.cpp
	g++ -c -std=c++11 html_check.cpp -o html_check.o

run:
	./s

clean:
	rm *.o s