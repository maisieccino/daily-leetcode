/*
 * VALID PARENTHESES (#20)
 * Runtime: 0 ms
 * 
 * Hey, so about mallocing the biggest array
 * possible. that's kinda what I did here.
 * my solution involves making a massive stack
 * and pushing chars onto it. well, it gets
 * results at least. and my program aims to
 * terminate as soon as possible (mismatched
 * brackets) to try and speed things up a little.
 * call it lazy evaluation if you will since I'm
 * not going to evaluate the whole list if it
 * isn't neccessary.
 */
void push(char* stack, int* ptr, char c) {
    stack[++(*ptr)] = c;
}

char pop(char* stack, int* ptr) {
    if (*ptr < 0) {
        return '\0';
    }
    return stack[(*ptr)--];
}

bool isValid(char* s) {
    if (*s == '\0')
        return true;
    
    char *parenstack[SHRT_MAX];
    int stackptr = -1;
    while (*s != '\0') {
        char c;
        switch (*(s++)) {
            case '(': push(parenstack, &stackptr, '('); break;
            case '[': push(parenstack, &stackptr, '['); break;
            case '{': push(parenstack, &stackptr, '{'); break;
            case ')':
                c = pop(parenstack, &stackptr);
                if (c != '(')
                    return false;
                break;
            case ']':
                c = pop(parenstack, &stackptr);
                if (c != '[')
                    return false;
                break;
            case '}':
                c = pop(parenstack, &stackptr);
                if (c != '{')
                    return false;
                break;
            default: break;
        }
    }
    
    return (stackptr < 0);
}
