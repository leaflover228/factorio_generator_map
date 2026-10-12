.PHONY: all clean

CC = gcc
CFLAGS = -std=c11 -D_GNU_SOURCE -Wall -Wextra -g
SOURCE = $(wildcard src/*.c)
OBJS = $(SOURCE:%.c=%.o)
INCLUDE = -I "./include"
BINDIR = bin
TARGET = $(BINDIR)/factorio_gen_map_img

all: $(TARGET)

$(TARGET): $(OBJS) | $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(BINDIR):
	mkdir -p $@

clean:
	rm -rf src/*.o $(BINDIR)
