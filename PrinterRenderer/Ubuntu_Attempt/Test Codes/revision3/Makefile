# Default architecture
ARCH ?= x86

# Compiler setup
ifeq ($(ARCH),arm)
	#Set the path to your cross-compiler toolchain here if it's not in the PATH
	#Example: CROSS_COMPILE=/usr/bin/arm-linux-gnueabihf-
	CROSS_COMPILE ?= arm-linux-gnueabi-
	CC=$(CROSS_COMPILE)g++
else
    CC=g++
endif

# Output directory
OUT_DIR=bin/$(ARCH)

# Compiler flags
CFLAGS=-Wall -Wextra

# Libraries
ifeq ($(ARCH),arm)
    LIBS=-lassimp # Specify ARM-specific library paths if needed
else
    LIBS=-lGL -lGLU -lglut -lassimp
endif

# Targets that don't correspond to filenames
.PHONY: all clean directories

all: directories $(OUT_DIR)/obj_viewer $(OUT_DIR)/model_center

# Rule to create output directory
directories:
	@mkdir -p $(OUT_DIR)

# Building obj_viewer
$(OUT_DIR)/obj_viewer: obj_viewer.cpp
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

# Building model_center
$(OUT_DIR)/model_center: obj_centering.cpp
	$(CC) $(CFLAGS) -o $@ $< -lassimp

clean:
	rm -rf bin
