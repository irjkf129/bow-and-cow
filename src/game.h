#ifndef GAME_H
#define GAME_H
#define MAX_INDEX 3
#define MAX_LENGTH 4

typedef struct{
    int number;
    int split_number[MAX_LENGTH];
}Num;

void input(Num* user_number);
void generate(Num* generate_number);
void split(Num* number);

#endif