#ifndef GAME_H
#define GAME_H

#define MAX_INDEX 3
#define MAX_LENGTH 4

#define ERROR_NUMBER_LENGTH -1
#define ERROR_NEGATIVE_NUMBER -2
#define ERROR_SYMBOL_INPUT -3
#define GAME_END_ERROR -4

#define OK 0

typedef struct{
    int number;
    int split_number[MAX_LENGTH];
}Num;

typedef struct{
    int bulls;
    int cow;
}Score;

int input(Num* user_number);
void generate(Num* generate_number);
int split(int* split_number, int number);
void compransion(Num user_number, Num random_number, Score* score);
int game();
void output(Score* score);
void parse_error(int error_code);

#endif