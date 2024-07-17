CC=clang++
CFLAGS=-Wall -g
BIN=./bin
OBJ=./$(BIN)/obj
MY=my_merge_sort my_quick_sort
TARGET= $(MY)

all: $(TARGET)

my_merge_sort: my_merge_sort.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

my_quick_sort: quick_sort.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

# Other

clean:
	rm -fr $(BIN)/*
