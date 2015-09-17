CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFALGS = -Wall $(DEBUG)
BIN = bin

$(shell mkdir -p $(BIN))

DATA_FILE1 = IntegerArray.txt
DATA_FILE2 = smallNumbers.txt

all: quicksort

quicksort: quicksort.o
	$(CC) quicksort.o -o $(BIN)/quicksort

quicksort.o: quicksort.C
	$(CC) $(CFLAGS) quicksort.C

$(shell cp ../$(DATA_FILE1) $(BIN))
$(shell cp ../$(DATA_FILE2) $(BIN))

clean:
	\rm -rf bin *.o *~quicksort
