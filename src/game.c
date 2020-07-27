#include "game.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int input(Num* user_number)
{
    char string[1000];
    printf("Введите число:\n");
    scanf("%s", string);
    if (isdigit(string[0])) {
        user_number->number = atoi(string);
    } else {
        return ERROR_SYMBOL_INPUT;
    }
    return split(user_number->split_number, user_number->number);
}

void generate(Num* generate_number)
{
    generate_number->number = rand() % 9000 + 1000;
    split(generate_number->split_number, generate_number->number);
}

int split(int* split_number, int number)
{
    if (number < 0) {
        return ERROR_NEGATIVE_NUMBER;
    }
    int index = MAX_INDEX;
    while (number) {
        if (index < 0) {
            return ERROR_NUMBER_LENGTH;
        }
        split_number[index] = number % 10;
        number /= 10;
        index--;
    }
    if (index != -1) {
        return ERROR_NUMBER_LENGTH;
    }
    return OK;
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

int game()
{
    int return_code = 0;
    Num number;
    Num rand_number;
    Score score;
    generate(&rand_number);
    while (true) {
        score.bulls = 0;
        score.cow = 0;
        return_code += input(&number);
        if (return_code != OK) {
            parse_error(return_code);
            return GAME_END_ERROR;
        }
        compransion(number, rand_number, &score);
        output(&score);
        if (score.bulls == MAX_LENGTH) {
            return OK;
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

void parse_error(int error_code)
{
    switch (error_code) {
    case ERROR_NUMBER_LENGTH:
        printf("Uncorrect number length(need 4)\n");
        break;
    case ERROR_NEGATIVE_NUMBER:
        printf("Input negative number\n");
        break;
    case ERROR_SYMBOL_INPUT:
        printf("Input uncorrect symbol\n");
        break;
    }
}