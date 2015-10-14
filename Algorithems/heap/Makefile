CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFALGS = -Wall $(DEBUG)
BIN = bin

$(shell mkdir -p $(BIN))

DATA_FILE1 = IntegerArray.txt
# DATA_FILE1 = smallheaparrays.txt


all: heaparray maxpriorityqueue

heaparray: heaparray.o
	$(CC) heaparray.o -o $(BIN)/heaparray

heaparray.o: heaparray.C
	$(CC) $(CFLAGS) heaparray.C

maxpriorityqueue: maxpriorityqueue.o
	$(CC) maxpriorityqueue.o -o $(BIN)/maxpriorityqueue

maxpriorityqueue.o: maxpriorityqueue.C
	$(CC) $(CFLAGS) maxpriorityqueue.C

$(shell cp $(DATA_FILE1) $(BIN))

clean:
	\rm -rf bin *.o *~heaparray
