IDIR=inc
CC=g++
CFLAGS=-I$(IDIR)

ODIR=obj
LIB=lib
SDIR=src

_DEPS =
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

_OBJ = encodings.o xor.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

all: crypto

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS) | $(ODIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR):
	mkdir -p $@

$(LIB)/libcrypto.a: $(OBJ)
	ar -cvq $@ $^

.PHONY: clean crypto all

crypto: $(LIB)/libcrypto.a

clean:
	rm -f $(ODIR)/*.o *~
