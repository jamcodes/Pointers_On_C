CC=gcc
CFLAGS=-g -O2 -Wall -Wextra -std=gnu11 -Isrc $(OPTFLAGS)

LIBS= $(OPTLIBS)

LDIR = C:\_clib

SOURCES=$(wildcard src/**/*.c src/*.c)
DEPS = $(wildcard src/**/*.h src/*.h)
OBJ = $(SOURCES: .c=.o)

TEST_SRC=$(wildcard tests/*.c)
TESTS=$(TEST_SRC:.c=)

TARGET=build/single_linked_list.a
DLL_TARGET=$(TARGET:.a=.dll)

all: $(TARGET) $(DLL_TARGET) tests

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

#$(TARGET): CFLAGS += -fPIC
# $(TARGET): $(OBJ)
# 	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(TARGET): build $(OBJ)
	ar rcs $@ $(OBJ)
	ranlib $@

$(DLL_TARGET): $(TARGET) $(OBJ)
	$(CC) -shared -o $@ $(OBJ)

tests: CFLAGS += $(SOURCES)
tests: $(TESTS)

clean:
	rm $(TARGET)
	rm $(DLL_TARGET)
	rm src/*.o
	rm $(TESTS)
	rm tests/*.o

.PHONY: target all tests
