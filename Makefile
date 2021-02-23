CC=g++ # compilador, troque para gcc se preferir utilizar C
CFLAGS=-Wall -Wextra -g # compiler flags, troque o que quiser, exceto bibliotecas externas
EXEC=./tp02 # nome do executavel que sera gerado, nao troque
TMPOUT=tp02.testresult

$(EXEC): src/main.cpp Graph.o DisjointSets.o Attraction.o Edge.o EdgeSort.o
	$(CC) $(CFLAGS) src/main.cpp Graph.o DisjointSets.o Attraction.o Edge.o EdgeSort.o -o $(EXEC)
	rm -rf Graph.o
	rm -rf DisjointSets.o
	rm -rf Attraction.o
	rm -rf Edge.o
	rm -rf EdgeSort.o

Graph.o: src/classes/Graph.cpp 
	$(CC) $(CFLAGS) -c src/classes/Graph.cpp  -o Graph.o

DisjointSets.o: src/classes/DisjointSets.cpp
	$(CC) $(CFLAGS) -c src/classes/DisjointSets.cpp -o DisjointSets.o

Attraction.o: src/classes/Attraction.cpp 
	$(CC) $(CFLAGS) -c src/classes/Attraction.cpp  -o Attraction.o

Edge.o: src/classes/Edge.cpp 
	$(CC) $(CFLAGS) -c src/classes/Edge.cpp  -o Edge.o

EdgeSort.o: src/classes/EdgeSort.cpp
	$(CC) $(CFLAGS) -c src/classes/EdgeSort.cpp  -o EdgeSort.o


test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf Attraction.o
	rm -rf Graph.o
	rm -rf DisjointSets.o
	rm -rf Edge.o
	rm -rf EdgeSort.o
	rm -rf tp02
	
