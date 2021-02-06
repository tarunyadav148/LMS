LMS: main.o interface.o student.o book.o methods.o first_time.o college.o
	g++ main.o interface.o student.o book.o methods.o first_time.o college.o -o LMS

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

first_time.o: first_time.cpp
	g++ -c first_time.cpp

college.o: college.cpp
	g++ -c college.cpp

clean:
	rm *.o LMS *.dat