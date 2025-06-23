CC=g++
CCFLAGS=--std=c++20 -pipe -g -fsanitize=address,undefined -Wall -Wextra -Wshadow -Wconversion

all: main run

main: main.cpp
	$(CC) $(CCFLAGS) ./main.cpp -o main

play: play.cpp
	$(CC) $(CCFLAGS) ./play.cpp -o main

run:
	cat ./test.txt | ./main
