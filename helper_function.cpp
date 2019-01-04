/********************************************************************
** Program Filename: helper_function.cpp
** Author: Aeijan Bajracharya
** Date: 2/4/18
** Description: Helper function library c++ file
** Input: Returns nothing
** Output: Returns nothing
*********************************************************************/

#include <iostream>
#include <string>
#include "helper_function.h"
#include <cmath>
using namespace std;

bool check_range(int lower_bound, int upper_bound, int test_value) {
		if (test_value >= lower_bound && test_value <= upper_bound) {
			return true;
		}
		else {
			return false;
		}
}

bool is_int(string num){
	for (int k = 0; k < num.length(); k++){
		if ((int)num[k] == 46){
			return false;
		}
	}
	bool is_negative = false;
	if (num[0] == '-'){
		is_negative = true;
		for (int j = 1; j < num.length(); j++){
			if (((int)num[j] < 48 || (int)num[j] > 57)){
				return false;
			}
		}	
	}
	for (int i = 0; i < num.length(); i++){
		if (num[i] < '0' || num[i] > '9'){
			return false;
		}
	}
	return true;
}

bool is_float(string num){
	for (int i = 0; i < num.length(); i++) {
		if((int)num[i] >= 45 && (int)num[i] <= 57) {
			continue;
		}
		else {
			return false;
		}
	}
	int num_of_dec = 0;
	for (int i = 0; i < num.length(); i++) {
		if ((int)num[i] == 46) {
			num_of_dec++;	
		}
	}
	if (num_of_dec <= 1) {
		return true;
	}
	else {
		return false;
	}
}

bool is_capital(char letter){
	if ((int)letter >= 65 && (int)letter <= 91) {
		return true;	
	}
	else {
		return false;	
	}
}

bool is_even(int num){
	if (num % 2 == 0){
		return true;
	}	
	else{
		return false;	
	}
}

bool is_odd(int num){
	if (num % 2 != 0){
		return true;	
	}
	else{
		return false;	
	}	
}


int equality_test(int num1, int num2){
	if (num1 == num2){
		return 0;	
	}
	if (num1 < num2){
		return -1;		
	}
	if (num1 > num2){
		return 1;	
	}
}

bool float_is_equal(float num1, float num2, float precision){
	if (abs(num1 - num2) <= precision){
		return true;
	}
	else{
		return false;	
	}
}

bool numbers_present(string sentence){
	for(int i = 0; i < sentence.length(); i++){
		if ((int)sentence[i] >= 48 && (int)sentence[i] <= 57){
			return true;	
		}	
	}
	return false;	
}

bool letters_present(string sentence){
	for(int i = 0; i < sentence.length(); i++){
		if ((int)sentence[i] >= 65 && (int)sentence[i] <= 90){
			return true;
		}
		if ((int)sentence[i] >= 97 && (int)sentence[i] <= 122){
			return true;
		}
	}
	return false;
}

bool contains_sub_string(string sentence, string substring){
	for(int i = 0; i < sentence.length(); i++){
		bool match = true;	
		for(int j = 0; j < substring.length(); j++){
			match = match && (substring[j] == sentence[i+j]);
		}
		if(match){
			return true;
		}	
	}
	return false;
}

int word_count(string sentence){
	int count_space = 0;
	for(int i = 0; i < sentence.length(); i++){
		if ((int)sentence[i] == 32 && (((int)sentence[i+1] >= 97 && (int)sentence[i+1] <= 122) && ((int)sentence[i-1] >= 97 && (int)sentence[i-1] <= 122))){
			count_space++;
		}

	}
	count_space += 1;
	return count_space;
}

string to_upper(string sentence){
	for(int i = 0; i < sentence.length(); i++){
		if ((int)sentence[i] >= 97 && (int)sentence[i] <= 122){
			sentence[i] = (char)(((int)sentence[i]) - 32);
		}
	}
	return sentence;		
}

string to_lower(string sentence){
	for(int i = 0; i < sentence.length(); i++){
		if ((int)sentence[i] >= 65 && (int)sentence[i] <= 90){
			sentence[i] = (char)(((int)sentence[i]) + 32);
		}
	}
	return sentence;		
}


int get_int(string num){
	int res = 0, i = 0;
	if(num[0] == '-'){
		i = 1;
	}
	for(i; i < num.length(); i++){
		res += (num[i] - 48) * pow(10,num.length()-i-1);
	}
	if(num[0] == '-'){
		res *= -1;
	}
	return res;	
}

float get_float(string num) {
	float res = 0;
	int i = 0, j = 0;
	if(num[0] == '-'){
		i = 1;
		j = 1;
	}
	for(i; i < num.length(); i++) {
		if (num[i] == '.') {
			break;	
		}
	}
	for(j; j < i; j++){
		res += (num[j] - 48) * pow(10,i-j-1);

	}
	for(int k = i + 1; k < num.length(); k++){
		res += (num[k] - 48) * pow(10,i-k);

	}
	if(num[0] == '-'){
		res *= -1;

	}
	return res;
}
