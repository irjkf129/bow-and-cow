#include "game.h"
#include <stdio.h>
#include <stdlib.h>

void input(Num* user_number)
{
    printf("Введите число:\n");
    scanf("%d", &user_number->number);
    split(user_number);
}

void generate(Num* generate_number)
{
    generate_number->number = rand() % 9000 + 1000;
    split(generate_number);
}

void split(Num* number)
{
    int index = MAX_INDEX;
    while (number->number) {
        printf("%d\n", number->number);
        number->split_number[index] = number->number % 10;
        number->number /= 10;
        index--;
    }
}