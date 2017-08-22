CC=gcc
CFLAGS=-g -O2 -Wall -Wextra -std=gnu11 $(OPTFLAGS)

LIBS=$(OPTLIBS)

SOURCES=$(wildcard *.c)
DEPS=$(wildcard *.h)
OBJ=$(SOURCES: .c=.o)

TARGET=get_line.a
# DLL_TARGET=$(TARGET: .a=.dll)

all: $(TARGET)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): build $(OBJ)
	ar rcs $@ $(OBJ)
	ranlib $@

# $(DLL_TARGET): $(TARGET) $(OBJ)
# 	$(CC) -shared -o $@ $(OBJ)

clean:
	rm $(TARGET)
	rm $(DLL_TARGET)
	rm *.o

.PHONY: all clean
