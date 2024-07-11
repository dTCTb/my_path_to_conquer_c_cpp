CC=clang++
CFLAGS=-Wall -g
BIN=./bin
OBJ=./ignore/obj
CH1=1.10
CH2=2.1 2.5 2.13
CH3=3.1 3.3 3.5 3.7 3.10 3.13 3.17
CH4=4.10 4.14 4.16
CH5=5.1 5.2 5.5 5.6 5.7 5.11 5.13 5.14 5.18
CH6=6.19
TARGET= $(CH1) $(CH2) $(CH3) $(CH4) $(CH5) $(CH6)

all: $(TARGET)

# Chapter 1

1.10: 1.10.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

# Chapter 2

2.1: 2.1.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

2.5: 2.5.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

2.13: 2.13.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

3.1: 3.1.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

# Chapter 3

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

# Chapter 4

4.10: 4.10_main.cpp 4.9_GradeBook.cpp 4.8_GradeBook.h
	$(CC) -c 4.9_GradeBook.cpp -o $(OBJ)/4.9_GradeBook.o
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< $(OBJ)/4.9_GradeBook.o

4.14: 4.14_main.cpp 4.13_GradeBook.cpp 4.12_GradeBook.h
	$(CC) -c 4.13_GradeBook.cpp -o $(OBJ)/4.13_GradeBook.o
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< $(OBJ)/4.13_GradeBook.o

4.16: 4.16.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

# Chapter 5

5.1: 5.1.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

5.2: 5.2.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

5.5: 5.5.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

5.6: 5.6.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

5.7: 5.7.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

5.11: 5.11_main.cpp 5.10_GradeBook.cpp 5.9_GradeBook.h
	$(CC) -c 5.10_GradeBook.cpp -o $(OBJ)/5.10_GradeBook.o
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< $(OBJ)/5.10_GradeBook.o

5.13: 5.13.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

5.14: 5.14.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

5.18: 5.18.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

6.19: 6.19.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

# Other

clean:
	rm -fr $(BIN)/$(TARGET) *.dSYM $(BIN)/*.dSYM
