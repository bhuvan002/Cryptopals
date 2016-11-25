IDIR=inc
CC=g++
CFLAGS=-std=c++11 -I$(IDIR)

ODIR=obj
LIB=lib
SDIR=src

_DEPS =
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

_OBJ = encodings.o xor.o natural_language.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

all: crypto

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS) | $(ODIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR):
	mkdir -p $@

$(LIB)/libcrypto.a: $(OBJ) | $(LIB)
	ar -cvq $@ $^

$(LIB):
	mkdir -p $@

.PHONY: clean crypto all

crypto: $(LIB)/libcrypto.a

clean:
	rm -f $(ODIR)/*.o *~
