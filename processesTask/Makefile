#compiler
CC=gcc
csrc = $(wildcard *.c)
obj = $(csrc:.c=.o)
TARGET=precesesTask
.PHONY: all clean 
all: $(TARGET)
clean:
	-rm -rf $(TARGET) *.o
$(TARGET): $(obj)
	$(CC)  $^ -o $@ 
%.o: %.c
	$(CC) -c $< -o $@