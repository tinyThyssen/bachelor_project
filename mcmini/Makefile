CC = cc
CFLAGS = -O2 -Wall -Wextra -pedantic
LDFLAGS = -lm

SRC = \
  src/main.c \
  src/vec3.c \
  src/rng.c \
  src/source_disk.c

OUT = disk_source

all:
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)
