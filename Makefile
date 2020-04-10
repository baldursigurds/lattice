DESTDIR=/usr
bindir=/bin
mandir=/share/man

all: lattice.c if.h if.c
	cc -g -Wall if.c lattice.c -o lattice -llatco

install:
	mkdir -p $(DESTDIR)$(bindir)
	install lattice $(DESTDIR)$(bindir)/lattice
	mkdir -p $(DESTDIR)$(mandir)/man1
	install man1/lattice.1 $(DESTDIR)$(mandir)/man1/lattice.1
