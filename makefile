polyexam2: poly2.o polyexam2.o
	g++ poly2.o polyexam2.o -o polyexam2

poly2.o: poly2.cxx poly2.h
	g++ poly2.cxx -c

polyexam2.o: polyexam2.cxx poly2.h
	g++ polyexam2.cxx -c

clean:
	rm polyexam2 poly2.o polyexam2.o
