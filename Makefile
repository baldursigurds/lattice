all: lattice.c aux.h aux.c
	cc -g aux.c lattice.c -o lattice
