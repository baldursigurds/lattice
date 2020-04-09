DESTDIR=/usr
bindir=/bin
mandir=/share/man

all: lattice.c if.h if.c
	cc -g -Wall if.c lattice.c -o lattice -llatco

install:
	install lattice $(DESTDIR)$(bindir)/lattice
	install man1/lattice.1 $(DESTDIR)$(mandir)/man1/lattice.1
