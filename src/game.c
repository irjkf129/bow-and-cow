#include "game.h"
#include <stdio.h>
#include <stdlib.h>

void input(int* number)
{
    printf("Введите число:\n");
    scanf("%d", number);
}

int generate()
{
    int generate_number;
    generate_number = rand() % 9000 + 1000;
    return generate_number;
}

void split(int* split_number, int number)
{
    int index = MAX_INDEX;
    while (number) {
        split_number[index] = number % 10;
        number /= 10;
        index--;
    }
}