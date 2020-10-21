  #the compiler: gcc for C program, define as g++ for C++
  CC = g++

  # compiler flags:
  #  -g    adds debugging information to the executable file
  #  -Wall turns on most, but not all, compiler warnings
  CFLAGS  = -g -Wall

  # the build target executable:
  TARGET = main
  FILEMAIN = main.cpp
<<<<<<< HEAD
  CLASS = Member.cpp Book.cpp Staff.cpp DbLinkedList.cpp LoginController.cpp RegiterController.cpp BookStoreController.cpp
=======
  CLASS = Member.cpp Book.cpp Staff.cpp DbLinkedList.cpp Buy_BookController.cpp PreOrder_BookController.cpp RentBookController.cpp
>>>>>>> 5aec69f3fd36820d66ab13cd1ac1b5e2c4f6d8cf
  all: 
	$(CC) $(FILEMAIN) $(CLASS) $(CFLAGS) -o $(TARGET)

  clean:
	rm $(TARGET)