CXX=g++
target=test


$(target): binomial.o main.o
	$(CXX) binomial.o main.o -o $(target) 
main.o: main.cpp
	$(CXX) main.cpp -c
binomial.o: binomial.cpp
	$(CXX) binomial.cpp -c
clean:
	rm $(target) *.o
