CC=clang++
CFLAGS=-Wall -Wextra -Wpedantic -g
BIN=./bin
OBJ=./ignore/obj
CH1=1.10
CH2=2.1 2.5 2.13
CH3=3.1 3.3 3.5 3.7 3.10 3.13 3.17
CH4=4.10 4.14 4.16
CH5=5.1 5.2 5.5 5.6 5.7 5.11 5.13 5.14 5.18
CH6=6.13 6.14 6.18 6.19 6.20 6.21 6.22 6.23 6.24 6.26
CH7=7.3 7.4 7.5 7.8 7.9 7.10 7.11 7.12 7.13 7.17 7.18 7.20 7.24 7.25
CH8=8.4 8.6 8.7 8.10 8.13 8.14 8.17 sml ol_extr_op
CH9=9.3
TARGET= $(CH1) $(CH2) $(CH3) $(CH4) $(CH5) $(CH6) $(CH7) $(CH8)

all: $(TARGET)

# Chapter 1

1.10: ch1/1.10.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

# Chapter 2

2.1: ch2/2.1.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

2.5: ch2/2.5.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

2.13: ch2/2.13.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

# Chapter 3

3.1: ch3/3.1.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

3.3: ch3/3.3.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

3.5: ch3/3.5.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

3.7: ch3/3.7.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

3.10: ch3/3.10_main.cpp ch3/3.9_GradeBook.h
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

3.13: ch3/3.13_main.cpp ch3/3.12_GradeBook.o
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< $(OBJ)/3.12_GradeBook.o

3.12_GradeBook.o: ch3/3.12_GradeBook.cpp 3.11_GradeBook.h
	$(CC) -c $< -o $(OBJ)/$@

3.17: ch3/3.17_main.cpp ch3/3.16_GradeBook.cpp ch3/3.15_GradeBook.h
	$(CC) -c ch3/3.16_GradeBook.cpp -o $(OBJ)/3.16_GradeBook.o
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< $(OBJ)/3.16_GradeBook.o

# Chapter 4

4.10: ch4/4.10_main.cpp ch4/4.9_GradeBook.cpp ch4/4.8_GradeBook.h
	$(CC) -c ch4/4.9_GradeBook.cpp -o $(OBJ)/4.9_GradeBook.o
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< $(OBJ)/4.9_GradeBook.o

4.14: ch4/4.14_main.cpp ch4/4.13_GradeBook.cpp ch4/4.12_GradeBook.h
	$(CC) -c ch4/4.13_GradeBook.cpp -o $(OBJ)/4.13_GradeBook.o
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< $(OBJ)/4.13_GradeBook.o

4.16: ch4/4.16.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

# Chapter 5

5.1: ch5/5.1.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

5.2: ch5/5.2.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

5.5: ch5/5.5.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

5.6: ch5/5.6.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

5.7: ch5/5.7.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

5.11: ch5/5.11_main.cpp ch5/5.10_GradeBook.cpp ch5/5.9_GradeBook.h
	$(CC) -c ch5/5.10_GradeBook.cpp -o $(OBJ)/5.10_GradeBook.o
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< $(OBJ)/5.10_GradeBook.o

5.13: ch5/5.13.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

5.14: ch5/5.14.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

5.18: ch5/5.18.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

6.13: ch6/6.13.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

6.14: ch6/6.14.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

6.18: ch6/6.18.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

6.19: ch6/6.19.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

6.20: ch6/6.20.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

6.21: ch6/6.21.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^
	$(BIN)/$@

6.22: ch6/6.22.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^
	$(BIN)/$@

6.23: ch6/6.23.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^
	$(BIN)/$@

6.24: ch6/6.24.cpp
	$(CC) $(CFLAGS) -c -o $(BIN)/$@.o $^
	nm $(BIN)/$@.o

6.26: ch6/6.26_maximum.cpp ch6/6.25_maximum.h
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

7.3: ch7/7.3.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

7.4: ch7/7.4.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

7.5: ch7/7.5.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

# 7.6_and_7.7: ch7/7.6_and_7.7.cpp
# 	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

7.8: ch7/7.8.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

7.9: ch7/7.9.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

7.10: ch7/7.10.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

7.11: ch7/7.11.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

7.12: ch7/7.12.cpp
	$(CC) -o $(OBJ)/$@.o -c  $<
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

7.13: ch7/7.13.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

7.17: ch7/7.17_main.cpp ch7/7.16_GradeBook.cpp ch7/7.15_GradeBook.h
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< ch7/7.16_GradeBook.cpp

7.18: ch7/7.18.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

7.20: ch7/7.20.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

7.24: ch7/7.24_main.cpp ch7/7.23_GradeBook.cpp ch7/7.22_GradeBook.h
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< ch7/7.23_GradeBook.cpp

7.25: ch7/7.25.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

8.4: ch8/8.4.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

8.6: ch8/8.6.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

8.7: ch8/8.7.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

8.10: ch8/8.10&8.11&8.12.cpp
	printf "%s\n" "8.10 & 8.11 & 8.12 are not supposed to be compiled"

8.13: ch8/8.13.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

8.14: ch8/8.14.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

8.17: ch8/8.17.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

sml: ch8/sml.cpp ch8/simpletron.cpp ch8/simpletron.h
	$(CC) $(CFLAGS) -c -o $(OBJ)/simpletron.o ch8/simpletron.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< $(OBJ)/simpletron.o
	clear
	$(BIN)/sml

ol_extr_op: ch8/overloaded_extraction_operator.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

9.3: ch9/9.3_main.cpp ch9/9.2_Time.cpp ch9/9.1_Time.h
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< ch9/9.2_Time.cpp

# Other

clean:
	rm -fr $(BIN)/*
