IDIR=inc
CC=g++
CFLAGS=-I$(IDIR) -g

ODIR=obj
BIN=bin
SDIR=src

_DEPS =
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

_OBJ = hex2base64.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

all: $(BIN)/hex2base64

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BIN)/hex2base64: $(OBJ)
	$(CC) -g -o $@ $^

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~
	rm -rf *.dSYM