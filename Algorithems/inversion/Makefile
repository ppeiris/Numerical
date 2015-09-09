CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFALGS = -Wall $(DEBUG)
BIN = bin

$(shell mkdir -p $(BIN))

# DATA_FILE1 = IntegerArray.txt
DATA_FILE1 = smallInversions.txt


all: inversion

inversion: inversion.o
	$(CC) inversion.o -o $(BIN)/inversion

inversion.o: inversion.C
	$(CC) $(CFLAGS) inversion.C


$(shell cp $(DATA_FILE1) $(BIN))

clean:
	\rm -rf bin *.o *~ inversion
