/**
* REVERSE VOWELS (#345)
* Runtime: 72 ms
*
* My algorithm uses an array to store indices
* of each vowel, then swaps these afterwards.
* Time complexity is O(n), which apparently is
* rather slow compared to some solutions!
*
* However, I realise after submitting that this
* could be waaaaay faster if I traverse front and
* back at the same time. Think of how one would 
* perform palindrome checking, comparing the front and
* end of the array in turn.
* except you would stop when you reach a vowel and wait
* for the other traversal to do likewise.
*
* In fact, let's try that. first, here's v1. */

// returns true if char is a vowel, false if not.
bool isVowel(char c) {
    // convert to uppercase.
    if (c > 90)
        c -= 32;
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

// swaps value of two char pointers. returns null.
void swap(char* a, char* b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

char* reverseVowels(char* s) {
    int size = strlen(s);
    int* vowels = (int*)calloc(size-1, sizeof(int));
    int vowelssize = 0;
    for (int i = 0; i < size; i++) {
        if (isVowel(s[i])) {
            vowels[vowelssize++] = i;
            printf("Add %c to vowels\n",s[i]);
        }
    }
    
    //now swap.
    for (int i = 0; i < (vowelssize/2); i++) {
        swap((s + vowels[i]), (s + vowels[vowelssize-i-1]));
    }
    
    return s;
}


/*************
* VERSION TWO
* Runtime: 6ms
*
* This one is waaaay faster.
* 
*/

bool isVowel(char c) {
  // same as before
}

void swap(char* a, char* b) {
  //same as before
}

char* reverseVowels(char* s) {
    int size = strlen(s);

    int frontptr = 0;
    int endptr = size-1;
    
    while (frontptr < endptr) {
        while (!isVowel(s[frontptr]) && frontptr < endptr)
            frontptr++;
        
        while (!isVowel(s[endptr]) && frontptr < endptr)
            endptr--;
        
        if (frontptr < size && endptr >= 0) {
            // printf("swapping %c with %c\n", s[frontptr], s[endptr]);
            swap((s + (frontptr++)), (s + (endptr--)));
        }
    }
    
    return s;
}
