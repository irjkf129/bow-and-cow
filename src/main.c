#include "game.h"
#include <stdio.h>

int main()
{
    Num number;
    input(&number);
    for (int i = 0; i < 4; i++) {
        printf("%d ", number.split_number[i]);
    }
    return 0;
}