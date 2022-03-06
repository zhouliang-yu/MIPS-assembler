OBJ = tester.o phase1.o phase2.o

tester: $(OBJ)
	g++ tester.o phase1.o phase2.o -o tester 
tester.o: tester.cpp LableTable.h phase1.h phase1.o phase2.h phase2.o
	g++ -c tester.cpp -o tester.o
phase2.o: phase2.cpp phase2.h LableTable.h phase1.h
	g++ -c -std=c++11 phase2.cpp -o phase2.o
phase1.o: phase1.cpp phase1.h LableTable.h
	g++ -c phase1.cpp -o phase1.o

.PHONY:clean 

clean: 
	rm *.o tester 