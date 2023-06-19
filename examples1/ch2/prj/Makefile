# -*- Makefile -*-

#target: dependencies
#   action

all: simple tip

simple: simple.o gd.o
	clang simple.o gd.o -o simple -lm

simple.o: simple.c gd.h
	clang -c simple.c

gd.o: gd.c gd.h
	clang -c gd.c

tip: tip.o gd.o
	clang tip.o gd.o -o tip

tip.o: tip.c gd.h
	clang -c tip.c

clean:
	rm *.o simple tip
