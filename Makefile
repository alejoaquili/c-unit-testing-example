all: 
	cd src; make all

clean:
	cd src; make clean
	rm -rf *.out

.PHONY: all clean check