CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFALGS = -Wall $(DEBUG)
BIN = bin

$(shell mkdir -p $(BIN))

# DATA_FILE1 = IntegerArray.txt
DATA_FILE1 = points.txt


all: closestpair

closestpair: closestpair.o
	$(CC) closestpair.o -o $(BIN)/closestpair

closestpair.o: closestpair.C
	$(CC) $(CFLAGS) closestpair.C


$(shell cp $(DATA_FILE1) $(BIN))

clean:
	\rm -rf bin *.o *~ closestpair
