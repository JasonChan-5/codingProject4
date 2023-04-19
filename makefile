all: exec

exec: main.o
	g++ main.o BST.o Node.o -o exec

main.o: main.cpp BST.o
	g++ -c main.cpp -o main.o

BST.o: BST.cpp BST.h Node.h Node.o
	g++ -c BST.cpp -o BST.o

Node.o: Node.cpp Node.h
	g++ -c Node.cpp -o Node.o

clean:
	rm -f *.o exec

tar: clean
	tar cvvf CP4_Chan_ychan18_JasonChan-5.tar
	gzip CP4_Chan_ychan18_JasonChan-5.tar