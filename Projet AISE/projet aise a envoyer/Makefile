CC? = gcc

 CFLAGS = -fPIC -Wall -O2
 LDFLAGS = -shared
  RM = rm -f



config : notrebib.h
	mkdir -p ./build
	mkdir -p ./build
	cp -r inclut ./build

lib : config  lib.c
	$ ( CC ) -shared -fPIC -o build /libtest.so lib.c -ldl

prog : main.c setup
	$ ( CC ) -o build / test $ <

exécuter : lib prog
	LD_LIBRARY_PATH =. / Build test
	LD_PRELOAD =. / Build /libtest.so ./build/test

propre :
	rm -rf build / *
