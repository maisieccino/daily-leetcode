/**
* Valid Number (#65)
* Runtime: 9 ms
*
* tl;dr: Edge cases, edge cases everywhere
* No formal input range given, so I had to work it
* out over time. In an actual interview, I would be
* asking the interviewer what I should expect to receive
* but idek.
*/
int* findChars(char* s, int* count, char c) {
    int* results = (int*)calloc(strlen(s), sizeof(int));
    int resptr = -1;
    int ptr = 0;
    while (s[ptr] != '\0') {
        if (s[ptr] == c)
            results[++resptr] = ptr;
        ptr++;
    }
    *count = resptr + 1;
    return results;
}

bool isInteger(char* s) {
    for (int i = 0; i < strlen(s); i++) {
        if (!(s[i] >= '0' && s[i] <= '9'))
            return false;
    }
    return true;
}

bool isDecimal(char* s) {
    if (isInteger(s))
        return true;
    
    int decCount = 0;
    int dec = findChars(s, &decCount, '.')[0];
    if (decCount != 1)
        return false;
    char* fst = (char*)calloc(dec+1, sizeof(char));
    char* snd = (char*)calloc(strlen(s)-decCount+1, sizeof(char));
    
    strncpy(fst,s,dec); fst[dec] = '\0';
    strcpy(snd,s+dec+1); snd[strlen(s)-decCount] = '\0';
    
    printf("s: \"%s\"\n",s);
    printf("dec: %i\n",dec);
    printf("fst: \"%s\"\n",fst);
    printf("snd: \"%s\"\n",snd);
    
    if (!strlen(fst) && !strlen(snd))
        return false;
    
    bool res = (isInteger(fst) && isInteger(snd));
    // free(fst);
    // free(snd);
    return res;
}

bool isExp(char* s) {
    int decCount = 0;
    int dec = findChars(s, &decCount, 'e')[0];
    if (decCount != 1)
        return false;
    char* fst = (char*)calloc(dec+1, sizeof(char));
    char* snd = (char*)calloc(strlen(s)-decCount, sizeof(char));
    
    strncpy(fst,s,dec); fst[dec] = '\0';
    strcpy(snd,s+dec+1); snd[strlen(s)-decCount-1] = '\0';
    
    if (strlen(snd) && (*snd == '-' || *snd == '+'))
        snd++;
    if ((!strlen(fst)) || (!strlen(snd)))
        return false;
        
    printf("s: \"%s\"\n",s);
    printf("dec: %i\n",dec);
    printf("fst: \"%s\"\n",fst);
    printf("snd: \"%s\"\n",snd);
    
    bool res = (isDecimal(fst) && isInteger(snd));
    // free(fst);
    // free(snd);
    return res;
}

bool stripSpaces(char* s) {
    int len = strlen(s);
    int end_of_string = -1;
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') {
            if (end_of_string < 0)
                end_of_string = i;
        }
        else if (end_of_string >= 0) {
            return false;
        }
    }
    
    s[end_of_string] = '\0';
    printf("final string: \"%s\"\n",s);
    return true;
}

bool isNumber(char* s) {
    
    while (*s == ' ')
        s++;
        
    if (!stripSpaces(s))
        return false;
        
    if (strlen(s) < 1)
        return false;

    if (*s == '-' || *s == '+')
        s++;
    
    // is integer?
    if (isInteger(s))
        return true;
        
    // is decimal?
    if (isDecimal(s))
        return true;
        
    if (isExp(s))
        return true;
        
    return false;
}
