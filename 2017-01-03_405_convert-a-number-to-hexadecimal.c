/**
* CONVERT A NUMBER TO HEXADECIMAL (#405)
* Runtime: 0ms
* 
* Very simply, this algorithm converts the
* number to its two's complement if less than
* 0, then the number is converted to a 32-bit 
* binary string.
* 
* Finally, I use a dictionary to translate each
* 4-bit segment into its corresponding hex char.
* 
* Complexity? O(n) because of a lack of nested loops.
**/
char* toBin(int num) {
    if (num < 0) {
        num &= 0xffffffff;
    }
    char* s = (char*)malloc(sizeof(char) * 33);
    for (int i = 0; i < 32; i++) {
        int shift = 31 - i;
        if ((num >> shift) & 1) {
            s[i] = '1';
        }
        else {
            s[i] = '0';
        }
    }
    s[32] = '\0';
    
    return s;
}

char getHex(char* s) {
    char* bin = (char*)malloc(sizeof(char) * 5);
    bin[0] = s[0];
    bin[1] = s[1];
    bin[2] = s[2];
    bin[3] = s[3];
    bin[4] = '\0';
    if (!strcmp(bin,"0000")) {
        return '0';
    }
    if (!strcmp(bin,"0001")) {
        return '1';
    }
    if (!strcmp(bin,"0010")) {
        return '2';
    }
    if (!strcmp(bin,"0011")) {
        return '3';
    }
    if (!strcmp(bin,"0100")) {
        return '4';
    }
    if (!strcmp(bin,"0101")) {
        return '5';
    }
    if (!strcmp(bin,"0110")) {
        return '6';
    }
    if (!strcmp(bin,"0111")) {
        return '7';
    }
    if (!strcmp(bin,"1000")) {
        return '8';
    }
    if (!strcmp(bin,"1001")) {
        return '9';
    }
    if (!strcmp(bin,"1010")) {
        return 'a';
    }
    if (!strcmp(bin,"1011")) {
        return 'b';
    }
    if (!strcmp(bin,"1100")) {
        return 'c';
    }
    if (!strcmp(bin,"1101")) {
        return 'd';
    }
    if (!strcmp(bin,"1110")) {
        return 'e';
    }
    if (!strcmp(bin,"1111")) {
        return 'f';
    }
    return '0';
}

char* toHex(int num) {
    char* bin = toBin(num);
    char* output = (char*)malloc(sizeof(char) * 9);
    int ptr = -1;
    output[0] = '\0';
    for (int i = 0; i < 8; i++) {
        char c = getHex((bin + (i * 4)));
        // printf("output not empty? ");
        // printf("%s\n", (strcmp(output,"") || (c != '0'))? "true" : "false");
        // printf("char: %c\n", c);
        if (strcmp(output,"") || (c != '0')) {
            printf("hell\n");
            output[++ptr] = c;
        }
    }
    if (!strcmp(output, "")) {
        output[++ptr] = '0';
    }
    output[ptr+1] = '\0';
    return output;
}
