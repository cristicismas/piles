gcc main.c -Wall -Wextra -ggdb -pedantic -c -o main.o
gcc array.c -Wall -Wextra -ggdb -pedantic -c -o array.o
gcc main.o array.o -o out
./out
