IDIR=inc
CC=g++
CFLAGS=-I$(IDIR)

ODIR=obj
LIB=lib
SDIR=src

_DEPS =
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

_OBJ = hex2base64.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(LIB)/libencodings.a: $(ODIR)/encodings.o
	ar -cvq $@ $^

.PHONY: clean libencodings

libencodings: $(LIB)/libencodings.a

clean:
	rm -f $(ODIR)/*.o *~
