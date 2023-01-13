SC_INCLUDE = /opt/systemc-2.3.4/include/
SC_LIB = /opt/systemc-2.3.4/lib-linux64/

all: main.cpp
	g++ main.cpp -o main -I. -I${SC_INCLUDE} -L${SC_LIB} -lsystemc -Wl,-rpath ${SC_LIB}

clean:
	rm -f main *.vcd
