#include "stack.h"

char* get_str() {
    char symb;
    char* string = (char*) calloc(0, sizeof(char));           
    for (unsigned int j = 0; (symb = getchar()) != '\n'; ++j) {
        if (!(j % 10)) {
            string = (char*) realloc(string, (j + 11) * sizeof(char));
        }
        string[j] = symb;
        string[j + 1] = '\0';
    }
    return string;
}

bool check_symb(char symb, char* str) {
	while ((int) *str) {
		if (symb == *str++) {
			return true;
		}
	}
	return false;
}

int num(char* str_1, char* str_2) {
	int i = 0;
	while ((int) *str_1) {
		if (check_symb(*str_1++, str_2)) {
			return i;
		}
		i++;
	}
	return -1;
}
