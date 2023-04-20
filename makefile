all: exec

exec: main.o
	g++ -Wall -Wextra -O3 main.o BST.o Node.o -o exec

main.o: main.cpp BST.o
	g++ -Wall -Wextra -O3 -c main.cpp -o main.o

BST.o: BST.cpp BST.h Node.h Node.o
	g++ -Wall -Wextra -O3 -c BST.cpp -o BST.o

Node.o: Node.cpp Node.h
	g++ -Wall -Wextra -O3 -c Node.cpp -o Node.o

clean:
	rm -f *.o *.tar.gz exec

tar: clean
	tar cvvf CP4_Chan_ychan18_JasonChan-5.tar .
	gzip CP4_Chan_ychan18_JasonChan-5.tar