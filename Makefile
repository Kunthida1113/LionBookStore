  #the compiler: gcc for C program, define as g++ for C++
  CC = g++

  # compiler flags:
  #  -g    adds debugging information to the executable file
  #  -Wall turns on most, but not all, compiler warnings
  CFLAGS  = -g -Wall

  # the build target executable:
  TARGET = main
  FILEMAIN = main.cpp
  CLASS = Member.cpp Book.cpp Staff.cpp DbLinkedList.cpp LoginController.cpp RegisterController.cpp BookStoreController.cpp Bill.cpp RentBookReport.cpp BuyBookReport.cpp PreOrderBookReport.cpp 
  all: 
	$(CC) $(FILEMAIN) $(CLASS) $(CFLAGS) -o $(TARGET)

  clean:
	rm $(TARGET)