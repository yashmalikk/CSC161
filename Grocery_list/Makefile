
CC = gcc
CFLAGS = -Wall -Wextra -g

SRCS = grocery-list.c
OBJS = $(SRCS:.c=.o)
TARGET = grocery-list

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
