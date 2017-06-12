#compiler
CC=gcc
#flags
CFLAGS= -g -O -Wall
#include PATHs
INC=-Iinclude -Isrc/m1/include -Isrc/m2/include
csrc = $(wildcard src/m1/*.c) \
$(wildcard src/m2/*.c)
obj = $(csrc:.c=.o)
#misc
OUT=outp/
PREFIX = /usr/local
TARGET=helloWorld
#phony targets
.PHONY: all clean install uninstall

all: $(TARGET)

clean:
	-rm -rf $(OUT)/$(TARGET) $(OUT)*.o

$(TARGET): $(obj)
	$(CC) $(INC) $(CFLAGS)  $(addprefix $(OUT),$(notdir $^)) -o $(OUT)$@ 

%.o: %.c
	$(CC) $(INC) $(CFLAGS) -c $< -o $(OUT)$(notdir $@)

install: $(TARGET)
	mkdir -p $(DESTDIR)$(PREFIX)/bin    #user can do `make istall DESTDIR=smth` into custom dir
	cp $(OUT)$< $(DESTDIR)$(PREFIX)/bin/$(TARGET)

uninstall:
			rm -f $(DESTDIR)$(PREFIX)/bin/$(TARGET)