IDIR=../../Lib/inc
CC=g++

LIBDIR=../../Lib/lib
LIB=crypto


CFLAGS=-std=c++11 -I$(IDIR)
LIBFLAGS=-L$(LIBDIR) -l$(LIB)

ODIR=obj
BIN=bin
SDIR=src

_DEPS = crypto.h
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

_OBJ = fixed_xor.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

all: $(BIN)/fixed_xor

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS) | $(ODIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR):
	mkdir -p $@

$(BIN)/fixed_xor: $(OBJ) libcrypto | $(BIN)
	$(CC) -g -o $@ $< $(CFLAGS) $(LIBFLAGS)

$(BIN):
	mkdir -p $@

.PHONY: clean libcrypto

libcrypto:
	$(MAKE) -C ../../Lib crypto

clean:
	rm -f $(ODIR)/*.o *~
