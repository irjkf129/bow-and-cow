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