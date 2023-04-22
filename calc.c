#include "stack.h"

bool calc(char* str) {
    char symb;
    double x;
    while(symb = *str) {
        switch (symb) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8': 
            case '9':
            case '-':
                int i = 0;
                bool lever = false;
                char buf[len] = {'\0'};
                buf[i++] = symb;
                str++;
                while (((symb = *str) >= '0' && symb <= '9') || (symb == '.' && buf[i-1] != '-')) {
                    str++;
                    lever = true;
                    if (i >= len) {
                        puts("ERROR: buf is full");
                        return false;
                    }
                    buf[i++] = symb;
                }
                if (lever || buf[0] != '-') {
                    double value = atof(buf);
                    if (value == 0) {
                        value = (double) atoi(buf);
                    }
                    if (!push(value)) {
                        return false;
                    }
                    break;
                }
                else {
                    if (pop()) {
                        x = pop_value;
                        if (pop()) {
                            if (push(pop_value - x)) {
                                break;
                            }
                        }
                    }
                return false;
                }    
            case '\0': return true;
            case ' ':
            case '\t': 
                str++;
                break;
            case 's': 
                if (pop()) {
                    if (push(sin(pop_value))) {
                        str++;
                        break;
                    }
                }
                return false;
            case 'c':
                if (pop()) {
                    if (push(cos(pop_value))) {
                        str++;
                        break;
                    }
                }
                return false;
            case '+':
                if (pop()) {
                    x = pop_value;
                    if (pop()) {
                        if (push(pop_value + x)) {
                            str++;
                            break;
                        }
                    }
                }
                return false;
            case '*':
                if (pop()) {
                    x = pop_value;
                    if (pop()) {
                        if (push(pop_value * x)) {
                            str++;
                            break;
                        }
                    }
                }
                return false;
            case '/':
                if (pop()) {
                    x = pop_value;
                    if (x == 0) {
                        puts("error: zero divisor");
                        return false;
                    }
                    if (pop() ) {
                        if (push(pop_value / x)) {
                            str++;
                            break;
                        }
                    }
                }
                return false;
            case '^':
                if (pop()) {
                    x = pop_value;
                    if (pop()) {
                        if (push(pow(pop_value, x))) {
                            str++;
                            break;
                        }
                    }
                }
            case '%':
                if (pop()) {
                    x = floor(pop_value);
                    if (x == 0) {
                        puts("error: zero divisor");
                        return false;
                    }
                    if (pop()) {
                        if (push((int)floor(pop_value) % (int)x)) {
                            str++;
                            break;
                        }
                    }
                }
                return false;
            default: 
                puts("error: uncnown command or trash");
                return false;
        }
    }
    return true;
}

