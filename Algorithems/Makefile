CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFALGS = -Wall $(DEBUG)
BIN = bin

$(shell mkdir -p $(BIN))

DATA_FILE1 = IntegerArray.txt
DATA_FILE2 = smallNumbers.txt

all: divideconquer mergesort linklistmergesort

divideconquer: divideconquer.o
	$(CC) divideconquer.o -o $(BIN)/divideconquer

divideconquer.o: divideconquer.C
	$(CC) $(CFLAGS) divideconquer.C

mergesort: mergesort.o
	$(CC) mergesort.o -o $(BIN)/mergesort

mergesort.o: mergesort.C
	$(CC) $(CFLAGS) mergesort.C

linklistmergesort: linklistmergesort.o
	$(CC) linklistmergesort.o -o $(BIN)/linklistmergesort

linklistmergesort.o: linklistmergesort.C
	$(CC) $(CFLAGS) linklistmergesort.C

$(shell cp $(DATA_FILE1) $(BIN))
$(shell cp $(DATA_FILE2) $(BIN))

clean:
	\rm -rf bin *.o *~ divideconquer
