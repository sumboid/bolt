foo: Main.o Bitset.o
	g++ $^ -o $@

clean:
	rm -rf *.o

# vim: set noet:
