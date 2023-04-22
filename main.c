#include "stack.h"
#include "calc.h"
#include "strings.h"

int main() {
    puts("5_1:\ninput 1st string:");
    char* str_1 = get_str();
    puts("input 2nd string:");
	char* str_2 = get_str();
	printf("result: %i\n", num(str_1, str_2));
    puts("5_2:\ninput math quest:");
    char* str = get_str();
    if(calc(str)) {
        printf("%f",stack[(int) (stack[0])]);
    }
}