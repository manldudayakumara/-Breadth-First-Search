# Makefile for BFS program

CC = gcc
CFLAGS = -Wall -g
TARGET = bfs

all: $(TARGET)

$(TARGET): bfs.c
	$(CC) $(CFLAGS) -o $(TARGET) bfs.c

clean:
	rm -f $(TARGET)
