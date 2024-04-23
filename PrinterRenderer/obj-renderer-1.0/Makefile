CC = g++
CFLAGS = -Wall -Iinclude -Ilib -std=c++11
LDFLAGS = -lGL -lGLU -lglut -lassimp

BIN = bin/obj_viewer
SRCS = $(wildcard src/*.cpp) lib/stb_image_write.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o lib/*.o $(BIN)

.PHONY: all clean
