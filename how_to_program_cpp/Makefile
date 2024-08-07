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
CH9=9.3 9.6 9.9 9.12 9.15 9.16 9.21 9.22 9.23 9.26 9.29 saving_account
CH10=10.1 10.5 10.8 10.9 10.13
CH11=11.6 11.9c1 11.9c2 11.9c3 11.9c4
CH12=12.1 12.2 12.3 12.4
TARGET= $(CH1) $(CH2) $(CH3) $(CH4) $(CH5) $(CH6) $(CH7) $(CH8) $(CH9) $(CH10) $(CH11) $(CH12)

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

ol_extr_op: ch8/overloaded_extraction_operator.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

9.3: ch9/9.3_main.cpp ch9/9.2_Time.cpp ch9/9.1_Time.h
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< ch9/9.2_Time.cpp

9.6: ch9/9.6_main.cpp ch9/9.5_Time.cpp ch9/9.4_Time.h
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< ch9/9.5_Time.cpp

9.9: ch9/9.9_main.cpp ch9/9.8_CreateAndDestroy.cpp ch9/9.7_CreateAndDestroy.h
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< ch9/9.8_CreateAndDestroy.cpp

9.12: ch9/9.12_main.cpp ch9/9.11_Time.cpp ch9/9.10_Time.h
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< ch9/9.11_Time.cpp

9.15: ch9/9.13-15.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

9.16: ch9/9.16.cpp ch9/9.4_Time.h ch9/9.5_Time.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< ch9/9.5_Time.cpp
	@echo "9.16.cpp not suppose to compile as,"
	@grep error $<

9.21: ch9/9.21_main.cpp ch9/9.18_Date.cpp ch9/9.20_Employee.cpp ch9/9.17_Date.h ch9/9.19_Employee.h
	@$(CC) $(CFLAGS) -c -o $(OBJ)/9.18_Date.o ch9/9.18_Date.cpp
	@$(CC) $(CFLAGS) -c -o $(OBJ)/9.20_Employee.o ch9/9.20_Employee.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< $(OBJ)/9.18_Date.o $(OBJ)/9.20_Employee.o

9.22: ch9/9.22.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

9.23: ch9/9.23.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

9.26: ch9/9.26_main.cpp ch9/9.25_Time.cpp ch9/9.24_Time.h
	$(CC) $(CFLAGS) -o $(OBJ)/lib9.25_Time.dylib -shared -fPIC ch9/9.25_Time.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/9.25_Time.o -c ch9/9.25_Time.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@_static $< $(OBJ)/9.25_Time.o
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< -L$(OBJ) -l9.25_Time

9.29: ch9/9.29_main.cpp ch9/9.28_Employee.cpp ch9/9.27_Employee.h
	$(CC) $(CFLAGS) -o $(OBJ)/lib9.28_Employee.dylib -shared -fPIC ch9/9.28_Employee.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/9.28_Employee.o -c ch9/9.28_Employee.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@_static $< $(OBJ)/9.28_Employee.o
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< -L$(OBJ) -l9.28_Employee

saving_account: ch9/saving_account.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

10.1: ch10/10.1.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

10.5: ch10/10.5_main.cpp ch10/10.4_PhoneNumber.cpp ch10/10.3_PhoneNumber.h
	$(CC) $(CFLAGS) -shared -fPIC -o $(OBJ)/libPhoneNumber.dylib ch10/10.4_PhoneNumber.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< -L$(OBJ) -lPhoneNumber

10.8: ch10/10.8_main.cpp ch10/10.7_Date.cpp ch10/10.6_Date.h
	$(CC) $(CFLAGS) -shared -fPIC -o $(OBJ)/libDate.dylib ch10/10.7_Date.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< -L$(OBJ) -lDate

10.9: ch10/10.9_main.cpp ch10/10.11_Array.cpp ch10/10.10_Array.h
	$(CC) $(CFLAGS) -shared -fPIC -o $(OBJ)/libArray.dylib ch10/10.11_Array.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< -L$(OBJ) -lArray

10.13: ch10/10.13.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<
	@$(BIN)/$@

ch11: $(CH11)

11.6: ch11/11.6_main.cpp ch11/11.5_CommissionEmployee.cpp ch11/11.4_CommissionEmployee.h
	$(CC) $(CFLAGS) -DEX11_3_1 -o $(OBJ)/lib11.5CE.dylib -shared -fPIC ch11/11.5_CommissionEmployee.cpp
	$(CC) $(CFLAGS) -DEX11_3_1 -o $(BIN)/$@ $< -L$(OBJ) -l11.5CE
	@$(BIN)/$@

11.9c1: ch11/11.9_main.cpp ch11/11.8_BasePlusCommissionEmployee.cpp ch11/11.7_BasePlusCommissionEmployee.h
	$(CC) $(CFLAGS) -o $(OBJ)/lib11.8BCEc1.dylib -shared -fPIC ch11/11.8_BasePlusCommissionEmployee.cpp
	$(CC) $(CFLAGS) -DEX11_3_2 -o $(BIN)/$@ $< -L$(OBJ) -l11.8BCEc1
	@$(BIN)/$@

11.9c2: ch11/11.9_main.cpp ch11/11.11_BCE.cpp ch11/11.10_BCE.h ch11/11.5_CommissionEmployee.cpp ch11/11.4_CommissionEmployee.h
	$(CC) $(CFLAGS) -DEX11_3_3 -o $(OBJ)/lib11.11BCE.dylib -shared -fPIC ch11/11.11_BCE.cpp -L$(OBJ) -l11.5CE
	$(CC) $(CFLAGS) -DEX11_3_3 -o $(BIN)/$@ $< -L$(OBJ) -l11.11BCE -l11.5CE
	@$(BIN)/$@

11.9c3: ch11/11.9_main.cpp ch11/11.11_BCE.cpp ch11/11.5_CommissionEmployee.cpp
	$(CC) $(CFLAGS) -DEX11_3_4 -o $(OBJ)/lib11.5CE.dylib -shared -fPIC ch11/11.5_CommissionEmployee.cpp
	$(CC) $(CFLAGS) -DEX11_3_4 -o $(OBJ)/lib11.11BCE.dylib -shared -fPIC ch11/11.11_BCE.cpp -L$(OBJ) -l11.5CE
	$(CC) $(CFLAGS) -DEX11_3_4 -o $(BIN)/$@ $< -L$(OBJ) -l11.11BCE -l11.5CE
	@$(BIN)/$@

11.9c4: ch11/11.9_main.cpp ch11/11.14_CE.cpp ch11/11.15_BCE.cpp
	$(CC) $(CFLAGS) -DEX11_3_5 -o $(OBJ)/libCE.dylib -shared -fPIC ch11/11.14_CE.cpp
	$(CC) $(CFLAGS) -DEX11_3_5 -o $(OBJ)/libBCE.dylib -shared -fPIC ch11/11.15_BCE.cpp -L$(OBJ) -lCE
	$(CC) $(CFLAGS) -DEX11_3_5 -o $(BIN)/$@ $< -L$(OBJ) -lCE -l BCE
	@$(BIN)/$@

12.1: ch12/12.1_main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/libCE.dylib -shared -fPIC ch12/CE.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/libBCE.dylib -shared -fPIC ch12/BCE.cpp -L$(OBJ) -lCE
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< -L$(OBJ) -lCE -lBCE

12.2: ch12/12.2_main.cpp
	$(CC) $(CFLAGS) -DPRINT -o $(BIN)/$@ $< -L$(OBJ) -lCE -lBCE

12.3: ch12/12.3_main.cpp
	$(CC) $(CFLAGS) -DPRINT -o $(BIN)/$@ $< -L$(OBJ) -lCE -lBCE

12.4: ch12/12.1_main.cpp
	$(CC) $(CFLAGS) -DVIRTUAL -o $(OBJ)/libCE.dylib -shared -fPIC ch12/CE.cpp
	$(CC) $(CFLAGS) -DVIRTUAL -o $(OBJ)/libBCE.dylib -shared -fPIC ch12/BCE.cpp -L$(OBJ) -lCE
	$(CC) $(CFLAGS) -DVIRTUAL -o $(BIN)/$@ $< -L$(OBJ) -lCE -lBCE

# Other

clean:
	rm -fr $(BIN)/*
