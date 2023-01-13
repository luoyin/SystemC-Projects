SC_INCLUDE = /opt/systemc-2.3.3/include/
SC_LIB = /opt/systemc-2.3.3/lib-linux64/

all: main.cpp
	g++ main.cpp -o main -I. -I${SC_INCLUDE} -L${SC_LIB} -lsystemc

clean:
	rm -f main *.vcd
