all: RBnode.h RBnode.cpp RBtree.h RBtree.cpp main.cpp
	g++ -std=c++11 -o main main.cpp RBtree.cpp RBnode.cpp >& err.log
RBtree: RBtee.cpp RBtree.h RBnode.h
	g++ -std=c++11 RBtree.cpp
RBnode: RBnode.cpp RBnode.h
	g++ -std=c++11 RBnode.cpp
run:
	./main >& out.log
clean:
	rm main err.log out.log