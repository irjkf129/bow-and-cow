#include "game.h"
#include <stdio.h>

int main()
{
    int split_number[4];
    int number;
    input(&number);
    split(split_number, number);
    for (int i = 0; i < 4; i++) {
        printf("%d ", split_number[i]);
    }
    return 0;
}