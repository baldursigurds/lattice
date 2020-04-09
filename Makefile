DESTDIR=/usr
bindir=/bin

all: lattice.c if.h if.c
	cc -g -Wall if.c lattice.c -o lattice -llatco

install:
	install lattice $(DESTDIR)$(bindir)/lattice
