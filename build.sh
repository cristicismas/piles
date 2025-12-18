gcc main.c -Wall -Wextra -ggdb -pedantic -c -I./raylib/src -o main.o
gcc array.c -Wall -Wextra -ggdb -pedantic -c -o array.o
gcc main.o array.o -L./raylib/src -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o out
