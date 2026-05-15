out: clean compile execute

#-Wno-sign-compare to delete this annoying bit sign mismatch warning.
compile: main.cpp Product.cpp
	g++ -g -Wall -Wno-sign-compare -std=c++14 main.cpp Product.cpp -o mainexe

execute: mainexe
	./mainexe

clean:
	rm -f mainexe+