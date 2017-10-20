all: listfxns.o main.o
	gcc -o music listfxns.o main.o

listfxns.o: listfxns.c listfxns.h
	gcc -c listfxns.c

main.o: main.c listfxns.h
	gcc -c main.c

clean:
	rm *.o
	rm *~

run: all
	./music
