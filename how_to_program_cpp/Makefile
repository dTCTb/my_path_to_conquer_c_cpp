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
CH12=12.1 12.2 12.3 12.4 12.17 12.19
CH13=13.3 13.4 13.5 13.6 13.7 13.8 13.9 13.10 13.11 13.13 13.14 13.15 13.16 13.17 13.18 13.19 13.20 13.21 13.22 ex13.15 ex13.18
CH14=14.3 14.6 14.7 14.11 14.12 14.13 14.14 ex14.12
CH15=15.4 15.10 15.11 15.13 15.14 15.15 15.16 15.17 15.18 15.19 15.20 15.21
CH16=16.1 16.2 16.3 16.4 16.5 16.6 16.7 16.8 16.9 16.10 16.11 16.12 16.13 16.15 16.16 ex16.3
CH17=17.2 17.3 17.4 17.5 17.9
TARGET= $(CH1) $(CH2) $(CH3) $(CH4) $(CH5) $(CH6) $(CH7) $(CH8) $(CH9) $(CH10) $(CH11) $(CH12) $(CH13) $(CH14) $(CH15) $(CH16) $(CH17)

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

12.17_library: ch12/base_* ch12/derived_*
	$(CC) $(CFLAGS) -o $(OBJ)/libE.dylib -shared -fPIC ch12/base_employee.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/libSE.dylib -shared -fPIC ch12/derived_salaried_employee.cpp -L$(OBJ) -lE
	$(CC) $(CFLAGS) -o $(OBJ)/libCE.dylib -shared -fPIC ch12/derived_commission_employee.cpp -L$(OBJ) -lE -lSE
	$(CC) $(CFLAGS) -o $(OBJ)/libBCE.dylib -shared -fPIC ch12/derived_base_plus_commission_employee.cpp -L$(OBJ) -lE -lSE -lCE

12.17: ch12/12.17_main.cpp  12.17_library
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< -L$(OBJ) -lE -lSE -lCE -lBCE

12.19: ch12/12.19.cpp 12.17_library
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< -L$(OBJ) -lE -lSE -lCE -lBCE

CH13: $(CH13)

13.3: ch13/13.3.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

13.4: ch13/13.4.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

13.5: ch13/13.5.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

13.6: ch13/13.6.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

13.7: ch13/13.7.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

13.8: ch13/13.8.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

13.9: ch13/13.9.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

13.10: ch13/13.10.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

13.11: ch13/13.11.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

13.13: ch13/13.13.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

13.14: ch13/13.14.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

13.15: ch13/13.15.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

13.16: ch13/13.16.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

13.17: ch13/13.17.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

13.18: ch13/13.18.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

13.19: ch13/13.19.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

13.20: ch13/13.20.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

13.21: ch13/13.21.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

13.22: ch13/13.22.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

ex13.15: ch13/ex13.15.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

ex13.18: ch13/ex13.18.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

CH14: $(CH14)

14.3: ch14/14.3.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

14.6: ch14/14.6.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

14.7: ch14/14.7.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

ClientData: ch14/ClientData.cpp ch14/ClientData.h
	$(CC) $(CFLAGS) -o $(OBJ)/libClientData.dylib -shared -fPIC ch14/ClientData.cpp

14.11: ch14/14.11_main.cpp ClientData
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< -L$(OBJ) -lClientData

14.12: ch14/14.12_main.cpp ClientData
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< -L$(OBJ) -lClientData

14.13: ch14/14.13_main.cpp ClientData
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< -L$(OBJ) -lClientData

14.14: ch14/14.14_main.cpp ClientData
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< -L$(OBJ) -lClientData

ex14.12: ch14/ex14.12.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

CH15: $(CH15)

15.4: ch15/15.4.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

15.10: ch15/15.10.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

15.11: ch15/15.11.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

15.13: ch15/15.13.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

15.14: ch15/15.14.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

15.15: ch15/15.15.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

15.16: ch15/15.16.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

15.17: ch15/15.17.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

15.18: ch15/15.18.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

15.19: ch15/15.19.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

15.20: ch15/15.20.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

15.21: ch15/15.21.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

CH16: $(CH16)

16.1: ch16/16.1.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

16.2: ch16/16.2.cpp
	$(CC) $(CFLAGS) -DCPP17 -o $(BIN)/$@ $<

16.3: ch16/16.3.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

16.4: ch16/16.4.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

16.5: ch16/16.5.cpp
	$(CC) -std=c++17 $(CFLAGS) -DCPP17 -o $(BIN)/$@ $<

16.6: ch16/16.6.cpp
	$(CC) -std=c++11 $(CFLAGS) -o $(BIN)/$@ $<

16.7: ch16/16.7.cpp
	$(CC) -std=c++11 $(CFLAGS) -o $(BIN)/$@ $<

16.8: ch16/16.8.cpp
	$(CC) -std=c++11 $(CFLAGS) -o $(BIN)/$@ $<

16.9: ch16/16.9.cpp
	$(CC) -std=c++11 $(CFLAGS) -o $(BIN)/$@ $<

16.10: ch16/16.10.cpp
	$(CC) -std=c++17 $(CFLAGS) -o $(BIN)/$@ $<

16.11: ch16/16.11.cpp
	$(CC) -std=c++17 $(CFLAGS) -o $(BIN)/$@ $<

16.12: ch16/16.12.cpp
	$(CC) -std=c++17 $(CFLAGS) -o $(BIN)/$@ $<

16.13: ch16/16.13.cpp
	$(CC) -std=c++17 $(CFLAGS) -o $(BIN)/$@ $<

16.15: ch16/16.15.cpp
	$(CC) -std=c++17 $(CFLAGS) -o $(BIN)/$@ $<

16.16: ch16/16.16.cpp
	$(CC) -std=c++17 $(CFLAGS) -o $(BIN)/$@ $<

ex16.3: ch16/ex16.3.cpp
	$(CC) -std=c++20 -DCPP17 -DCPP20 $(CFLAGS) -o $(BIN)/$@ $<

CH17: $(CH17)

17.2: ch17/17.2.cpp ch17/DivideByZeroException.h
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

17.3: ch17/17.3.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

17.4: ch17/17.4.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

17.5: ch17/17.5.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

17.6: ch17/17.6.cpp
	$(CC) $(CFLAGS) -o $(BIN)/$@ $<

Integer: ch17/Integer.cpp ch17/Integer.h
	$(CC) -Wall -Wextra -o $(OBJ)/lib$@.dylib -shared -fPIC $< -I./ch17

17.9: ch17/17.9.cpp Integer
	$(CC) $(CFLAGS) -o $(BIN)/$@ $< -L$(OBJ) -lInteger

# Other

clean:
	rm -fr $(BIN)/* 17.9
