CC=clang++
CFLAGS=-Wall -g
BIN=./bin
OBJ=./ignore/obj
TARGET= 1.10 2.1 2.5 2.13 3.1 3.3 3.5 3.7 3.10 3.13 3.17 4.10

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

3.7: 3.7.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

3.10: 3.10_main.cpp 3.9_GradeBook.h
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

3.13: 3.13_main.cpp 3.12_GradeBook.o
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< $(OBJ)/3.12_GradeBook.o

3.12_GradeBook.o: 3.12_GradeBook.cpp 3.11_GradeBook.h
	$(CC) -c $< -o $(OBJ)/$@

3.17: 3.17_main.cpp 3.16_GradeBook.cpp 3.15_GradeBook.h
	$(CC) -c 3.16_GradeBook.cpp -o $(OBJ)/3.16_GradeBook.o
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< $(OBJ)/3.16_GradeBook.o

4.10: 4.10_main.cpp 4.9_GradeBook.cpp 4.8_GradeBook.h
	$(CC) -c 4.9_GradeBook.cpp -o $(OBJ)/4.9_GradeBook.o
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< $(OBJ)/4.9_GradeBook.o

clean:
	rm -fr $(BIN)/$(TARGET) *.dSYM $(BIN)/*.dSYM
