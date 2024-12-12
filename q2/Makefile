CC = gcc
CFLAGS = -Wall
CFILES = main.c array_utils.c
OBJFILES = main.o array_utils.o
TARGET = q2

all : $(TARGET)

$(TARGET) : $(OBJFILES)
	$(CC) $(CFLAGS) $(OBJFILES) -o $(TARGET)

array_utils.o : array_utils.c
	$(CC) array_utils.c -c

main.o : main.c
	$(CC) main.c -c

clean:
	rm -f $(TARGET) $(OBJFILES)