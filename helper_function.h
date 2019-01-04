/********************************************************************
** Program Filename: helper_function.h
** Author: Aeijan Bajracharya
** Date: 2/4/18
** Description: Helper function library .h file
** Input: Returns nothing
** Output: Returns nothing
*********************************************************************/

#include <string>
#ifndef HELPER_FUNCTION_H					
#define HELPER_FUNCTION_H

using namespace std;

bool check_range(int lower_bound, int upper_bound, int test_value);
bool is_int(string num);
bool is_float(string num);
bool is_capital(char letter);
bool is_even(int num);
bool is_odd(int num);
int equality_test(int num1, int num2);
bool float_is_equal(float num1, float num2, float precision);
bool numbers_present(string sentence);
bool letters_present(string sentence);
bool contains_sub_substring(string sentence, string substring);
int word_count(string sentence);
string to_upper(string sentence);
string to_lower(string sentence);
int get_int(string num);
float get_float(string num);

#endif