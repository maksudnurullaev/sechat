CC=gcc 
# Remove -g -O2 flags after debug
CXXFLAGS=-Wall -g -O2

main: server client tester

clean:
	rm -f server client tester

