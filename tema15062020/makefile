LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

myLIBS:=integral.o integralMC.o

compito: compito.cpp ${myLIBS}
	g++ -o $@ $^ ${INCS} ${LIBS}

%.o: %.cpp
	g++ -c $< ${INCS}

clean:
	rm compito
	rm *.o