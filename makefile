all: listfxns.o lib.o main.o
	gcc -o music listfxns.o main.o lib.o

listfxns.o: listfxns.c listfxns.h
	gcc -c listfxns.c

lib.o: lib.c lib.h
	gcc -c lib.c

main.o: main.c listfxns.h lib.h
	gcc -c main.c

clean:
	rm *.o

run: all
	./music
