Tree: Christmas.o Christmas_Celebration.o
	g++ -o Tree Christmas.o Christmas_Celebration.o
Christmas.o: Christmas.cpp christmas.h
	g++ -c Christmas.cpp christmas.h
Christmas_Celebration.o: Christmas_Celebration.cpp christmas.h
	g++ -c Christmas_Celebration.cpp christmas.h

clean:
	rm Tree *.o *.h.gch