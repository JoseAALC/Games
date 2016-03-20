
CFLAGS = -g -std=c++11

all:main.o State.o
	$(CXX) $(CFLAGS) $? 

main.o: main.cpp 
	$(CXX) -c $(CFLAGS) $?

hello.o: State.cpp
	$(CXX) -c $(CFLAGS) $?  

