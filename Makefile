CC=clang++
CFLAGS=-Wall -g
BIN=./bin
1.10: 1.10.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

clean:
	rm -fr $(BIN)/$(TARGET) *.dSYM $(BIN)/*.dSYM
