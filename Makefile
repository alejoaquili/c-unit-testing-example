all: 
	cd src; make all

clean:
	cd src; make clean
	
format:
	clang-format -style=file --sort-includes --Werror -i ./src/*.c ./src/include/*.h

check:
	cppcheck --quiet --enable=all --force --inconclusive .
	pvs-studio-analyzer trace -- make
	pvs-studio-analyzer analyze
	plog-converter -a '64:1,2,3;GA:1,2,3;OP:1,2,3' -t tasklist -o report.tasks PVS-Studio.log

.PHONY: all clean format check