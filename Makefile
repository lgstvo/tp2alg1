CC=g++ # compilador, troque para gcc se preferir utilizar C
CFLAGS=-Wall -Wextra -g # compiler flags, troque o que quiser, exceto bibliotecas externas
EXEC=./tp02 # nome do executavel que sera gerado, nao troque
TMPOUT=tp02.testresult

$(EXEC): src/main.cpp Graph.o DisjointSets.o TouristicPoint.o Stretch.o
	$(CC) $(CFLAGS) src/main.cpp Graph.o DisjointSets.o TouristicPoint.o Stretch.o -o $(EXEC)
	rm -rf Graph.o
	rm -rf DisjointSets.o
	rm -rf TouristicPoint.o
	rm -rf Stretch.o

Graph.o: src/classes/Graph.cpp 
	$(CC) $(CFLAGS) -c src/classes/Graph.cpp  -o Graph.o

DisjointSets.o: src/classes/DisjointSets.cpp
	$(CC) $(CFLAGS) -c src/classes/DisjointSets.cpp -o DisjointSets.o

TouristicPoint.o: src/classes/TouristicPoint.cpp 
	$(CC) $(CFLAGS) -c src/classes/TouristicPoint.cpp  -o TouristicPoint.o

Stretch.o: src/classes/Stretch.cpp 
	$(CC) $(CFLAGS) -c src/classes/Stretch.cpp  -o Stretch.o

test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf TouristicPoint.o
	rm -rf Graph.o
	rm -rf DisjointSets.o
	rm -rf Stretch.o
	rm -rf tp02
	
