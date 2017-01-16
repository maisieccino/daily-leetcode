/**
* Remove Duplicates from Sorted Array II (#80)
* Runtime: 6 ms
*
* Sorted array, so we can guarantee that elements
* of same value are adjacent. We can assume that
* if nth element = x, and (n-2)th element = x,
* then (n-1)th element will also be x.
* 
* It may seem weird to see this algorithm malloc
* and copy the nums array, but other languages
* will actually do this! they use syntactic sugar
* (e.g. `for n : nums` in C++) to do the same thing
* but abstracted away.
*
* Complexity is O(n) cuz you need to check each
* element anyway.
*/
int removeDuplicates(int* nums, int numsSize) {
    int count = 0;
    
    int* numscpy = (int*)calloc(numsSize,sizeof(int));
    memcpy(numscpy,nums, numsSize*sizeof(int));
    
    for (int j = 0; j < numsSize; j++) {
        if (j < 2 || numscpy[j-2] != numscpy[j])
            nums[count++] = numscpy[j];
        
        // printf("[%i",nums[0]);
        // for (int k = 1; k < numsSize; k++)
        //     printf(",%i",nums[k]);
        // printf("]\n");
    }
    
    return count;
}
