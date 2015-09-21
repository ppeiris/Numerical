CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFALGS = -Wall $(DEBUG)
BIN = bin

$(shell mkdir -p $(BIN))

DATA_FILE2 = IntegerArray.txt
DATA_FILE1 = points.txt

all: binarytree

binarytree: binarytree.o
	$(CC) binarytree.o -o $(BIN)/binarytree

binarytree.o: binarytree.C
	$(CC) $(CFLAGS) binarytree.C

$(shell cp $(DATA_FILE2) $(BIN))
$(shell cp $(DATA_FILE1) $(BIN))

clean:
	\rm -rf bin *.o *~binarytree
