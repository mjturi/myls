CXX = g++ 
CXXFLAGS += -std=c++11 

myls : myls.o 
	$(CXX) myls.o -o myls

myls.o : myls.cpp
	$(CXX) $(CXXFLAGS) -c myls.cpp

clean :
	rm *.o
