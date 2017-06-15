#compiler
CC=gcc
csrc = $(wildcard *.c)
obj = $(csrc:.c=.o)
TARGET=threadsTask
.PHONY: all clean 
all: $(TARGET)
clean:
	-rm -rf $(TARGET) *.o
$(TARGET): $(obj)
	$(CC) -w -pthread $^ -o $@ 
%.o: %.c
	$(CC) -c $< -o $@