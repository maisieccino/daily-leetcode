/**
* FACTORIAL TRAILING ZEROES (#172)
*
* This one wasn't all that hard tbh
* Since for all x >= 5, 5! % 10 = 0
* Meaning that we can just keep dividing
* by five until n/5 = 0 (in C, int / int
* is an int. 4/5 = 0.
*/
int trailingZeroes(int n) {
    if (n==0) {
        return 0;
    }
    else {
        return n / 5 + trailingZeroes(n / 5);
    }
}
