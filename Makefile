CC = gcc
CFLAGS = -Wall -Wextra -pedantic

TARGET = lab_11

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)
