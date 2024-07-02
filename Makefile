CC=clang++
CFLAGS=-Wall -g
BIN=./bin
TARGET= 1.10 2.1 2.5 2.13 3.1 3.3 3.5

all: $(TARGET)

1.10: 1.10.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

2.1: 2.1.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

2.5: 2.5.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

2.13: 2.13.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

3.1: 3.1.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

3.3: 3.3.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

3.5: 3.5.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

clean:
	rm -fr $(BIN)/$(TARGET) *.dSYM $(BIN)/*.dSYM
