CC=gcc
CFLAGS=-g -O2 -Wall -Wextra -std=gnu11 -IG:\C\PointersOnC\lib\ $(OPTFLAGS)

LIBS= $(OPTLIBS)

SOURCES=$(wildcard *.c)
DEPS = $(wildcard *.h)
OBJ = $(SOURCES: .c=.o)

TARGET=fgrep

all: $(TARGET)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: target all
