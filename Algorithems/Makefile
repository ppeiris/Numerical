CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFALGS = -Wall $(DEBUG)
BIN = bin

$(shell mkdir -p $(BIN))

DATA_FILE1 = IntegerArray.txt

all: divideconquer

divideconquer: divideconquer.o
	$(CC) divideconquer.o -o divideconquer

divideconquer.o: divideconquer.C
	$(CC) $(CFLAGS) divideconquer.C


$(shell cp $(DATA_FILE1) $(BIN))

$(shell cp divideconquer $(BIN))

clean:
	\rm -rf bin *.o *~ divideconquer
