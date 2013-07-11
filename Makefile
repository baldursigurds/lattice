all: lattice.c aux.h aux.c
	cc aux.c lattice.c -o lattice
