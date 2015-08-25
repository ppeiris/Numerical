CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFALGS = -Wall $(DEBUG)
BIN = bin

$(shell mkdir -p $(BIN))

FILE_NAME1 = divideconquer
DATA_FILE1 = IntegerArray.txt



all: $(FILE_NAME1)

$(FILE_NAME1): $(FILE_NAME1)
	$(CC) $(LFLAGS) $(OBJS) -o $(FILE_NAME1)

$(FILE_NAME1).o: $(FILE_NAME1).C
	$(CC) $(CFLAGS) $(FILE_NAME1).C



#FILE_NAME2 = inversion
#inversion: $(OBJS2)
#	$(CC) $(LFLAGS) $(OBJS2) -o $(BIN)/inversion

#inversion.o: inversion.C
#	$(CC) $(CFLAGS) inversion.C


#$(shell mv )

#$(shell cp $(DATA_FILES) $(BIN))

clean:
	\rm -rf bin *.o *~ divideconquer
