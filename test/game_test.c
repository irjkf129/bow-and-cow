#include "ctest.h"
#include "game.h"

CTEST(test_split_function, correct_split_number)
{
    int exp[MAX_LENGTH] = {6, 3, 8, 3};
    int real[MAX_LENGTH];
    int number = 6383;
    int exp_code = OK;
    int real_code = split(real, number);
    for (int i = 0; i < MAX_INDEX; i++) {
        ASSERT_EQUAL(exp[i], real[i]);
    }
    ASSERT_EQUAL(exp_code, real_code);
}

CTEST(test_split_function, uncorrect_split_negative_number)
{
    int real[MAX_LENGTH];
    int number = -6383;
    int exp_code = ERROR_NEGATIVE_NUMBER;
    int real_code = split(real, number);
    ASSERT_EQUAL(exp_code, real_code);
}

CTEST(test_split_function, uncorrect_split_little_length_number)
{
    int real[MAX_LENGTH];
    int number = 638;
    int exp_code = ERROR_NUMBER_LENGTH;
    int real_code = split(real, number);
    ASSERT_EQUAL(exp_code, real_code);
}

CTEST(test_split_function, uncorrect_split_greater_length_number)
{
    int real[MAX_LENGTH];
    int number = 63834;
    int exp_code = ERROR_NUMBER_LENGTH;
    int real_code = split(real, number);
    ASSERT_EQUAL(exp_code, real_code);
}