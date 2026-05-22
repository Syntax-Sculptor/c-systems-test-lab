INCLUDES := -I lib/ -I ext/unity
CFLAGS   := -Wall -Wextra -std=c2x
CC		 := gcc
SRC		 := src/main.c src/systems_test_lab.c 
OUT		 := build/systems_test_lab
TEST_OUT := build/test
SRC_TEST := tests/test_systems_test.c src/systems_test_lab.c ext/unity/unity.c

all: systems_test_lab

systems_test_lab:
	mkdir -p build
	$(CC) $(SRC) $(CFLAGS) $(INCLUDES) -o $(OUT)

test:
	mkdir -p build
	$(CC) $(SRC_TEST) $(CFLAGS) $(INCLUDES) -o $(TEST_OUT)
	./$(TEST_OUT)

clean:
	rm -rf build/