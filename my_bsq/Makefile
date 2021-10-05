OBJ=obj
BIN=bin

CFLAGS +=-W  -Wall -Wextra -g3
 
CC=gcc
TARGET=my_bsq
RM=rm -rf

SRCS=$(wildcard ./*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))


all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(CFLAGS) 

$(OBJ)/%.o: $(SRC)/%.c 
	${CC} ${CFLAGS} -c $< -o $@

clean:
		$(RM) $(TARGET) 
