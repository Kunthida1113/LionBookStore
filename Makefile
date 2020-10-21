  #the compiler: gcc for C program, define as g++ for C++
  CC = g++

  # compiler flags:
  #  -g    adds debugging information to the executable file
  #  -Wall turns on most, but not all, compiler warnings
  CFLAGS  = -g -Wall

  # the build target executable:
  TARGET = BookStoreOnline
  FILEMAIN = main.cpp
<<<<<<< HEAD
<<<<<<< HEAD
  CLASS = Member.cpp Book.cpp Staff.cpp DbLinkedList.cpp BookStoreController.cpp
=======
  CLASS = Member.cpp Book.cpp Staff.cpp DbLinkedList.cpp RentBookController.cpp
>>>>>>> fe073c614dd9718d00e14d3f7c5ff4a5d18de58a
=======
  CLASS = Member.cpp Book.cpp Staff.cpp DbLinkedList.cpp BookStoreController.cpp
>>>>>>> d92b58403290b9bbb422ba7994e7babd87330565
  all: 
	$(CC) $(FILEMAIN) $(CLASS) $(CFLAGS) -o $(TARGET)

  clean:
	rm $(TARGET)