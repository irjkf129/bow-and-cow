#include "game.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void input(Num* user_number)
{
    printf("Введите число:\n");
    scanf("%d", &user_number->number);
    split(user_number->split_number, user_number->number);
}

void generate(Num* generate_number)
{
    generate_number->number = rand() % 9000 + 1000;
    split(generate_number->split_number, generate_number->number);
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

void compransion(Num user_number, Num random_number, Score* score)
{
    for (int i = 0; i < MAX_LENGTH; i++) {
        if (user_number.split_number[i] == random_number.split_number[i]) {
            score->bulls++;
            random_number.split_number[i] = -1;
        }
    }
    for (int i = 0; i < MAX_LENGTH; i++) {
        for (int j = 0; j < MAX_LENGTH; j++) {
            if (user_number.split_number[i] == random_number.split_number[j]
                && i != j) {
                score->cow++;
                random_number.split_number[j] = -1;
                break;
            }
        }
    }
}

void game()
{
    Num number;
    Num rand_number;
    Score score;
    generate(&rand_number);
    while (true) {
        score.bulls = 0;
        score.cow = 0;
        input(&number);
        compransion(number, rand_number, &score);
        output(&score);
        if (score.bulls == MAX_LENGTH) {
            return;
        }
    }
}

void output(Score* score)
{
    printf("cow = %d\nbulls = %d\n", score->cow, score->bulls);
    if (score->bulls == MAX_LENGTH) {
        printf("You win!!\n");
    }
}