INCLUDES := -I lib/ -I ext/unity
CFLAGS   := -Wall -Wextra -std=c2x
CC		 := gcc
SRC		 := src/main.c src/systems_test_lab.c
OUT		 := -o build/systems_test_lab

all: systems_test_lab

systems_test_lab:
	mkdir -p build
	$(CC) $(SRC) $(CFLAGS) $(INCLUDES) $(OUT)

clean:
	rm -rf build/