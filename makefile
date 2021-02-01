LMS: main.o interface.o student.o book.o methods.o
	g++ main.o interface.o student.o book.o methods.o -o LMS

main.o: main.cpp
	g++ -c main.cpp

interface.o: interface.cpp
	g++ -c interface.cpp

student.o: student.cpp
	g++ -c student.cpp

book.o: book.cpp
	g++ -c book.cpp

methods.o: methods.cpp
	g++ -c methods.cpp

clean:
	rm *.o LMS *.dat