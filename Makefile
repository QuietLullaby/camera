CFLAGS = 'pkg-config --cflags opencv'
CLIBS = 'pkg-config --libs opencv'

objects= main.o

tcp: $(objects) 
	g++ main.cpp -o main $(pkg-config --cflags --libs opencv) -pthread
	

.PHONY: clean
clean:
	rm tcp $(objects)
