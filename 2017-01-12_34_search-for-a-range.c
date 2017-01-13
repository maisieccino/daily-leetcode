/**
 * SEARCH FOR A RANGE (#34)
 * Runtime: 6 ms
 *
 * The brief says that the given array which you're searching
 * a range for is ORDERED. this means that you can get away
 * with performing a binary search on the array to achieve
 * that sweet, sweet O(log n) runtime. Buenisimo!
 *
 * Once you locate one of the target values, searching
 * forwards and backwards until you reach the end of the
 * range. then return them. it was quite a straightforwards
 * solution with a minimal amount of debugging!
 */
int binarySearch(int* nums, int numsSize, int target) {
    int low = 0;
    int high = numsSize-1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (nums[mid] > target)
            high = mid - 1;
        else if (nums[mid] < target)
            low = mid + 1;
        else return mid;
    }
    return -1;
} 
 
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int low = binarySearch(nums, numsSize, target);
    int high = low;
    int* range = calloc(2,sizeof(int));
    *returnSize = 2;
    
    if (low == -1) {
        range[0] = -1;
        range[1] = -1;
        return range;
    }
    
    while (low > 0 && nums[low] == target)
        low--;
    if (nums[low] != target)
        low++;
    
    while (high < numsSize && nums[high] == target)
        high++;
    if (nums[high] != target)
        high--;
    
    range[0] = low;
    range[1] = high;
    return range;
}
