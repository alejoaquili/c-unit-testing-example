include ./include/Makefile.inc

TARGET  := MemoryManagerTest
SOURCES := $(wildcard *.c)
OBJECTS := $(SOURCES:.c=.o)

all: clean compile link

compile:$(SOURCES)
	$(COMPILER) $(COMPILER_FLAGS) $(SOURCES)
	@echo "Compilation complete."

link:$(OBJECTS)
	$(LINKER) $(LINKER_FLAGS) $(OBJECTS) -o ../$(TARGET).out
	@echo "Linking complete."

%.o : %.c
	$(COMPILER) $(COMPILER_FLAGS) $< -o $@

%.out : %.o
	$(LINKER) $(LINKER_FLAGS) $< -o $@

clean:
	@rm -rf $(OBJECTS)
	@rm -rf $(TARGET).out
	@echo "Clean complete."

.PHONY: all clean