LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

compito: compito.cpp
	g++ -o $@ $^ ${INCS} ${LIBS}

%.o: %.cpp
	g++ -c $< ${INCS}

clean:
	rm compito