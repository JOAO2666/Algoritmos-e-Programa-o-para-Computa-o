CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = -lm

SRCS = main.c matematica.c strings.c
OBJS = $(SRCS:.c=.o)
TARGET = simulados

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) 