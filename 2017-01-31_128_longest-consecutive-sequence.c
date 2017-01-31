/**
* LONGEST CONSECUTIVE SEQUENCE (#128)
* Runtime: 3 ms (faster that 72%)
*
* Sort the array, then count consecutive
* sequences, storing the highest value.
* Simple.
*
* Sort is O(log n), search is O(n)
**/
void swap(int* nums, int a, int b) {
    int tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
}

void sort(int* nums, int numsSize) {
    if (numsSize < 2)
        return;
    int pivot = nums[numsSize / 2];
    int i;
    int j;
    
    for (i = 0, j = numsSize - 1;; i++, j--) {
        while (nums[i] < pivot)
            i++;
        while (nums[j] > pivot)
            j--;
        if (i >= j)
            break;
        swap(nums, i, j);
    }  
    sort(nums, i);
    sort(nums + i, numsSize - i);
}

int longestConsecutive(int* nums, int numsSize) {
    if (numsSize == 0)
        return 0;
    if (numsSize == 1)
        return 1;
        
    // quicksort.
    sort(nums,numsSize);
    int maxlen = 1;
    int currlen = 1;
    int i = 0;
    while (i < numsSize - 1) {
        if ((currlen == 1) && (i >= numsSize - maxlen))
            break;
        if (nums[i] + 1 == nums[i+1])
            currlen++;
        else if (nums[i] == nums[i+1]) {}
        else {
            if (currlen > maxlen)
                maxlen = currlen;
            currlen = 1;
        }
        i++;
    }
    
    if (currlen > maxlen)
        maxlen = currlen;
    
    return maxlen;
}
