IDIR=../../Lib/inc
CC=g++

LIBDIR=../../Lib/lib
LIB=encodings


CFLAGS=-I$(IDIR)
LIBFLAGS=-L$(LIBDIR) -l$(LIB)

ODIR=obj
BIN=bin
SDIR=src

_DEPS = encodings.h
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

_OBJ = hex2base64.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

all: $(BIN)/hex2base64

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BIN)/hex2base64: $(OBJ) libencodings
	$(CC) -g -o $@ $< $(CFLAGS) $(LIBFLAGS)

.PHONY: clean libencodings

libencodings:
	$(MAKE) -C ../../Lib libencodings

clean:
	rm -f $(ODIR)/*.o *~