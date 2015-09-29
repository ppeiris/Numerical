CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFALGS = -Wall $(DEBUG)
BIN = bin

$(shell mkdir -p $(BIN))

DATA_FILE1 = data.txt

all: comparisons

comparisons: comparisons.o
	$(CC) comparisons.o -o $(BIN)/comparisons

comparisons.o: comparisons.C
	$(CC) $(CFLAGS) comparisons.C


$(shell cp $(DATA_FILE1) $(BIN))

clean:
	\rm -rf bin *.o *~ comparisons
