#ifndef GAME_H
#define GAME_H
#define MAX_INDEX 3
#define MAX_LENGTH 4

typedef struct{
    int number;
    int split_number[MAX_LENGTH];
}Num;

typedef struct{
    int bulls;
    int cow;
}Score;

void input(Num* user_number);
void generate(Num* generate_number);
void split(int* split_number, int number);
void compransion(Num user_number, Num random_number, Score* score);

#endif