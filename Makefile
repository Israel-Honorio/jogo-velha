all: testa_velha.cpp velha.cpp velha.hpp velha.o
	g++ -std=c++11 -Wall velha.o testa_velha.cpp -o testa_velha
	./testa_velha

compile: testa_velha.cpp velha.cpp velha.hpp velha.o
	g++ -std=c++11 -Wall velha.o testa_velha.cpp -o testa_velha
	
test: testa_velha	
	./testa_velha
	
cpplint: testa_velha.cpp velha.cpp velha.hpp
	cpplint --filter=-legal/copyright testa_velha.cpp velha.cpp velha.hpp
	
gcov: testa_velha.cpp velha.cpp velha.hpp 
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage -c velha.cpp
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage velha.o testa_velha.cpp -o testa_velha
	./testa_velha
	gcov *.cpp	
	
debug: testa_velha.cpp velha.cpp velha.hpp 
	g++ -std=c++11 -Wall -g -c velha.cpp
	g++ -std=c++11 -Wall -g velha.o testa_velha.cpp -o testa_velha
	gdb testa_velha
	
cppcheck: testa_velha.cpp velha.cpp velha.hpp
	cppcheck --enable=warning . 

valgrind: testa_velha
	valgrind --leak-check=yes --log-file=valgrind.rpt testa_velha

velha.o: velha.cpp velha.hpp
	g++ -std=c++11 -Wall -c velha.cpp
	
testa_velha: testa_velha.cpp velha.cpp velha.hpp velha.o
	g++ -std=c++11 -Wall velha.o testa_velha.cpp -o testa_velha

clean:
	rm -rf *.o *.exe *.gc* testa_velha