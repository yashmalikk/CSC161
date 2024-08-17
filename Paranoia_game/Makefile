
CC := clang
CFLAGS := -g
CFLAGS_ASAN := $(CFLAGS) -fsanitize=address

all: paranoia

clean:
	rm -rf paranoia 

paranoia: main.c player_list.h player_list.c
	$(CC) $(CFLAGS) -o paranoia main.c player_list.c

.PHONY: all clean
