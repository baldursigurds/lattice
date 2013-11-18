all: lattice.c aux.h aux.c if.h if.c
	cc -g aux.c if.c lattice.c -o lattice
