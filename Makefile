PREFIX?= /usr
BINDIR?= $(PREFIX)/bin

CFLAGS+= -Wall
LDADD+= -lX11 
LDFLAGS=
EXEC=lumen

CC=gcc

all: $(EXEC)

lumen: lumen.o
	$(CC) $(LDFLAGS) -Os -o $@ $+ $(LDADD)

install: all
	install -Dm 755 lumen $(DESTDIR)$(BINDIR)/lumen

clean:
	rm -f lumen lumen.o
